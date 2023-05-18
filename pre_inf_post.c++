#include <iostream>
#include <stack>
using namespace std;

bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

string pre_to_in(string prefix);
string in_to_post(string infix);
int precedence(char c);

string pre_to_in(string prefix) {
    stack<string> s;

    int length = prefix.length();

    for (int i = length - 1; i >= 0; i--) {
        if (isOperator(prefix[i])) {
            string operand1 = s.top();
            s.pop();
            string operand2 = s.top();
            s.pop();
            string temp = operand1 + prefix[i] + operand2;
            s.push(temp);
        } else {
            s.push(string(1, prefix[i]));
        }
    }

    string infix = s.top();
    return infix;
}

string in_to_post(string infix) {
    int length = infix.length();
    string postfix = "";
    stack<char> s;

    for (int i = 0; i < length; i++) {
        if (isalnum(infix[i])) {
            postfix += infix[i];
        } else if (infix[i] == '(') {
            s.push(infix[i]);
        } else if (infix[i] == ')') {
            while (!s.empty() && s.top() != '(') {
                postfix += s.top();
                s.pop();
            }
            if (!s.empty() && s.top() == '(') {
                s.pop();
            }
        } else {
            while (!s.empty() && precedence(infix[i]) <= precedence(s.top())) {
                postfix += s.top();
                s.pop();
            }
            s.push(infix[i]);
        }
    }

    while (!s.empty()) {
        postfix += s.top();
        s.pop();
    }

    return postfix;
}

int precedence(char c) {
    if (c == '+' || c == '-')
        return 1;
    if (c == '*' || c == '/')
        return 2;
    return 0;
}

int main() {
    string prefix;
    cout << "Enter the prefix expression: ";
    getline(cin, prefix);

    string infix = pre_to_in(prefix);
    cout << "Infix: " << infix << endl;

    string postfix = in_to_post(infix);
    cout << "Postfix: " << postfix;

    return 0;
}

// Enter the prefix expression: -+a*bcd
// Infix: a+b*c-d
// Postfix: abc*+d-