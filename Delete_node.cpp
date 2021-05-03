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

Node *inorderSucc(Node *root){
	Node* curr=root;
	while(curr && curr->left !=NULL){
		curr=curr->left;
	}
	return curr;
}

Node *DeleteNode(Node *root,int key){

	if(root==NULL){
		return NULL;
	}
	if(key<root->data){
		root->left=DeleteNode(root->left,key);
	}
	else if(root->data<key){
		root->left=DeleteNode(root->right,key);
	}
	else{
			if(root->left==NULL){
				Node *temp=root->right;
				free(root);
				return temp;
			}

			else if(root->right==NULL){
				Node *temp=root->left;
				free(root);
				return temp;
			}
			Node *temp=inorderSucc(root->right);
			root->data=temp->data;
			root->right=DeleteNode(root->right,temp->data);
	}

	return root;
}


void inorderPrint(Node *root){

	if(root==NULL){
		return;
	}

	inorderPrint(root->left);
	cout<<root->data<<" ";
	inorderPrint(root->right);
}

int main(){



	Node *root=new Node(4);
	root->left=new Node(2);
	root->right=new Node(5);
	root->left->left=new Node(1);
	root->left->right=new Node(3);
	root->right->right=new Node(6);

inorderPrint(root);
cout<<endl;
	DeleteNode(root,2);

	inorderPrint(root);

	cout<<endl;



	return 0;
}
