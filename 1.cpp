
#include <bits/stdc++.h>
using namespace std;

class Node {
    public:
    int data;
    Node* left;
    Node* right;

    Node(int val){
       this->data = val;
       this->left = NULL;
       this->right = NULL;
    }
};

class BST {
private:
    Node* root;

    Node* insert(Node* node, int key) {
        if (node == NULL) return new Node(key);
        if (key < node->data)
            node->left = insert(node->left, key);
        else if (key > node->data)
            node->right = insert(node->right, key);
        return node;
    }

    void preorder(Node* node) {
        if (node == NULL) return;
        cout << node->data << " ";
        preorder(node->left);
        preorder(node->right);
    }

    void inorder(Node* node) {
        if (node == NULL) return;
        inorder(node->left);
        cout << node->data << " ";
        inorder(node->right);
    }

    void postorder(Node* node) {
        if (node == NULL) return;
        postorder(node->left);
        postorder(node->right);
        cout << node->data << " ";
    }

    bool search(Node* node, int key) {
        if (node == NULL) return false;
        if (node->data == key) return true;
        if (key < node->data) return search(node->left, key);
        return search(node->right, key);
    }

    
    int pathLength(Node* node, int depth) {
        if (node == NULL) return 0;
        return depth + pathLength(node->left, depth + 1) + pathLength(node->right, depth + 1);
    }

public:
    BST() : root(NULL) {}

    void insert(int key) {
        root = insert(root, key);
    }

    void displayTraversals() {
        cout << "Pre-order: ";
        preorder(root);
        cout << "\nIn-order: ";
        inorder(root);
        cout << "\nPost-order: ";
        postorder(root);
        cout << endl;
    }

    void searchKey(int key) {
        cout << (search(root, key) ? "Yes" : "No") << endl;
    }

    void calculatePathLength() {
        cout << "Path Length of the tree: " << pathLength(root, 0) << endl;
    }
};

int main() {
    BST bst;
    int n, key;

    cout << "Enter number of elements: ";
    cin >> n;
    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++) {
        cin >> key;
        bst.insert(key);
    }

    bst.displayTraversals();

    cout << "Enter key to search: ";
    cin >> key;
    cout << "Search result: ";
    bst.searchKey(key);

    cout << "Enter a new key to insert: ";
    cin >> key;
    bst.insert(key);
    cout << "Tree after insertion (In-order): ";
    bst.calculatePathLength();

    return 0;
}