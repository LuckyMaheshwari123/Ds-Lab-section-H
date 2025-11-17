#include <iostream>


using namespace std;
int max(int a,int b){
    if(a>b) return a;
    return b;
}
struct Node {
    int price;
    Node* left;
    Node* right;
    int height;

    Node(int p) {
        price = p;
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
    Node* x = y->left;
    Node* T2 = x->right;
    x->right = y;
    y->left = T2;
    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;
    return x;
}

Node* leftRotate(Node* x) {
    Node* y = x->right;
    Node* T2 = y->left;
    y->left = x;
    x->right = T2;
    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;
    return y;
}

Node* insertNode(Node* node, int price) {
    if (!node)
        return new Node(price);

    if (price < node->price)
        node->left = insertNode(node->left, price);
    else if (price > node->price)
        node->right = insertNode(node->right, price);
    else
        return node;

    node->height = max(height(node->left), height(node->right)) + 1;

    int balance = getBalance(node);

    if (balance > 1 && price < node->left->price)
        return rightRotate(node);

    if (balance < -1 && price > node->right->price)
        return leftRotate(node);

    if (balance > 1 && price > node->left->price) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    if (balance < -1 && price < node->right->price) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

void rangeQuery(Node* root, int X, int Y) {
    if (!root) return;
    if (root->price > X)
        rangeQuery(root->left, X, Y);
    if (root->price >= X && root->price <= Y)
        cout << root->price << " ";
    if (root->price < Y)
        rangeQuery(root->right, X, Y);
}

void inorder(Node* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->price << " ";
    inorder(root->right);
}

int main() {
    Node* root = nullptr;

    int prices[] = { 499, 199, 999, 349, 799, 1299, 250 };
    int n = sizeof(prices) / sizeof(prices[0]);

    for (int p : prices)
        root = insertNode(root, p);

    cout << "All prices: ";
    inorder(root);

    int X, Y;
    cout << "\nEnter range (X Y): ";
    cin >> X >> Y;

    cout << "Prices between " << X << " and " << Y << ": ";
    rangeQuery(root, X, Y);

    return 0;
}
