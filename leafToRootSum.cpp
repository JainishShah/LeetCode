#include<bits/stdc++.h>

using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

typedef struct Node Node;

Node* newNode(int val){
    Node* temp = new Node;
    temp->data = val;
    temp->left = temp->right = NULL;
    return temp;
}

void dfs(Node* root){
    if(root == NULL)
        return;
    dfs(root->left);
    cout<<root->data<<"  ";
    dfs(root->right);
}


void findMaxSumLeafToRoot(Node* root,int sum, int* max_sum,Node** target_leaf){

    if(!root->left && !root->right){
        if(root->data + sum  > *max_sum ) {
            *max_sum = root->data + sum;
            *target_leaf = root; 
        }
        return;
    }

    if(root->left != NULL)
        findMaxSumLeafToRoot(root->left,sum+root->data,max_sum,target_leaf);
    if(root->right != NULL)
        findMaxSumLeafToRoot(root->right,sum+root->data,max_sum,target_leaf);
    
    return;
}


bool print_path(Node *root, Node* target_leaf){
    if(root == NULL)
        return false;
    
    if(root== target_leaf || print_path(root->left,target_leaf) || print_path(root->right,target_leaf)  ){
        cout<<root->data<<" ";
        return true;
    }
}


int main(){

    int max_val = INT_MIN;

    Node *root = newNode(-15); 
    root->left = newNode(5); 
    root->right = newNode(6); 
    root->left->left = newNode(-8); 
    root->left->right = newNode(1); 
    root->left->left->left = newNode(2); 
    root->left->left->right = newNode(6); 
    root->right->left = newNode(3); 
    root->right->right = newNode(9); 
    root->right->right->right= newNode(0); 
    root->right->right->right->left= newNode(4); 
    root->right->right->right->right= newNode(-1); 
    root->right->right->right->right->left= newNode(10); 

    int max_sum = INT_MIN;
    Node  *target_leaf = NULL;
    
    findMaxSumLeafToRoot(root,0,&max_sum,&target_leaf);
    cout<<max_sum<<endl;
    print_path(root,target_leaf);
    return 0;
}
