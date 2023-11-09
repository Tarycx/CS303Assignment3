#pragma once
#include <iostream>
#include "Stack.h"


Stack::Stack() {
	top = nullptr;

}

bool Stack::empty() {
	return top == nullptr;

}

void Stack::push(char data) {
	Node* newNode = new Node;
	newNode->data = data;  //Test
	newNode->next = top;
	top = newNode;

}

void Stack::pop() {
	if (empty()) {
		throw runtime_error("Stack is empty(pop())");
	}
	Node* tempNode = top;
	top = top->next;
	delete tempNode;

}

char Stack::getTop() {
	if (empty()) {
		//throw runtime_error();
		return '0';
		
	}
	return top->data;

}
