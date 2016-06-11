#include <iostream>
#include "BiTree.h"

using namespace std;

inline int max(int a, int b)
{
	return a > b ? a : b;
}

/*
				x
			y		T1
		z		T2
	T3		T4
*/
Node* rotate_right(Node* x)
{
	int height;

	Node* y = x->getLeft();
	Node* T2 = y->getRight();

	x->setLeft(T2);

	height = max(x->getRight() == NULL ? 0 : x->getRight()->getHeight(), x->getLeft() == NULL ? 0 : x->getLeft()->getHeight()) + 1;
	x->setHeight(height);

	y->setRight(x);

	height = max(y->getRight() == NULL ? 0 : y->getRight()->getHeight(), y->getLeft() == NULL ? 0 : y->getLeft()->getHeight()) + 1;
	y->setHeight(height);

	return y;
}

/*
				x
			T1		y
				T2		z
					T3		T4

*/
Node* rotate_left(Node* x)
{
	int height;

	Node* y = x->getRight();
	Node* T2 = y->getLeft();

	x->setRight(T2);
	
	height = max(x->getRight() == NULL ? 0 : x->getRight()->getHeight(), x->getLeft() == NULL ? 0 : x->getLeft()->getHeight()) + 1;
	x->setHeight(height);

	y->setLeft(x);

	height = max(y->getRight() == NULL ? 0 : y->getRight()->getHeight(), y->getLeft() == NULL ? 0 : y->getLeft()->getHeight()) + 1;
	y->setHeight(height);

	return y;
}

Node* insert(Node* root, Node* x)
{
	if (x == NULL) {
		cout << "Insert Node = NULL!" << endl;
		return NULL;
	}

	if (root == NULL) {
		root = x;
		x->setHeight(1);
	}
	else {
		if (x->getValue() < root->getValue()){
			if (NULL == root->getLeft())
				root->setLeft(x);
			else
				root->setLeft(insert(root->getLeft(), x));
		}
		else {
			if (NULL == root->getRight())
				root->setRight(x);
			else
				root->setRight(insert(root->getRight(), x));
		}
	}

	// update height
	int hl = (root->getLeft() == NULL) ? 0 : root->getLeft()->getHeight();
	int hr = (root->getRight() == NULL) ? 0 : root->getRight()->getHeight();
	root->setHeight(max(hl, hr)+1);

	// check balance
	int balance = hl - hr;

	// LL
	if (balance > 1 && x->getValue() <= root->getLeft()->getValue())
		return rotate_right(root);

	// LR
	if (balance > 1 && x->getValue() > root->getLeft()->getValue()) {
		root->setLeft(rotate_left(root->getLeft()));
		return rotate_right(root);
	}

	// RR
	if (balance < -1 && x->getValue() >= root->getRight()->getValue())
		return rotate_left(root);

	// RL
	if (balance < -1 && x->getValue() < root->getRight()->getValue()) {
		root->setRight(rotate_right(root->getRight()));
		return rotate_left(root);
	}

	return root;
}

// PreOrder_Traversal
// Self, Left, Right
void PreOrder_Traversal(Node* root)
{
	if (root == NULL) return;

	cout << root->getValue() << endl;

	PreOrder_Traversal(root->getLeft());

	PreOrder_Traversal(root->getRight());
}
/*
void preorderTraversal( Node root ){
	NodeStack stack = new NodeStack();
	stack.push( root );
	while( stack.size() > 0 ){
		Node curr = stack.pop();
		curr.printValue();
		Node n = curr.getRight();
		if( n != null ) stack.push( n );
		n = curr.getLeft();
		if( n != null ) stack.push( n );
	}
}*/

// InOrder_Traversal
// Left, Self, Right
void InOrder_Traversal(Node* root)
{

}

// PostOrder_Traversal
// Left, Right, Self
void PostOrder_Traversal(Node* root)
{

}

#define SIZE 20

int main()
{
	unsigned int ary[SIZE];

	for (int i = 0; i < SIZE; i++) {
		ary[i] = i;
	}

	Node* root = NULL;

	for (int i = 0; i < SIZE; i++) {
		Node* t = new Node(ary[i]);

		root = insert(root, t);
	}

	PreOrder_Traversal(root);

	return 0;
}