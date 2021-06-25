#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    struct Node* left;
    struct Node* right;
};

Node* newNode(int key){
    Node* n = new Node();
    n->left = NULL;
    n->right = NULL;
    n->data = key;
    return n;
}

Node* createTree(Node* root){
    root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    return root;
}

void inorder(Node* root){
    stack<Node*> s;
    Node* curr = root;
    while(!s.empty() || curr){
        if(curr == NULL){
            Node* temp = s.top();
            s.pop();
            curr = temp->right;
            cout << temp->data << " ";
        }
        else{
            s.push(curr);
            curr = curr->left;
        }
    }
}

int main(){
    Node* root;
    root = createTree(root);
    inorder(root);
    cout << endl;
}