Node* delNode(Node* root, Node* toDelete)
{
    Node* prev, *temp=root;
    while(1){
        prev=temp;
        if(temp->right){    
            temp=temp->right;
            toLeft = false;
        }
        else if(temp->left){
            temp=temp->left;
            toLeft = true;    
        }
        else{
            toDelete->data = temp->data;
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
    return root;
}

Node* searchKey(Node* root, int key){
    if(root == NULL)
        return root;

    searchKey(root->left, key);
    if(root->data == key)   return root;
    searchKey(root->right, key);
}