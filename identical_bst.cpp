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

bool isIdentical(Node *root1,Node *root2){

	if(root1==NULL && root2==NULL){
	     return true;
	}
	else if(root1==NULL || root2==NULL){
		 return false;
	}
	else{
		bool cond1=root1->data==root2->data;
		bool cond2=isIdentical(root1->left,root2->left);
		bool cond3=isIdentical(root1->right,root2->right);
		if(cond1 && cond2 && cond3){
			return true;
		}
		return false;
	}
}

int main(){

	Node *root=new Node(2);
	root->left=new Node(1);
	root->left=new Node(3);

	Node *root1=new Node(2);
	root1->left=new Node(1);
	root1->left=new Node(4);

	if(isIdentical(root,root1))
	{
		cout<<"It is Identical"<<endl;
	}else{
		cout<<"It is not  Identical"<<endl;
	}
	return 0;
}