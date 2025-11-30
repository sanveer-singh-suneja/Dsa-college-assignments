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

Node* searchRec(Node* root,int key){
    if(!root||root->data==key) return root;
    if(key<root->data) return searchRec(root->left,key);
    return searchRec(root->right,key);
}

Node* searchIter(Node* root,int key){
    while(root){
        if(root->data==key) return root;
        if(key<root->data) root=root->left;
        else root=root->right;
    }
    return NULL;
}

Node* findMax(Node* root){
    while(root->right) root=root->right;
    return root;
}

Node* findMin(Node* root){
    while(root->left) root=root->left;
    return root;
}

Node* inorderSuccessor(Node* root,Node* x){
    if(x->right) return findMin(x->right);
    Node* succ=NULL;
    while(root){
        if(x->data<root->data){
            succ=root;
            root=root->left;
        } else if(x->data>root->data) root=root->right;
        else break;
    }
    return succ;
}

Node* inorderPredecessor(Node* root,Node* x){
    if(x->left) return findMax(x->left);
    Node* pred=NULL;
    while(root){
        if(x->data>root->data){
            pred=root;
            root=root->right;
        } else if(x->data<root->data) root=root->left;
        else break;
    }
    return pred;
}

int main(){
    Node* root=NULL;
    root=insertNode(root,20);
    insertNode(root,10);
    insertNode(root,30);
    insertNode(root,5);
    insertNode(root,15);

    Node* x=searchRec(root,10);
    cout<<searchIter(root,15)->data<<endl;
    cout<<findMax(root)->data<<endl;
    cout<<findMin(root)->data<<endl;
    cout<<inorderSuccessor(root,x)->data<<endl;
    cout<<inorderPredecessor(root,x)->data<<endl;
}
