#include <iostream>
using namespace std;

struct Process{
    int id;
    int priority;
};

class Queue{
    Process arr[100];
    int front,rear,size;
public:
    Queue(){front=0;rear=-1;size=0;}
    void enqueue(Process p){arr[++rear]=p;size++;}
    Process dequeue(){size--;return arr[front++];}
    bool empty(){return size==0;}
    Process peek(){return arr[front];}
    int getSize(){return size;}
};

class Stack{
    Process arr[100];
    int top;
public:
    Stack(){top=-1;}
    void push(Process p){arr[++top]=p;}
    Process pop(){return arr[top--];}
    bool empty(){return top==-1;}
    Process peek(){return arr[top];}
};

int main(){
    Queue q;
    Stack s;
    int n;
    cout<<"Enter number of processes: ";
    cin>>n;
    for(int i=0;i<n;i++){
        Process p;
        cout<<"Enter Process ID and Priority: ";
        cin>>p.id>>p.priority;
        q.enqueue(p);
    }

    cout<<"\nArrival order (Queue): ";
    for(int i=0;i<n;i++){
        Process temp=q.dequeue();
        cout<<"[ID:"<<temp.id<<",P:"<<temp.priority<<"] ";
        if(s.empty()) s.push(temp);
        else if(temp.priority > s.peek().priority){
            Process top=s.pop();
            s.push(temp);
            s.push(top);
        } else s.push(temp);
    }

    cout<<"\nExecution order (Stack): ";
    while(!s.empty()){
        Process run=s.pop();
        cout<<"[ID:"<<run.id<<",P:"<<run.priority<<"] ";
    }
    cout<<endl;
    return 0;
}
