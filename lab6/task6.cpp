#include <iostream>
#include <stack>
#include <algorithm>
#include <cmath>
#include <cctype>
using namespace std;

int precedence(char c) {
    if (c == '^') return 3;
    if (c == '*' || c == '/') return 2;
    if (c == '+' || c == '-') return 1;
    return 0;
}

bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

string infixToPrefix(string infix) {
    reverse(infix.begin(), infix.end());
    for (int i = 0; i < infix.size(); i++) {
        if (infix[i] == '(') infix[i] = ')';
        else if (infix[i] == ')') infix[i] = '(';
    }
    stack<char> st;
    string result;
    for (char c : infix) {
        if (isspace(c)) continue;
        if (isalnum(c)) result += c;
        else if (c == '(') st.push(c);
        else if (c == ')') {
            while (!st.empty() && st.top() != '(') {
                result += st.top();
                st.pop();
            }
            st.pop();
        } else if (isOperator(c)) {
            while (!st.empty() && precedence(st.top()) > precedence(c)) {
                result += st.top();
                st.pop();
            }
            st.push(c);
        }
    }
    while (!st.empty()) {
        result += st.top();
        st.pop();
    }
    reverse(result.begin(), result.end());
    return result;
}

int evaluatePrefix(string prefix) {
    stack<int> st;
    for (int i = prefix.size() - 1; i >= 0; i--) {
        char c = prefix[i];
        if (isdigit(c)) st.push(c - '0');
        else if (isOperator(c)) {
            int a = st.top(); st.pop();
            int b = st.top(); st.pop();
            switch (c) {
                case '+': st.push(a + b); break;
                case '-': st.push(a - b); break;
                case '*': st.push(a * b); break;
                case '/': st.push(a / b); break;
                case '^': st.push(pow(a, b)); break;
            }
        }
    }
    return st.top();
}

int main() {
    string infix;
    cout << "Enter infix expression: ";
    getline(cin, infix);
    string prefix = infixToPrefix(infix);
    cout << "Prefix expression: " << prefix << endl;
    cout << "Evaluated result: " << evaluatePrefix(prefix) << endl;
    return 0;
}
