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
	for (int i = start; i <= end; ++i)
	{
		if(inorder[i]==curr){
			return i;
		}
	}
		return -1;
}
 
Node * buildTree(int preorder[],int inorder[],int start,int end){
	static int idx=0;

	if(start>end){
		return NULL;
	}

	int curr=preorder[idx];

	idx++;


	Node *node=new Node(curr);

	if(start == end){
		return node;
	}

	int pos=search(inorder,start,end,curr);
	node->left=buildTree(preorder,inorder,start,pos-1);
	node->right=buildTree(preorder,inorder,pos+1,end);

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



	int preorder[]={1,2,4,3,5};
	int inorder[]={4,2,1,5,3};

	Node *node = buildTree(preorder,inorder,0,4);

	print(node);
	cout<<endl;






	return 0;
}