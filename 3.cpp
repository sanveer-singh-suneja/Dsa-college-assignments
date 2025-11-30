#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node *left,*right;
    Node(int x){data=x;left=right=NULL;}
};

Node* insertNode(Node* root,int key){
    if(!root) return new Node(key);
    if(key<root->data) root->left=insertNode(root->left,key);
    else if(key>root->data) root->right=insertNode(root->right,key);
    return root;
}

Node* findMin(Node* root){
    while(root->left) root=root->left;
    return root;
}

Node* deleteNode(Node* root,int key){
    if(!root) return root;
    if(key<root->data) root->left=deleteNode(root->left,key);
    else if(key>root->data) root->right=deleteNode(root->right,key);
    else{
        if(!root->left) return root->right;
        else if(!root->right) return root->left;
        Node* temp=findMin(root->right);
        root->data=temp->data;
        root->right=deleteNode(root->right,temp->data);
    }
    return root;
}

int maxDepth(Node* root){
    if(!root) return 0;
    return 1+max(maxDepth(root->left),maxDepth(root->right));
}

int minDepth(Node* root){
    if(!root) return 0;
    if(!root->left) return 1+minDepth(root->right);
    if(!root->right) return 1+minDepth(root->left);
    return 1+min(minDepth(root->left),minDepth(root->right));
}

int main(){
    Node* root=NULL;
    root=insertNode(root,10);
    insertNode(root,5);
    insertNode(root,15);
    insertNode(root,2);
    insertNode(root,7);

    root=deleteNode(root,5);
    cout<<maxDepth(root)<<endl;
    cout<<minDepth(root)<<endl;
}
