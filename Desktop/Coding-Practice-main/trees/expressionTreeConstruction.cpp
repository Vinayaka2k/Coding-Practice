#include<bits/stdc++.h>
using namespace std;

struct Node{
    char data;
    struct Node* left;
    struct Node* right;
};

Node* newNode(char c){
    Node* n = new Node();
    n->left = NULL;
    n->right = NULL;
    n->data = c;
    return n;
}

void inorder(Node* root){
    if(root == NULL)    return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

Node* createExpressionTree(string postfix){
    int i=0;
    char c;
    Node* temp; 
    stack<Node*> s;
    while(i<postfix.length()){
        c=postfix[i];
        if(c>='0' && c<='9'){
            temp = newNode(c);
            s.push(temp);
        }
        else{
            Node* t1 = s.top(); 
            s.pop();
            Node* t2 = s.top();
            s.pop();
            temp = newNode(c);
            temp->right = t1;   
            temp->left = t2;
            s.push(temp);
        }
        ++i;
    }
    return s.top();
}

int evalTree(Node* root){
    if(root->data >= '0' && root->data <= '9')
        return root->data -'0';
    int res;
    int left = evalTree(root->left);
    int right = evalTree(root->right);
    switch(root->data){
        case '+' : {
            res = left + right; break;
        }
        case '-' : {
            res = left - right; break;
        }
        case '*' : {
            res = left * right; break;
        }
    }
    return res;
}

int main(){
    string postfix = "12+34*5*-";
    Node* root = createExpressionTree(postfix);
    inorder(root);
    cout << endl;
    cout << evalTree(root) << endl;
}
