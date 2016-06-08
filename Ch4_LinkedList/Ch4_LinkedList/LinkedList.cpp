#include "LinkedList.h"

template<typename Type>
bool LinkedList<Type>::insert(int pos, LinkedListNode<Type>* n)
{
	if (pos > size)
	{
		return false;
	}

	LinkedListNode* p = head;
	for (int index = 0; index < pos; index++)
	{
		p = head->getNext();
	}

	n->setNext(p->getNext());
	p->setNext(n);

	return true;
}


