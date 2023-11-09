#include "expressionManager.h"

using namespace std;

ExpressionManager::ExpressionManager() {}

//Selection of operators, finding precendence
int ExpressionManager::getPrecedence(char op) {
    if (op == '+' || op == '-') {
        return 1;
    }
    else if (op == '*' || op == '/') {
        return 2;
    }
    return 0;
}
//check if open parenthesis
bool ExpressionManager::isOpeningParenthesis(char c) {
    return c == '(' || c == '[' || c == '{';
}

//check if closing parentthesis
bool ExpressionManager::isClosingParenthesis(char c) {
    return c == ')' || c == ']' || c == '}';
}

//checking parentthesis are paired
bool ExpressionManager::isPair(char open, char close) {
    return (open == '(' && close == ')') || (open == '[' && close == ']') || (open == '{' && close == '}');
}

//converting infix to postfix equaiton
string ExpressionManager::infixToPostfix(const string& infix) {
    postfix = "";
    for (char c : infix) {
        if (isalnum(c)) {
            postfix += c;
        }
        else if (isOpeningParenthesis(c)) {
            operatorStack.push(c);
        }
        else if (isClosingParenthesis(c)) {
            while (!operatorStack.empty() && isOpeningParenthesis(operatorStack.getTop())) {
                if (isPair(operatorStack.getTop(), c)) {
                    operatorStack.pop();
                    break;
                }
                else {
                    postfix = "Unbalanced";
                    return postfix;
                }
            }
        }
        else {
            while (!operatorStack.empty() && getPrecedence(c) <= getPrecedence(operatorStack.getTop())) {
                if (operatorStack.getTop() != '(' && operatorStack.getTop() != '[' && operatorStack.getTop() != '{') {
                    postfix += operatorStack.getTop();
                }
                operatorStack.pop();
            }
            if (c != ')' && c != ']' && c != '}') {
                operatorStack.push(c);
            }
        }
    }

    while (!operatorStack.empty()) {
        if (operatorStack.getTop() != '(' && operatorStack.getTop() != '[' && operatorStack.getTop() != '{') { //Updated tailing values
            postfix += operatorStack.getTop();
        }
        operatorStack.pop();
    }

    return postfix;
}

//checking if stack is balanced
bool ExpressionManager::isBalanced(const string& expression) {
    Stack checkStack; //cretes stack variable
    for (char c : expression) {
        if (isOpeningParenthesis(c)) {
            checkStack.push(c);
        }
        else if (isClosingParenthesis(c)) {
            if (checkStack.empty() || !isPair(checkStack.getTop(), c)) {
                return false;
            }
            checkStack.pop();
        }
    }
    return checkStack.empty();
}