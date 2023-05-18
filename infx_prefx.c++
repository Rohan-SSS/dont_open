#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;

int priority(char alpha) {
    if (alpha == '-' || alpha == '+')
        return 1;
    if (alpha == '/' || alpha == '*')
        return 2;
    return 0;
}

string inf_pfx(string infix) {
    reverse(infix.begin(), infix.end());

    int i = 0;
    string prefix = "";
    stack<char> s;

    while (infix[i] != '\0') {
        if (infix[i] >= 'a' && infix[i] <= 'z' || infix[i] >= 'A' && infix[i] <= 'Z') {
            prefix += infix[i];
            i++;
        } else if (infix[i] == ')') {
            s.push(infix[i]);
            i++;
        } else if (infix[i] == '(') {
            while (s.top() != ')') {
                prefix += s.top();
                s.pop();
            }
            s.pop();
            i++;
        } else {
            while (!s.empty() && priority(infix[i]) < priority(s.top())) {
                prefix += s.top();
                s.pop();
            }
            s.push(infix[i]);
            i++;
        }
    }
    while (!s.empty()) {
        prefix += s.top();
        s.pop();
    }

    reverse(prefix.begin(), prefix.end());
    cout << "Prefix: " << prefix;
    return prefix;
}

int main() {
    string infix;
    cout << "Enter the infix expression: ";
    getline(cin, infix);

    string prefix;
    prefix = inf_pfx(infix);

    return 0;
}

// Enter the infix expression: a+b*c-d
// Prefix: -+a*bcd