#pragma once
#include <iostream>
#include <string>
using namespace std;


struct Node {
	char data;
	Node* next;
};


class Stack {
private:
	Node* top;


public:
	Stack();
	bool empty();
	void push(char data);
	void pop();
	char getTop();


};