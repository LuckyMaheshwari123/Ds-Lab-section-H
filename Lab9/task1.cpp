#include <iostream>
#include <algorithm>
using namespace std;

struct Node {
    int key;
    Node* left;
    Node* right;
    int height;

    Node(int k) {
        key = k;
        left = right = nullptr;
        height = 1;
    }
};

int height(Node* n) {
    return n ? n->height : 0;
}

int getBalance(Node* n) {
    return n ? height(n->left) - height(n->right) : 0;
}

Node* rightRotate(Node* y) {
    cout << "Rotation: Right Rotate on node " << y->key << endl;

    Node* x = y->left;
    Node* T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    return x;
}

Node* leftRotate(Node* x) {
    cout << "Rotation: Left Rotate on node " << x->key << endl;

    Node* y = x->right;
    Node* T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    return y;
}

Node* insertNode(Node* node, int key) {
    if (!node) {
        cout << "\nInserted: " << key << endl;
        return new Node(key);
    }

    if (key < node->key)
        node->left = insertNode(node->left, key);
    else if (key > node->key)
        node->right = insertNode(node->right, key);
    else
        return node;   

    node->height = max(height(node->left), height(node->right)) + 1;

    int balance = getBalance(node);
    cout << "Balance factor at node " << node->key << " = " << balance << endl;

    // LL case
    if (balance > 1 && key < node->left->key)
        return rightRotate(node);

    // RR case
    if (balance < -1 && key > node->right->key)
        return leftRotate(node);

    // LR case
    if (balance > 1 && key > node->left->key) {
        cout << "Rotation: Left Rotate on node " << node->left->key << " (LR case)\n";
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    // RL case
    if (balance < -1 && key < node->right->key) {
        cout << "Rotation: Right Rotate on node " << node->right->key << " (RL case)\n";
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

Node* minValueNode(Node* node) {
    Node* current = node;
    while (current->left != nullptr)
        current = current->left;
    return current;
}

Node* deleteNode(Node* root, int key) {
    if (!root)
        return root;

    if (key < root->key)
        root->left = deleteNode(root->left, key);
    else if (key > root->key)
        root->right = deleteNode(root->right, key);
    else {
        cout << "\nDeleting: " << key << endl;

        if (root->left == nullptr || root->right == nullptr) {
            Node* temp = root->left ? root->left : root->right;

            if (!temp) {
                temp = root;
                root = nullptr;
            } else 
                *root = *temp;

            delete temp;
        } else {
            Node* temp = minValueNode(root->right);
            root->key = temp->key;
            root->right = deleteNode(root->right, temp->key);
        }
    }

    if (!root)
        return root;

    root->height = max(height(root->left), height(root->right)) + 1;

    int balance = getBalance(root);
    cout << "Balance factor at node " << root->key << " = " << balance << endl;

    // LL
    if (balance > 1 && getBalance(root->left) >= 0) {
        return rightRotate(root);
    }

    // LR
    if (balance > 1 && getBalance(root->left) < 0) {
        cout << "Rotation: Left Rotate on node " << root->left->key << "\n";
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    // RR
    if (balance < -1 && getBalance(root->right) <= 0) {
        return leftRotate(root);
    }

    // RL
    if (balance < -1 && getBalance(root->right) > 0) {
        cout << "Rotation: Right Rotate on node " << root->right->key << "\n";
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

int treeHeight(Node* root) {
    if (!root) return 0;
    return root->height;
}

int main() {
    Node* root = nullptr;

    
    int inserts[] = { 50, 20, 70, 10, 30, 25, 60 };
    cout << "\n---INSERT--- \n";
    for (int x : inserts) {
        root = insertNode(root, x);
        cout << "Tree Height after insertion: " << treeHeight(root) << "\n";
        cout << "---------------------------\n";
    }

  
    int deletes[] = { 20, 30, 50 };
    cout << "\n--- DELETING ---\n";
    for (int x : deletes) {
        root = deleteNode(root, x);
        cout << "Tree Height after deletion: " << treeHeight(root) << "\n";
        cout << "---------------------------\n";
    }

    return 0;
}
