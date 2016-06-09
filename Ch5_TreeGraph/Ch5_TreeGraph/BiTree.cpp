#include "BiTree.h"

bool Node::setLeft(Node* l)
{
	if (l) {
		left = l;
		return true;
	}
	else {
		return false;
	}
}

bool Node::setRight(Node* r)
{
	if (r) {
		right = r;
		return true;
	}
	else {
		return false;
	}
}

Node::Node()
{
	value = 0; 
	left = NULL; 
	right = NULL;
}
