#include <iostream>
using namespace std;


class Node{
public:
	int data;
	Node *left,*right;

	Node(int val){
		data=val;
		left=right=NULL;
	}
};

Node * create(Node *root,int data){

	if(root==NULL){
		return new Node(data);
	}

	if(data<root->data  ){
		root->left=create(root->left,data);
	}
	else{
		root->right=create(root->right,data);
	}
	return root;

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
	
	Node *root=NULL;
	root=create(root,5);
	create(root,1);
	create(root,2);
	create(root,3);
	create(root,4);
	create(root,7);
	create(root,6);
	print(root);
	cout<<endl;
	return 0;
}