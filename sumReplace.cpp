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


void sumReplace(Node* root){
	if(root==NULL){
		return;
	}

	sumReplace(root->left);
	sumReplace(root->right);


	if(root->left!=NULL){
		root->data+=root->left->data;
	}

	if(root->right!=NULL){
		root->data+=root->right->data;
		
	}
}


void Preorder(Node *root){

	if(root==NULL){
		return;
	}

	cout<<root->data<<" ";
	Preorder(root->left);
	Preorder(root->right);

}



int main(){

	Node *root=new Node(1);
	root->left=new Node(2);
	root->right=new Node(3);
	root->left->left=new Node(4);
	root->left->right=new Node(5);
	root->right->left=new Node(6);
	root->right->right=new Node(7);

	Preorder(root);


	cout<<endl;

	sumReplace(root);
	Preorder(root);

	cout<<endl;

	return 0;
}