#include <iostream>
#include <stack>
#include <string>
#include <cctype>  // For isdigit function

using namespace std;

// Function to return the precedence of operators
int precedence(char op) {
    switch(op) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
        case '%':
            return 2;
        default:
            return 0;
    }
}

// Function to convert infix expression to postfix
string infixToPostfix(const string& infix) {
    stack<char> s;
    string postfix;

    for (char ch : infix) {
        if (isdigit(ch) || isalpha(ch)) {
            // If character is an operand, add it to the output
            postfix += ch;
        } else if (ch == '(') {
            // If character is '(', push it to the stack
            s.push(ch);
        } else if (ch == ')') {
            // If character is ')', pop and output from the stack
            // until an '(' is encountered
            while (!s.empty() && s.top() != '(') {
                postfix += s.top();
                s.pop();
            }
            s.pop();  // Pop the '('
        } else {
            // An operator is encountered
            while (!s.empty() && precedence(s.top()) >= precedence(ch)) {
                postfix += s.top();
                s.pop();
            }
            s.push(ch);
        }
    }

    // Pop all the operators from the stack
    while (!s.empty()) {
        postfix += s.top();
        s.pop();
    }

    return postfix;
}

int main() {
    string infix;
    cout << "Enter infix expression: ";
    cin >> infix;

    string postfix = infixToPostfix(infix);
    cout << "Postfix expression: " << postfix << endl;

    return 0;
}
