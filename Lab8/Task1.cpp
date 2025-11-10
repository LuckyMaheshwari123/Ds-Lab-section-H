#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int value) {
        data = value;
        left = right = NULL;
    }
};
void printLeafNodes(Node* root) {
    if (root == nullptr) return;

    if (root->left == nullptr && root->right == nullptr)
        cout << root->data<< " ";
    else {
        printLeafNodes(root->left);
        printLeafNodes(root->right);
    }
}

int height(Node* root) {
    if (root == NULL)
        return 0;  
    else {
        int leftHeight = height(root->left);
        int rightHeight = height(root->right);
        return 1 + max(leftHeight, rightHeight);
    }
}
void printLevels(Node* root, int level = 1) {
    if (root == NULL)
        return;

    cout << "Node " << root->data << " is at level " << level << endl;

    // Recursive calls for left and right children
    printLevels(root->left, level + 1);
    printLevels(root->right, level + 1);
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    cout << "Root: " << root->data << endl;
    printLeafNodes(root);
    cout<<endl;
    cout<<"height:"<<height(root)<<endl;
    printLevels(root->left->left,1);
    return 0;
}
