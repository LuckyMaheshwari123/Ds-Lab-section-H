#include <iostream>
#include <cmath>
#include <cctype>
using namespace std;

class CharStack {
    char arr[100];
    int top;
public:
    CharStack(){top=-1;}
    void push(char x){arr[++top]=x;}
    char pop(){return arr[top--];}
    char peek(){return arr[top];}
    bool empty(){return top==-1;}
};

class IntStack {
    int arr[100];
    int top;
public:
    IntStack(){top=-1;}
    void push(int x){arr[++top]=x;}
    int pop(){return arr[top--];}
};

int prec(char c){
    if(c=='^') return 3;
    if(c=='*'||c=='/') return 2;
    if(c=='+'||c=='-') return 1;
    return 0;
}

bool isOp(char c){
    return c=='+'||c=='-'||c=='*'||c=='/'||c=='^';
}

void reverse(string &s){
    int n=s.size();
    for(int i=0;i<n/2;i++) swap(s[i],s[n-1-i]);
}

string infixToPrefix(string infix){
    reverse(infix);
    for(int i=0;i<infix.size();i++){
        if(infix[i]=='(') infix[i]=')';
        else if(infix[i]==')') infix[i]='(';
    }
    CharStack st;
    string res="";
    for(char c: infix){
        if(isspace(c)) continue;
        if(isalnum(c)) res+=c;
        else if(c=='(') st.push(c);
        else if(c==')'){
            while(!st.empty() && st.peek()!='(') res+=st.pop();
            st.pop();
        }
        else if(isOp(c)){
            while(!st.empty() && prec(st.peek())>prec(c)) res+=st.pop();
            st.push(c);
        }
    }
    while(!st.empty()) res+=st.pop();
    reverse(res);
    return res;
}

int evalPrefix(string pre){
    IntStack st;
    for(int i=pre.size()-1;i>=0;i--){
        char c=pre[i];
        if(isdigit(c)) st.push(c-'0');
        else if(isOp(c)){
            int a=st.pop();
            int b=st.pop();
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
    string pre=infixToPrefix(exp);
    cout<<"Prefix: "<<pre<<endl;
    cout<<"Result: "<<evalPrefix(pre)<<endl;
    return 0;
}
