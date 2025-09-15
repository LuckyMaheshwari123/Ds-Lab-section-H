#include <iostream>
using namespace std;

int factorial(int n){
    if(n<1){
        cout<<"negative factorial does not exit ";
        return -1;
    }
    if(n==1 || n==0 )return 1;
    else{
        return n*factorial(n-1);
    }
}

int main() {
    cout << factorial(17)<<endl;
    return 0;
}
