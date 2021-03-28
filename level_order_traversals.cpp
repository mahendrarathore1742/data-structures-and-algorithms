#include <iostream>
#include <queue>
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
	void print_level_order(Node *root){
		if(root==NULL)
		{
			return;
		}
		
		queue<Node*> q;
		q.push(root);
		q.push(NULL);

		while(!q.empty()){
			Node *node=q.front();
			q.pop();

			if(node!=NULL){
				cout<<node->data<<" ";
				if(node->left)
					q.push(node->left);
				if(node->right)
					q.push(node->right);
			}
			else if(!q.empty()) {
				q.push(NULL);
			}
		}
	}

	int sumNode(Node *root,int k){
		if(root==NULL){
			return -1;
		}

		queue <Node*> q;
		q.push(root);
		q.push(NULL);

		int level=0;
		int sum=0;

		while(!q.empty()){
			Node *node=q.front();
			q.pop();

			if(node!=NULL){
				if(level==k){
					sum+=node->data;
				}
					if(node->left)
						q.push(node->left);

					if(node->right)
						q.push(node->right);

				}else if(!q.empty()){
					q.push(NULL);
					level++;
				}
			}
		return sum;
	}
	
	void print(Node* root){
		print(root->left);
		cout<<root->data<<" ";
		print(root->right);
	}

int main(){


	Node *root=new Node(1);
	root->left=new Node(2);
	root->right=new Node(3);

	root->left->left=new Node(4);
	root->left->right=new Node(5);
	
	root->right->left=new Node(6);
	root->right->right=new Node(7);

	print_level_order(root);
	
	cout<<endl;

	cout<<sumNode(root,2)<<endl;

	return  0;
}