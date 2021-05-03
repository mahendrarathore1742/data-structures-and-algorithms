#include <iostream>
using namespace  std;

class Node{

public:
	int data;
	Node *left,*right;

	Node(int val) {
		data=val;
		left=right=NULL;
		}
};



int main(){

	 
	root->left=new Node(2);
	root->right=new Node(3);
	root->left->left=new Node(4);
	root->right->right=new Node(5);
	root->left->right=new Node(6);
	root->right->left=new Node(7);

	
	
	return 0;
}