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

Node* insert(Node* root, int data) {
    if (root == NULL) {
        return new Node(data);
    }
    if (data < root->data) {
        root->left = insert(root->left, data);
    }
    else if (data > root->data) {
        root->right = insert(root->right, data);
    }
    return root;
}

Node* search(Node* root, int data) {
    if (root == NULL || root->data == data) {
        return root;
    }
    if (data < root->data) {
        return search(root->left, data);
    }
    return search(root->right, data);
}

void inorder(Node* root) {
    if (root == NULL) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void postorder(Node* root) {
    if (root == NULL) return;
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

int main() {
    Node* rootNode = new Node(10);
    insert(rootNode, 12);
    insert(rootNode, 13);
    insert(rootNode, 15);
    insert(rootNode, 8);
    
    cout << "Inorder Traversal: ";
    inorder(rootNode);
    cout << endl;

    cout << "Postorder Traversal: ";
    postorder(rootNode);
    cout << endl;

    return 0;
}
