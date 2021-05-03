#include <iostream>

using namespace  std;

class Node{

public:
	int data;
	Node *right,*left;


	Node(int val){
		data=val;
		left=right=NULL;
	}
};

int nodeCount(Node  * root){

	if(root==NULL){
		return 0;
	}
	return nodeCount(root->left)+nodeCount(root->right)+1;
}


int nodesum(Node  * root){

	if(root==NULL){
		return 0;
	}
	return nodesum(root->left)+nodesum(root->right)+root->data;
}

int calcheight(Node *root){
	
	if(root==NULL){
		return 0;
	}

	int Lheight=calcheight(root->left);
	int Hheight=calcheight(root->right);

	return max(Lheight,Hheight)+1;
}


int caldiameter(Node *root){
	if(root==NULL){
		return 0;
	}

	int Lheight=calcheight(root->left);
	int Rright=calcheight(root->right);

	int curr=Lheight+Rright+1;

	int lDiameter=caldiameter(root->left);
	int RDiameter=caldiameter(root->right);

	return max(curr,max(lDiameter,RDiameter))+1;

}

int Calcdiameter(Node *root,int *height){
	if(root==NULL){
		*height=0;
		return 0;
	}

	int lh=0;
	int rh=0;

	int lDiameter=Calcdiameter(root->left,&lh);
	int RDiameter=Calcdiameter(root->right,&rh);

	int curr=lh+rh+1;

	*height=max(lh,rh)+1;


	return max(curr,max(lDiameter,RDiameter));



}


int main(){

	Node *root=new Node(1);
	root->left=new Node(2);
	root->right=new Node(3);
	root->left->left=new Node(4);
	root->right->right=new Node(5);
	root->left->right=new Node(6);
	root->right->left=new Node(7);


	// cout<<nodeCount(root)<<endl;

	// cout<<nodesum(root)<<endl;

	// cout<<calcheight(root)<<endl;

	// cout<<caldiameter(root)<<endl;

	int height =0;
	cout<<Calcdiameter(root,&height)<<endl;

	return 0;
}