#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;

bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

string post_to_in(string postfix);
string in_to_pre(string infix);
int precedence(char c);

string post_to_in(string postfix) {
    stack<string> s;

    int length = postfix.length();

    for (int i = 0; i < length; i++) {
        if (isOperator(postfix[i])) {
            string operand2 = s.top();
            s.pop();
            string operand1 = s.top();
            s.pop();
            string temp = operand1 + postfix[i] + operand2;
            s.push(temp);
        } else {
            s.push(string(1, postfix[i]));
        }
    }

    string infix = s.top();
    return infix;
}

string in_to_pre(string infix) {
    int length = infix.length();
    string prefix = "";
    stack<char> s;

    for (int i = length - 1; i >= 0; i--) {
        if (isalnum(infix[i])) {
            prefix += infix[i];
        } else if (infix[i] == ')') {
            s.push(infix[i]);
        } else if (infix[i] == '(') {
            while (!s.empty() && s.top() != ')') {
                prefix += s.top();
                s.pop();
            }
            if (!s.empty() && s.top() == ')') {
                s.pop();
            }
        } else {
            while (!s.empty() && precedence(infix[i]) < precedence(s.top())) {
                prefix += s.top();
                s.pop();
            }
            s.push(infix[i]);
        }
    }

    while (!s.empty()) {
        prefix += s.top();
        s.pop();
    }

    reverse(prefix.begin(), prefix.end());
    return prefix;
}

int precedence(char c) {
    if (c == '+' || c == '-')
        return 1;
    if (c == '*' || c == '/')
        return 2;
    return 0;
}

int main() {
    string postfix;
    cout << "Enter the postfix expression: ";
    getline(cin, postfix);

    string infix = post_to_in(postfix);
    cout << "Infix: " << infix << endl;

    string prefix = in_to_pre(infix);
    cout << "Prefix: " << prefix;

    return 0;
}

// Enter the postfix expression: abc*+d-
// Infix: a+b*c-d
// Prefix: -+a*bcd