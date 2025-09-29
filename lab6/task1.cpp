#include<iostream>
using namespace std;

class Stack{
    //array
    int size=5;
    int top=-1;
    int arr[5];
    public:
    bool push(int n){
        if(top>=size-1){
            cout<<"stack over flow";
            return false;
        }
        else{
            arr[++top]=n;
            return true;
        }
     

      return false;
    }
    int  pop(){
      if(top<0){
          cout<<"stack is empty";
          return 0;
      }
      else{
          int x=arr[top--];
          return x;
      }

      return 0;
    }
    int peek(){
        if(top<0){
          cout<<"stack is empty";
          return 0;
      }
      else{
          int x=arr[top];
          return x;
      }
     
    }
    void display(){
        if(top<0){
            cout<<"list is empty";
            return;
        }
     for(int i=0;i<=top;i++){
         cout<<arr[i]<<" ";
     }
    }
    bool isempty(){
        return (top<0);
    }

};


int main(){
    Stack s1;
   s1.push(10);
   s1.push(20);
   s1.push(30);
   s1.pop();
   cout<<s1.peek()<<endl;
  s1.display();
  cout<<endl;
  cout<<s1.isempty()<<endl;


}
