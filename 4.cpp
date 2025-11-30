#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node *left,*right;
    Node(int x){data=x;left=right=NULL;}
};

bool isBST(Node* root,long long minv,long long maxv){
    if(!root) return true;
    if(root->data<=minv || root->data>=maxv) return false;
    return isBST(root->left,minv,root->data) &&
           isBST(root->right,root->data,maxv);
}

int main(){
    Node* root=new Node(10);
    root->left=new Node(5);
    root->right=new Node(15);
    root->right->left=new Node(12);
    root->right->right=new Node(20);

    cout<<isBST(root,LLONG_MIN,LLONG_MAX);
}

