#pragma once

#include <iostream>

class Node {
public:
	Node(int v, Node* l, Node* r, int h) :left(l), right(r), value(v), height(h) {}
	Node(int v);
	Node();
	~Node() {}

	bool setLeft(Node* l);
	bool setRight(Node* r);
	bool setValue(int v) { value = v; return true; }
	bool setHeight(int h) { height = h; return true; }

	Node* getLeft() { return left; }
	Node* getRight() { return right; }
	int getValue() { return value; }
	int getHeight() { return height; }

private:
	Node* left;
	Node* right;
	int	  value;
	int   height;
};