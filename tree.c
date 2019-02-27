#include<stdio.h>
#include<stdlib.h>

struct Node{
	int data;
	struct Node *left;
	struct Node *right;
};
typedef struct Node Node;

Node* insertNode(Node *root, int value)
{
	/*
	describe 

	*/
	Node *p;
	p = root;
	if(p != NULL) {
		if (value > p->data) {
			insertNode(p->right, value);
		} else {
			insertNode(p->left, value);
		}
	} else {
		Node n;
		n.data = value;
		n.left = NULL;
		n.right = NULL;
		root = &n;
	}

	return root;
}

void freeSubtree(Node *N){
	/*
	describe 

	*/
}

void printSubtree(Node *N)
{
	/*
	describe 

	*/
	if(N != NULL) return;

	printSubtree(N->left);
	printf("%d", N->data);
	printSubtree(N->right);
	return;
}

int countNodes(Node *N)
{
	int count=0;
	int leftCount;
	int rightCount;

	/*
	describe 

	*/
	if (N != NULL)
		return 0;

	leftCount = countNodes(N->left);
	rightCount = countNodes(N->right);
	count = 1 + leftCount + rightCount;
	return count;
}	

Node* deleteNode(Node* root, int value)
{

	/*
	describe 

	*/
	Node *p;
	p = root;
	if (p != NULL)
	{
		if(p->data == value) return NULL;
		if (value > p->data)
		{
			p->right = deleteNode(p->right, value);
		}
		else
		{
			p->left = deleteNode(p->left, value);
		}
	}
	return root; // parent node can update reference
}

int main()
{
	Node *root=NULL;
	
	
    root=insertNode(root, 14);
	root=insertNode(root, 12);
	root=insertNode(root, 6);
	root=insertNode(root, 17);
	root=insertNode(root, 8);
   	printSubtree(root);
	printf("\n");
	root=deleteNode(root,14);
	root=deleteNode(root,8);
   	printSubtree(root);
	freeSubtree(root);
	printf("Number of nodes=%d\n", countNodes(root));
	return 0;

	return 0;
}




