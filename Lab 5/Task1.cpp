#include <iostream>
using namespace std;

int factorial(int n){
    if(n<0){
        cout<<"negative factorial does not exit ";
        return -1;
    }
    if(n==1 || n==0 )return 1;
    else{
        return n*factorial(n-1);
    }
}

int main() {
    int n;
    cout<<"enter the number:";
    cout << factorial(n)<<endl;
    return 0;
}
