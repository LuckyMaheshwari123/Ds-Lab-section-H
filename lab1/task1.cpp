#include<iostream>
using namespace std;

class Account {
public:
    int *balance;
    Account() {
        balance = new int(0);
    }

   
    Account(int b) {
        balance = new int(b);
    }
    
    Account(const Account& other) {
        balance = new int(*other.balance);
    }
    
    void display() {
        cout << *balance << endl;
    }

    ~Account() {
        delete balance;
    
    }
};

int main() {
    Account a1;
    a1.display(); 

    Account a2(1000);
    a2.display(); 

    Account a3 = a2;
    *a3.balance -= 200;

    a3.display(); 
    a2.display(); 
}
