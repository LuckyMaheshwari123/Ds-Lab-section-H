#include <iostream>
using namespace std;

class CircularQueue {
    int *arr;
    int front;
    int rear;
    int size;

public:
    CircularQueue(int s) {
        size = s;
        arr = new int[size];
        front = -1;
        rear = -1;
    }

    void enqueue(int value) {
        if ((front == 0 && rear == size - 1) || (rear + 1) % size == front) {
            cout << "Queue Overflow (Full)" << endl;
            return;
        }
        if (front == -1)
            front = 0;
        rear = (rear + 1) % size;
        arr[rear] = value;
        cout << value << " enqueued to queue." << endl;
    }

    void dequeue() {
        if (front == -1) {
            cout << "Queue Underflow (Empty)" << endl;
            return;
        }
        cout << arr[front] << " dequeued from queue." << endl;
        if (front == rear) {
            front = rear = -1;
        } else {
            front = (front + 1) % size;
        }
    }

    void display() {
        if (front == -1) {
            cout << "Queue is empty." << endl;
            return;
        }
        cout << "Queue elements: ";
        int i = front;
        while (true) {
            cout << arr[i] << " ";
            if (i == rear)
                break;
            i = (i + 1) % size;
        }
        cout << endl;
    }

    int peek() {
        if (front == -1) {
            cout << "Queue is empty." << endl;
            return -1;
        }
        return arr[front];
    }
};

int main() {
    CircularQueue q(5);
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);
    q.display();
    q.dequeue();
    q.dequeue();
    q.display();
    q.enqueue(60);
    q.enqueue(70);
    q.display();
    return 0;
}
