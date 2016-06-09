#pragma once

#include <iostream>

class Node {
public:
	Node(int v, Node* l, Node* r) :left(l), right(r), value(v) {}
	Node();
	~Node() {}

	bool setLeft(Node* l);
	bool setRight(Node* r);
	bool setValue(int v) { value = v; return true; }

	Node* getLeft() { return left; }
	Node* getRight() { return right; }
	int getValue() { return value; }

private:
	Node* left;
	Node* right;
	int	  value;
};