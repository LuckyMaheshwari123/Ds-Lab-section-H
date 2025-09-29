#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = nullptr;
    }
};

class Stack {
    Node* top;
    int count;

public:
    Stack() {
        top = nullptr;
        count = 0;
    }

    void push(int x) {
        Node* temp = new Node(x);
        temp->next = top;
        top = temp;
        count++;
    }

    void pop() {
        if (top == nullptr) {
            cout << "Stack is empty\n";
            return;
        }
        Node* temp = top;
        top = top->next;
        cout << "Popped element: " << temp->data << "\n";
        delete temp;
        count--;
    }

    int peek() {
        if (top == nullptr) {
            cout << "Stack is empty\n";
            return -1;
        }
        return top->data;
    }

    bool isEmpty() {
        return top == nullptr;
    }

    int size() {
        return count;
    }
};

int main() {
    Stack st;
    st.push(7);
    st.push(14);
    st.push(21);

    cout << "Top element: " << st.peek() << "\n";
    st.pop();
    cout << "Top element after pop: " << st.peek() << "\n";
    cout << "Stack size: " << st.size() << "\n";

    return 0;
}
