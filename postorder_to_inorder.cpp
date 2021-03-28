#include <iostream>
using namespace  std;


class Node{
public:
	int data;
	Node *left,*right;

	Node(int val){
		data=val;
		left=right=NULL;
	}
};

int search(int inorder[],int start,int end,int curr){
	for (int i = start; i <=end; ++i)
	{
		if(inorder[i]==curr){
			return i;
		}
	}
	return -1;
}

Node *buildtree(int postorder[],int inorder[],int start,int end){
	static int idx=4;
	if(start>end){
		return NULL;
	}

	int curr=postorder[idx];
	idx--;
	Node *node=new Node(curr);

	if(start==end){
		return node;
	}
	
	int pos=search(inorder,start,end,curr);
	node->right=buildtree(postorder,inorder,pos+1,end);
	node->left=buildtree(postorder,inorder,start,pos-1);
	return node;
}


void print(Node *root){
	if(root==NULL){
		return;
	}

	print(root->left);
	cout<<root->data<<" ";
	print(root->right);

}

int main(){

	
	int postorder[]={4,2,5,3,1};
	int inorder[]={4,2,1,5,3};

	Node *node = buildtree(postorder,inorder,0,4);
	print(node);
	cout<<endl;



	return 0;
}