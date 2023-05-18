#include <iostream>
#include <stack>
using namespace std;

int priority(char alpha) {
    if (alpha == '-')
        return 1;
    if (alpha == '+')
        return 2;
    if (alpha == '/')
        return 3;
    if (alpha == '*')
        return 4;
    return 0;
}

string inf_psf(string infix) {
    int i = 0;
    string postfix = "";
    stack<int> s;

    while (infix[i] != '\0') {
        if (infix[i] >= 'a' && infix[i] <= 'z' || infix[i] >= 'A' && infix[i] <= 'Z') {
            postfix += infix[i];
            i++;
        } else if (infix[i] == '(') {
            s.push(infix[i]);
            i++;
        } else if (infix[i] == ')') {
            while (s.top() != '(') {
                postfix += s.top();
                s.pop();
            }
            s.pop();
            i++;
        } else {
            while (!s.empty() && priority(infix[i]) <= priority(s.top())) {
                postfix += s.top();
                s.pop();
            }
            s.push(infix[i]);
            i++;
        }
    }
    while (!s.empty()) {
        postfix += s.top();
        s.pop();
    }

    cout << "Postfix: " << postfix;
    return postfix;
}

int main() {
    string infix;
    cout << "Enter the infix expression: ";
    getline(cin, infix);

    string postfix;
    postfix = inf_psf(infix);

    return 0;
}

// Enter the infix expression: a+b*c-d
// Postfix: abc*+d-