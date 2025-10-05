#include <iostream>
#include <cmath>
#include <cctype>
using namespace std;

class Stack {
    char arr[100];
    int top;
public:
    Stack() { top = -1; }
    void push(char x) { arr[++top] = x; }
    char pop() { return arr[top--]; }
    char peek() { return arr[top]; }
    bool empty() { return top == -1; }
};

int precedence(char c) {
    if (c == '^') return 3;
    if (c == '*' || c == '/') return 2;
    if (c == '+' || c == '-') return 1;
    return 0;
}

bool isOperator(char c) {
    return c=='+'||c=='-'||c=='*'||c=='/'||c=='^';
}

string infixToPostfix(string infix) {
    Stack st;
    string out="";
    for(char c: infix){
        if(isspace(c)) continue;
        if(isalnum(c)) out+=c;
        else if(c=='(') st.push(c);
        else if(c==')'){
            while(!st.empty() && st.peek()!='('){ out+=st.pop(); }
            st.pop();
        } else if(isOperator(c)){
            while(!st.empty() && precedence(st.peek())>=precedence(c)) out+=st.pop();
            st.push(c);
        }
    }
    while(!st.empty()) out+=st.pop();
    return out;
}

class IntStack {
    int arr[100];
    int top;
public:
    IntStack(){top=-1;}
    void push(int x){arr[++top]=x;}
    int pop(){return arr[top--];}
    bool empty(){return top==-1;}
};

int evaluatePostfix(string exp){
    IntStack st;
    for(char c: exp){
        if(isdigit(c)) st.push(c-'0');
        else if(isOperator(c)){
            int b=st.pop();
            int a=st.pop();
            switch(c){
                case '+': st.push(a+b); break;
                case '-': st.push(a-b); break;
                case '*': st.push(a*b); break;
                case '/': st.push(a/b); break;
                case '^': st.push(pow(a,b)); break;
            }
        }
    }
    return st.pop();
}

int main(){
    string exp;
    cout<<"Enter infix expression: ";
    getline(cin,exp);
    string post=infixToPostfix(exp);
    cout<<"Postfix: "<<post<<endl;
    cout<<"Result: "<<evaluatePostfix(post)<<endl;
    return 0;
}
