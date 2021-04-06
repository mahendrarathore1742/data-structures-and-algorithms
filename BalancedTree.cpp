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

int height(Node *root){
	if(root==NULL){
		return 0;
	}

	int lh=height(root->left);
	int rh=height(root->right);
	return max(lh,rh)+1;
}

bool isBalanvedTree(Node *root){
	if(root==NULL){
		return true;
	}

	if(isBalanvedTree(root->left)==false){
		return false;
	}

	if (isBalanvedTree(root->right)==false)
	{
		return false;
	}

	int lh=height(root->left);
	int rh=height(root->right);

	if(abs(lh-rh)<=1){
		return true;
	}else{
		return false;
	}
}


bool isBalanvedTree2(Node *root,int *height){

	if(root==NULL){
		
		return true;
	}

	int lh=0,rh=0;
	if(isBalanvedTree2(root->left,&lh)==false);
	{
		return false;
	}

	if(isBalanvedTree2(root->right,&rh)==false){
		return false;
	}

	*height=max(lh,rh)+1;
	if(abs(lh-rh)<=1){
		return true;
	}else{
		return false;
	}
}



int main(){	

	Node *root=new Node(1);
	root->left=new Node(2);
	root->right=new Node(3);
	root->left->left=new Node(4);
	root->left->right=new Node(5);
	root->right->left=new Node(6);
	root->right->right=new Node(7);

	int height=0;
	if(isBalanvedTree2(root,&height)==true){
		cout<<"it's balanced tree"<<endl;
	}else{
		cout<<"it's not balanced "<<endl;
	}


	return 0;
}