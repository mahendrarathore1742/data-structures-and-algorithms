#include <iostream>
#include<vector>
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

vector<Node*> constract(int start,int end){
	vector<Node*> tree;
	if(start>end){
		tree.push_back(NULL);
		return tree;
	}
	for (int i = start; i <= end; i++)
	{

		vector<Node*> leftSubtree=constract(start,i-1);
		vector<Node*> rightSubtree=constract(i+1,end);
		for (int j = 0; j <leftSubtree.size(); j++)
		{
			Node *left=leftSubtree[j];
			for (int k = 0; k <rightSubtree.size(); k++)
		{

			Node *right=rightSubtree[k];
			Node *node=new Node(i);
			node->left=left;
			node->right=right;
			tree.push_back(node);
		}	
		}		
	}
	return tree;
}

void preOrder(Node *root){
	if(root==NULL){
		return;
	}
	cout<<root->data<<" ";
	preOrder(root->left);
	preOrder(root->right);
}


int main(){
	vector<Node*> totalTree=constract(1,3);
	for (int i = 0; i < totalTree.size(); i++)
	{
		cout<<(i+1)<<": ";
		preOrder(totalTree[i]);
		cout<<endl;
	}
	return 0;
}
