#include<bits/stdc++.h>
using namespace std;



class Node{
    public:
        int val;
        Node* left;
        Node* right;
    Node(int val){
        this->val = val;
        this->left = NULL;
        this->right = NULL;
    }
};
void print_inorder(Node* root);
void print_preorder(Node* root);
void print_postorder(Node* root);

int main(){
    Node* root = new Node(10);
    Node* a = new Node(20);
    Node* b = new Node(30);
    Node* c = new Node(40);
    Node* d = new Node(50);
    Node* e = new Node(60);

    root->left = a;
    root->right = b;
    a->left = c;
    b->left = d;
    b->right = e;
    
    cout << "Preorder Traversal : ";
    print_preorder(root);
    cout << "\n";
    cout << "Inorder Traversal : ";
    print_inorder(root);
    cout << "\n";
    cout << "Postorder Traversal : ";
    print_postorder(root);
    cout << "\n";
    return 0;
}

void print_preorder(Node* root){
    if(root == NULL)return;
    cout << root->val << " ";
    print_preorder(root->left);
    print_preorder(root->right);
}

void print_inorder(Node* root){
    if(root == NULL)return;
    print_inorder(root->left);
    cout << root->val << " ";
    print_inorder(root->right);
}


void print_postorder(Node* root){
    if(root == NULL)return;
    print_postorder(root->left);
    print_postorder(root->right);
    cout << root->val << " ";
}