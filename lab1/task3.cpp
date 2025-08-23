#include<iostream>
using namespace std;
class Number{
    int *n;
    Number(){
        n=new int(0);
    }
    Number(int num){
        n=new int(num);
    }
    //deep copy
     Number(const Number& other) {
        n = new int(*other.n);
    }

    ~Number(){
        delete n;
    }

     void display() {
        cout << *n << endl;
    }

}
int main(){
Number n1;
Number n2(20);
Number n3=n2;
n1.display();
n2.display();
n3.display();
}
