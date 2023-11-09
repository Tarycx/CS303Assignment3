#pragma once

#include <iostream>
#include "Stack.h"
#include <string>
using namespace std;


class ExpressionManager {
private:
    Stack operatorStack; //create stack
    string postfix; 

    int getPrecedence(char op);
    bool isOpeningParenthesis(char c);
    bool isClosingParenthesis(char c);
    bool isPair(char open, char close);

public:
    ExpressionManager();
    string infixToPostfix(const string& infix);
    bool isBalanced(const string& expression);
};
