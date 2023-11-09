#include <iostream>
#include "Queue.h"


Queue::Queue() {
	frontPtr = nullptr;
	rearPtr = nullptr;

}

//Appends element to the rear
void Queue::enqueue(string inVal, string postVal) {
	NodeQ* newNode = new NodeQ;
	newNode->dataInfix = inVal;
	newNode->dataPostfix = postVal;
	if (rearPtr == nullptr) {
		frontPtr = rearPtr = newNode;
		return;
	}
	rearPtr->nextPtr = newNode;
	rearPtr = newNode;
}

//Removes front element
void Queue::dequeue() {
	if (frontPtr == nullptr) {
		cout << "Queue is empty(dequeue)" << endl;
		return;
	}
	NodeQ* tempPtr = frontPtr;
	frontPtr = frontPtr->nextPtr;
	if (frontPtr == nullptr) {
		rearPtr = nullptr;
	}
	delete tempPtr;

}


//Returns top node of queue
void Queue::peek() {
	if (frontPtr == nullptr) {
		cout << "Queue is empty(peek)" << endl;
	}
	else {
	cout << "Infix Equation: " << frontPtr->dataInfix << "  ";
	cout << "Postfix Equation: " << frontPtr->dataPostfix << endl;
	}
	

	
}

bool Queue::empty() {
	return frontPtr == nullptr;
}

void Queue::printQueue() {
	int indexPos = 0;
	NodeQ* current = frontPtr;
	while (current != nullptr) {
		cout << "Index: " << indexPos << "  ";
		cout << "Infix Equation: " << current->dataInfix << "  ";
		cout << "Postfix Equation: " << current->dataPostfix << endl;
		current = current->nextPtr;
		indexPos++;
	}
}