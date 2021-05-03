#include <iostream>
#include<climits>
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

struct  Info{

	int size;
	int max;
	int min;
	int ans;
	bool isBST;
};

Info LargestBSTinBT(Node *root){
	if(root==NULL){
		return {0,INT_MIN,INT_MAX,0,true};
	}

	if(root->left ==NULL && root->right==NULL){
		return {1,root->data,root->data,1,true};
	}

	Info LeftInfo=LargestBSTinBT(root->left);
	Info rightInfo=LargestBSTinBT(root->right);
	Info curr;
	curr.size=(1+LeftInfo.size+rightInfo.size);

	if(LeftInfo.isBST && rightInfo.isBST && LeftInfo.max <root->data && rightInfo.min>root->data){

		curr.min =min(LeftInfo.min,min(rightInfo.min,root->data));
		curr.max=max(rightInfo.max,max(LeftInfo.max,root->data));
		curr.ans=curr.size;
		curr.isBST=true;
		return curr;
	}
	curr.ans=max(LeftInfo.ans,rightInfo.ans);
	curr.isBST=false;
	return curr;
}

int main(){

	Node *root=new Node(15);
	root->left=new Node(20);
	root->right=new Node(30);
	root->left->left=new Node(5);
	cout<<"Largest bst in BT : "<< LargestBSTinBT(root).ans<<endl;
	return 0;
}