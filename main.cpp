#include <iostream>
#include <string>
#include "Stack.h"
#include "Queue.h"
#include "expressionManager.h"
using namespace std;


int main() {
	
	Queue myQueue; //creates Queue structure for equations data

	//Project Introduction
	cout << "CS303 Data Structures" << endl;
	cout << "Assigment 3: InfixToPostfix/Stack/Queue" << endl;
	cout << "Instructor: Syed Jawad Hussain Shah" << endl;
	cout << "Name: Thomas Reilly" << endl;
	cout << "Due: Thursday, Nov 9, 11:59pm" << endl << endl;

	while (true) {
		ExpressionManager myEquation;
	
		string userInput; //users Infix
		string postfix; //Users postfix
		char userChoice; //User input for menu selection

		//Menu Selections display
		cout << endl;
		cout << "1 - Convert Infix to Postfix equation(Expression Manager using stack, Appends data to Queue)" << endl;
		cout << "2 - Print current list of conversions(Prints Queue)" << endl;
		cout << "3 - Delete from Queue(Peek, Dequeue)" << endl;
		cout << "q - Quit/Exit" << endl;

		cout << "Enter you selection: ";
		cin >> userChoice;
		cout << endl;

		//Meny selections and funcitons
		switch (tolower(userChoice)) {

		case '1': //Converts infix to postfix and enqueues data to queue.
			cout << "Enter Infix equation:" << endl;
			cin >> userInput;
			if (!myEquation.isBalanced(userInput)) {
				cout << "Equation is not balanced: " << userInput << endl << endl;
			}
			else {
				postfix = myEquation.infixToPostfix(userInput);
				cout << "Postfix equaitons : " << postfix << endl;
				myQueue.enqueue(userInput, postfix);
				cout << "Data updated in Queue(Enqueue)" << endl;

			}
			break;

		case '2': //Prints all queue elements 
			if (myQueue.empty()) {
				cout << "Queue is empty" << endl;
				break;
			}
			myQueue.printQueue();
			cout << endl;
			break;

		case '3': // deletes from front of the queue
			if (myQueue.empty()) {
				cout << "Queue is empty" << endl << endl;
				break;
			}
			cout << "(Data Deleted) ";
			myQueue.peek();
			myQueue.dequeue();
			cout << endl;
			break;

		case '4':

			break;

		case 'q': //excited program
			cout << "GoodBye! Exiting Program" << endl;
			break;

		default: //loops back for invaild input
			cout << "Invalid Input. Try Again." << endl;
			break;
		}


		if (tolower(userChoice) == 'q') { //Program END, Exiting statement
			break; 
		}
	
	}
		
	
	return 0;
}