#pragma once

template<typename Type>
class LinkedListNode {
public:
	
	LinkedListNode(const Type d) :data(d), next(NULL) {}
	~LinkedListNode() {};
	LinkedListNode* getNext() const { return next; }
	const Type& value() const { return data; }
	void* setNext(LinkedListNode* l) { next = l; }
	void setValue(const Type& d) { data = d; }

private:
	LinkedListNode* next;
	Type		data;
};

template<typename Type>
class LinkedList {
public:
	LinkedList(LinkedListNode* h) :head(h), size(1) {}
	~LinkedList() {}

	bool insert(int pos, LinkedListNode<Type>* n);
	/*
	bool push_back(LinkedListNode* n);
	bool push_front(LinkedListNode* n);
	LinkedListNode* pop_back();
	LinkedListNode* pop_front();
	*/

private:
	LinkedListNode* head;
	int size;
};



