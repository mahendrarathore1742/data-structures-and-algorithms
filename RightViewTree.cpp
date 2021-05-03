#include <iostream>
#include<queue>
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

void rightview(Node *root){

	if(root==NULL){
		return;
	}

	queue<Node*> q;
	q.push(root);

	while(!q.empty()){
		int n=q.size();
		for (int i = 0; i < n; i++)
		{
			Node *curr=q.front();
			q.pop();

			if(i==n-1){
				cout<<curr->data<<" ";
			}

			if(curr->left!=NULL){
				q.push(curr->left);
			}

			if (curr->right!=NULL)
			{
				q.push(curr->right);
			}
		}
	}
}


void lefttview(Node *root){
	if(root==NULL){
		return;
	}

	queue<Node*> q;
	q.push(root);

	while(!q.empty()){

		int n=q.size();

		for (int i = 1; i <=n; i++)
		{

			Node *curr=q.front();
			q.pop();
			if(i==1){
				cout<<curr->data<<" ";
			}
			if(curr->left!=NULL){
				q.push(curr->left);
			}
			if(curr->right!=NULL){
				q.push(curr->right);
			}
		}
	}
}


int main(){

Node *root=new Node(5);
	root->left=new Node(3);
	root->right=new Node(6);
	root->left->left=new Node(2);
	root->left->right=new Node(4);
	


	// rightview(root);

	lefttview(root);


	return 0;
}