// Recursive C++ program to print odd level nodes
#include <bits/stdc++.h>
using namespace std;

struct Node {
	int data;
	Node* left, *right;
};

void weWillRockYou(Node *root, bool Odd = true)
{
if (root == NULL)
return;
if (Odd){
	cout << root->data << " " ;
}

weWillRockYou(root->left, !Odd);
}

// Utility method to create a node
struct Node* newNode(int data)
{
	struct Node* node = new Node;
	node->data = data;
	node->left = node->right = NULL;
	return (node);
}

// Driver code
int main()
{
	struct Node* root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	root->left->left = newNode(4);
	root->left->right = newNode(5);
	weWillRockYou(root);

	return 0;
}
