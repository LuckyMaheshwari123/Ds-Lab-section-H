#include <iostream>
using namespace std;

class LinkedList {
private:
    struct ListNode {
        int val;
        ListNode* next;
        ListNode(int x) : val(x), next(nullptr) {}
    };

    ListNode* head;


    ListNode* reverseList(ListNode* node) {
        ListNode* prev = nullptr;
        ListNode* curr = node;
        while (curr) {
            ListNode* nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }
        return prev;
    }

public:
    LinkedList() : head(nullptr) {}


    void append(int val) {
        ListNode* newNode = new ListNode(val);
        if (!head) {
            head = newNode;
            return;
        }
        ListNode* temp = head;
        while (temp->next)
            temp = temp->next;
        temp->next = newNode;
    }

    
    bool isPalindrome() {
        if (!head || !head->next)
            return true;

     
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

     
        ListNode* secondHalf = reverseList(slow);

     
        ListNode* firstHalf = head;
        ListNode* secondHalfCopy = secondHalf; 
        bool palindrome = true;
        while (secondHalf) {
            if (firstHalf->val != secondHalf->val) {
                palindrome = false;
                break;
            }
            firstHalf = firstHalf->next;
            secondHalf = secondHalf->next;
        }

        
        reverseList(secondHalfCopy);

        return palindrome;
    }

 
    void printList() {
        ListNode* temp = head;
        while (temp) {
            cout << temp->val << " -> ";
            temp = temp->next;
        }
        cout << "nullptr" << endl;
    }
};

int main() {
    LinkedList list;
    list.append(1);
    list.append(2);
    list.append(3);
    list.append(2);
    list.append(1);

    list.printList();

    if (list.isPalindrome()) {
        cout << "The list is a palindrome." << endl;
    } else {
        cout << "The list is NOT a palindrome." << endl;
    }

    return 0;
}
