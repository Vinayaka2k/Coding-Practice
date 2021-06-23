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
    root = newNode(10);
    root->left = newNode(11);
    root->left->left = newNode(7);
    root->right = newNode(9);
    root->right->left = newNode(15);
    root->right->right = newNode(8);
    return root;
}

void inorder(Node* root){
    if(root == NULL)    return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

Node* insertNode(Node* root, int key){
    if(!root){
        return newNode(key);
    }
    queue<Node*> q;
    q.push(root);

    while(!q.empty()){
        Node* temp = q.front();
        q.pop();
        if(temp->left)
            q.push(temp->left);
        else{
            temp->left = newNode(key);
            return root;
        }
        if(temp->right)
            q.push(temp->right);
        else{
            temp->right = newNode(key);
            return root;
        }
    }
}

int main(){
    Node* root;
    root = createTree(root);
    inorder(root);
    root = insertNode(root, 12);
    cout << endl << "After insertion:" << endl;
    inorder(root);
}