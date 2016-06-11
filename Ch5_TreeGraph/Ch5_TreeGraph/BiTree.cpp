#include "BiTree.h"

bool Node::setLeft(Node* l)
{

	left = l;
	return true;
	
}

bool Node::setRight(Node* r)
{
	right = r;
	return true;
}

Node::Node()
{
	value = 0; 
	left = NULL; 
	right = NULL;
	height = 0;	// no value, no height
}

Node::Node(int v):value(v) 
{
	left = NULL;
	right = NULL;
	height = 1;
}