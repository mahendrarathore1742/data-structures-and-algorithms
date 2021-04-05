#include <iostream>
using namespace  std;

class Node{
public:
	int data;
	Node *left,*right;
	Node(int val){
		data=val;
		right=left=NULL;
	}
};


Node *SortedArrayBSt(int arr[],int start,int end){
	if(start>end){
		return NULL;
	}
	int mid=(start+end)/2;
	Node *root=new Node(arr[mid]);
	root->left=SortedArrayBSt(arr,start,mid-1);
	root->right=SortedArrayBSt(arr,mid+1,end);
	return root;
}
void print(Node*root){
	if(root==NULL){
		return;
	}
	cout<<root->data<<" ";
	print(root->left);
	print(root->right);
}

int main(){
	int arr[]={1,2,3,4,5,6,7};
	Node *root=SortedArrayBSt(arr,0,6);
	print(root);
	return 0;
}