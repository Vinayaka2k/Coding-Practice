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


void delNode(Node* root, Node* toDelete)
{
    if(!root){
        delete root;
        return;
    }

    Node* prev, *temp=root;
    bool toLeft;
    while(1){
        if(temp->right){  
            prev=temp;  
            temp=temp->right;
            toLeft = false;
        }
        else if(temp->left){
            prev=temp;
            temp=temp->left;
            toLeft = true;    
        }
        else{
            toDelete->data = temp->data;
            break;
        }
    }
    if(toLeft){
        delete prev->left;
        prev->left = NULL;
    }
    else{
        delete prev->right;
        prev->right = NULL;
    }
}
Node* searchKey(Node* root, int key){
    if(!root)   return NULL;
    
    Node* left_tree = searchKey(root->left, key);
    Node* right_tree = searchKey(root->right, key);
    

    if(left_tree == NULL && right_tree == NULL){
        if(root->data == key){
            return root;
        }
        return NULL;
    }
    if(left_tree == NULL)
        return right_tree;
    return left_tree;
}


int main(){
    Node* root;
    root = createTree(root);
    inorder(root);
    cout << endl;
    Node* temp = searchKey(root, 8);
    delNode(root, temp);
    inorder(root);
}
