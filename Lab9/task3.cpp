#include <iostream>

using namespace std;
int max(int a,int b){
 if(a>b) return a;
return b;
    
}
struct Node {
    int score;
    Node* left;
    Node* right;
    int height;
    Node(int s) {
        score = s;
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
    cout << "Rotation: Right Rotate on " << y->score << endl;
    Node* x = y->left;
    Node* T2 = x->right;
    x->right = y;
    y->left = T2;
    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;
    return x;
}

Node* leftRotate(Node* x) {
    cout << "Rotation: Left Rotate on " << x->score << endl;
    Node* y = x->right;
    Node* T2 = y->left;
    y->left = x;
    x->right = T2;
    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;
    return y;
}

Node* insertNode(Node* node, int score) {
    if (!node) {
        cout << "\nInserted patient severity: " << score << endl;
        return new Node(score);
    }

    if (score < node->score)
        node->left = insertNode(node->left, score);
    else if (score > node->score)
        node->right = insertNode(node->right, score);
    else
        return node;

    node->height = max(height(node->left), height(node->right)) + 1;
    int balance = getBalance(node);

    if (balance > 1 || balance < -1)
        cout << "Tree became unbalanced at node " << node->score << endl;

    if (balance > 1 && score < node->left->score)
        return rightRotate(node);

    if (balance < -1 && score > node->right->score)
        return leftRotate(node);

    if (balance > 1 && score > node->left->score) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    if (balance < -1 && score < node->right->score) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

Node* minValueNode(Node* node) {
    Node* curr = node;
    while (curr->left)
        curr = curr->left;
    return curr;
}

Node* deleteNode(Node* root, int score) {
    if (!root)
        return root;

    if (score < root->score)
        root->left = deleteNode(root->left, score);
    else if (score > root->score)
        root->right = deleteNode(root->right, score);
    else {
        cout << "\nDischarging patient with severity: " << score << endl;
        if (!root->left || !root->right) {
            Node* temp = root->left ? root->left : root->right;
            if (!temp) {
                temp = root;
                root = nullptr;
            } else
                *root = *temp;
            delete temp;
        } else {
            Node* temp = minValueNode(root->right);
            root->score = temp->score;
            root->right = deleteNode(root->right, temp->score);
        }
    }

    if (!root)
        return root;

    root->height = max(height(root->left), height(root->right)) + 1;
    int balance = getBalance(root);

    if (balance > 1 && getBalance(root->left) >= 0)
        return rightRotate(root);

    if (balance > 1 && getBalance(root->left) < 0) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    if (balance < -1 && getBalance(root->right) <= 0)
        return leftRotate(root);

    if (balance < -1 && getBalance(root->right) > 0) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

int highestSeverity(Node* root) {
    if (!root) return -1;
    while (root->right) root = root->right;
    return root->score;
}

int main() {
    Node* root = nullptr;

    int arrivals[] = { 40, 55, 20, 75, 10, 60, 80, 65 };
    int discharges[] = { 20, 75, 55 };

    cout << "--- Patient Arrivals (Insert) ---\n";
    for (int s : arrivals) {
        root = insertNode(root, s);
        cout << "Tree Height: " << root->height << endl;
        cout << "Highest Severity Patient: " << highestSeverity(root) << "\n\n";
    }

    cout << "--- Patient Discharges (Delete) ---\n";
    for (int s : discharges) {
        root = deleteNode(root, s);
        if (root) {
            cout << "Tree Height: " << root->height << endl;
            cout << "Highest Severity Patient: " << highestSeverity(root) << "\n\n";
        } else {
            cout << "Tree is empty.\n\n";
        }
    }

    return 0;
}
