#include <iostream>
#include <climits>
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

int maxsumPathUtil(Node *root,int &ans){

	if(root==NULL){
		return 0;
	}

	int left=maxsumPathUtil(root->left,ans);
	int right=maxsumPathUtil(root->right,ans);
	int nodemax=max(max(root->data,root->data+left+right),
				max(root->data+left,root->data+right));
	ans=max(ans,nodemax);
	int singlePath=max(root->data,max(root->data+left,root->data+right));
	return singlePath;
}


int maxsumPath(Node *root){
	int ans=INT_MIN;
	maxsumPathUtil(root,ans);
	return ans;
}


int main(){

	Node *root=new Node(1);
	root->left=new Node(2);
	root->right=new Node(3);
	root->left->left=new Node(4);
	root->right->right=new Node(5);
	cout<<maxsumPath(root)<<endl;

	return 0;
}