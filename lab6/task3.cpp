#include<iostream>
using namespace std;
#define size 5
class Quee{
    int arr[size];
    int front,back;
    public:
    Quee(){
        front=-1;
        back=-1;
    }
bool isempty(){
    if(front==-1 || front>back){
        return true;
    }
    return false;
}

bool isfull(){
    if(back==size-1){
        return true;
    }
    return false;
}

void add(int data){
    if(isfull()){
        cout<<"can not add quee is full";
        return;
    }
    if(front==-1){
        front=0;
    }
    arr[++back]=data;// at zero index the elemet stored and index become 1
}
int del(){
  if(isempty()){
        cout<<"can not delete quee is full";
        return 0;
    }

    return arr[front++];
}

};
int main(){
    Quee q1;
    cout<<q1.isempty();
    q1.add(3);
    cout<<endl;
     cout<<q1.isempty();
     cout<<endl;
     cout<<q1.isfull();

}
