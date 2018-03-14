/*<><><><><><><><><><><><><><><><><><><><><><><><><>*/
//Program Name: Prime Factor Finder
//Developer: Trevor Murphy
//Date: 12/10/2017
//Description: Linked Stack Type header file
//
/*<><><><><><><><><><><><><><><><><><><><><><><><><>*/
#pragma once
#include "stackADT.h"
#include <assert.h>
#include <string>

using namespace std;
template <class T>
struct nodeType
{
	T info;
	nodeType<T> *link;
};

template <class T>
class linkedStackType : public stackADT<T>
{
public:
	const linkedStackType<T>& operator=(const linkedStackType<T>&);
	bool operator==(linkedStackType<T>&);
	bool isEmptyStack() const;

	bool isFullStack() const;

	void initializeStack();

	void push(const T& newItem);

	T top() const;
	int getSz() const;
	void pop();
	void reverseStack(linkedStackType<T>&);
	linkedStackType<T> RreverseStack(linkedStackType<T>&);
	void print(string = " ") const;
	linkedStackType();
	linkedStackType(const linkedStackType<T>& otherStack);

private:
	nodeType<T>*stackTop;
	void copyStack(const linkedStackType<T>& otherStack);
	int size;
};

template <class T>
int linkedStackType<T>::getSz() const {
	return size;
}

template <class T>
void linkedStackType<T>::copyStack(const linkedStackType<T>& otherStack)
{
	nodeType<T> *newNode, *current, *prev;
	if (stackTop != NULL)
	{
		initializeStack();
	}
	if (otherStack.stackTop == NULL)
	{
		stackTop = NULL;
	}
	else
	{
		current = otherStack.stackTop;
		stackTop = new nodeType<T>;
		stackTop->info = current->info;
		stackTop->link = NULL;
		prev = stackTop;
		current = current->link;
		while (current != NULL)
		{
			newNode = new nodeType<T>;

			newNode->info = current->info;
			newNode->link = NULL;
			prev->link = newNode;
			prev = newNode;
			current = current->link;
		}
		size = otherStack.getSz();
	}
}

template <class T>
linkedStackType<T>::linkedStackType()
{
	stackTop = NULL;
}

template <class T>
bool linkedStackType<T>::isEmptyStack() const
{
	return	(stackTop == NULL);
}

template <class T>
bool linkedStackType<T>::isFullStack() const
{
	return false;
}

template <class T>
void linkedStackType<T>::initializeStack()
{
	nodeType<T>*temp;
	while (stackTop != NULL)
	{
		temp = stackTop;
		stackTop = stackTop->link;
		delete temp;
		size = 0;
	}
}

template <class T>
void linkedStackType<T>::push(const	 T& newElement)
{
	nodeType<T> *newNode;

	newNode = new nodeType<T>;

	newNode->info = newElement;
	newNode->link = stackTop;
	stackTop = newNode;
	size++;
}

template <class T>
T linkedStackType<T>::top() const
{
	assert(stackTop != NULL);

	return stackTop->info;
}

template <class T>
void linkedStackType<T>::pop()
{
	nodeType<T>*temp;
	if (stackTop != NULL)
	{
		temp = stackTop;

		stackTop = stackTop->link;

		delete temp;
		size--;
	}
	else
		cout << "Cannot remove from an empty stack." << endl;
}

template <class T>
linkedStackType<T>::linkedStackType(const linkedStackType<T>& otherStack)
{
	stackTop = NULL;
	copyStack(otherStack);
}

template <class T>
const linkedStackType<T>& linkedStackType<T>::operator=(const linkedStackType<T>& otherStack)
{
	if (this != &otherStack)
	{
		copyStack(otherStack);
	}
	return *this;
}

template <class T>
bool linkedStackType<T>::operator==(linkedStackType<T>& otherStack) {
	while (top() != NULL && otherStack.top() != NULL) {
		if (top() != otherStack.top())
			return 0;
		else {
			pop();
			otherStack.pop();
			if (top() != NULL && otherStack.top() != NULL)
				return 1;
		}
	}
	return 0;
}

template <class T>
void linkedStackType<T>::reverseStack(linkedStackType<T>& otherStack) {
	for (linkedStackType<T> cp = *this; !cp.isEmptyStack(); cp.pop())
		otherStack.push(cp.top());
	//cout << "Showing Reversed Stack" << endl;
	for (otherStack; !otherStack.isEmptyStack(); otherStack.pop())
		cout << otherStack.top() << endl;
}

template <class T>
linkedStackType<T> linkedStackType<T>::RreverseStack(linkedStackType<T>& otherStack) {
	for (linkedStackType<T> cp = *this; !cp.isEmptyStack(); cp.pop())
		otherStack.push(cp.top());
	return otherStack;
}

template <class T>
void linkedStackType<T>::print(string name) const {
	if (name != " ")
		cout << name << endl;
	for (linkedStackType<T> cp = *this; !cp.isEmptyStack(); cp.pop())
		cout << cp.top() << " ";
}
