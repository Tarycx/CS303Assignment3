#pragma once
#include <iostream>
#include <string> 
using namespace std;

struct NodeQ {
	string dataInfix;
	string dataPostfix;
	NodeQ* nextPtr = nullptr;


};

class Queue {
private:
	NodeQ* frontPtr;
	NodeQ* rearPtr;
public:
	Queue();
	void enqueue(string inVal, string postVal);
	void dequeue();
	void peek();
	bool empty();
	void printQueue();

};