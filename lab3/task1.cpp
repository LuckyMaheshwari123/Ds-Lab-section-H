#include <iostream>
using namespace std;


class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = nullptr;
    }
};


class LinkedList {
private:
    Node* head;

  
    Node* reverse(Node* node) {
        Node* prev = nullptr;
        Node* curr = node;
        while (curr) {
            Node* nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }
        return prev;
    }

public:
    LinkedList() {
        head = nullptr;
    }

    void append(int val) {
        Node* newNode = new Node(val);
        if (!head) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next)
            temp = temp->next;
        temp->next = newNode;
    }

    void printList() {
        Node* temp = head;
        while (temp) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "nullptr" << endl;
    }

    
    bool isPalindrome() {
        if (!head || !head->next) return true;

      
        Node* slow = head;
        Node* fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        
        Node* secondHalf = reverse(slow);

        Node* firstHalf = head;
        Node* secondHalfCopy = secondHalf; 
        bool result = true;
        while (secondHalf) {
            if (firstHalf->data != secondHalf->data) {
                result = false;
                break;
            }
            firstHalf = firstHalf->next;
            secondHalf = secondHalf->next;
        }

        
        reverse(secondHalfCopy);

        return result;
    }
};

int main() {
    LinkedList list;

   
    list.append(1);
    list.append(2);
    list.append(3);
    list.append(2);
    list.append(1);

    cout << "Linked List: ";
    list.printList();

  
    if (list.isPalindrome()) {
        cout << "The list is a palindrome." << endl;
    } else {
        cout << "The list is NOT a palindrome." << endl;
    }

    return 0;
}
