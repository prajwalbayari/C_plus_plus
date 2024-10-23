#include<iostream>
#include<stdlib.h>
#include<algorithm>
#include<queue>
using namespace std;

class Node
{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int val)
    {
        data=val;
        left=NULL;
        right=NULL;
    }
};

Node* LCA(Node *root,int n1,int n2)
{
    if(root==NULL)
    {
        return NULL;
    }
    if(root->data==n1 || root->data==n2)
    {
        return root;
    }
    Node *left=LCA(root->left,n1,n2);
    Node *right=LCA(root->right,n1,n2);
    if(left!=NULL && right!=NULL)
    {
        return root;
    }
    if(left==NULL && right==NULL)
    {
        return NULL;
    }
    if(left!=NULL)
    {
        return LCA(root->left,n1,n2);
    }
    return LCA(root->right,n1,n2);
}

int dist(Node *root,int k,int d)
{
    if(root==NULL)
    {
        return -1;
    }
    if(root->data==k)
    {
        return d;
    }
    int l=dist(root->left,k,d+1);
    if(l!=-1)
    {
        return l;
    }
    return dist(root->right,k,d+1);
}

int dis(Node *root,int n1,int n2)
{
    Node *lca=LCA(root,n1,n2);
    int d1=dist(lca,n1,0);
    int d2=dist(lca,n2,0);
    return d1+d2;
}

int main()
{
    Node *root=new Node(1);
    root->left=new Node(2);
    root->right=new Node(3);
    root->left->left=new Node(4);
    root->left->right=new Node(5);
    root->right->left=new Node(6);
    root->right->right=new Node(7);
    root->left->left->left=new Node(8);
    root->left->left->right=new Node(9);
    root->left->right->left=new Node(10);
    root->left->right->right=new Node(11);
    root->right->left->left=new Node(12);
    root->right->left->right=new Node(13);
    root->right->right->left=new Node(14);
    root->right->right->right=new Node(15);
    cout<<dis(root,8,15);
    return 0;
}