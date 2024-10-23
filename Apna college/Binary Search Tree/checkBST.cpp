#include<iostream>
#include<vector>
#include<climits>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int val)
    {
        data=val;
        left=NULL;
        right=NULL;
    }
};

bool isBST(Node* root,Node* min,Node* max)
{
    if(root==NULL)
    {
        return true;
    }
    if((min!=NULL && min->data>=root->data) || (max!=NULL && max->data<=root->data))
    {
        return false;
    }
    return (isBST(root->left,min,root) && isBST(root->right,root,max));
}

int main()
{
    Node* root=new Node(2);
    root->left=new Node(1);
    root->right=new Node(3);
    root->left->left=new Node(-1);
    if(isBST(root,NULL,NULL))
    {
        cout<<"This is a valid BST\n";
    }
    else
    {
        cout<<"This is not a a valid BST\n";
    }
    return 0;
}