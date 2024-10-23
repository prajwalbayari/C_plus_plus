#include<iostream>
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

Node* insertBST(Node *root,int val)
{
    if(root==NULL)
    {
        return new Node(val);
    }
    if(root->data>val)
    {
        root->left=insertBST(root->left,val);
    }
    else
    {
        root->right=insertBST(root->right,val);
    }
    return root;
}

void inorder(Node *root)
{
    if(root!=NULL)
    {
        inorder(root->left);
        cout<<root->data<<" ";
        inorder(root->right);
    }
}

int main()
{
    Node *root=new Node(10);
    root=insertBST(root,-1);
    root=insertBST(root,78);
    root=insertBST(root,0);
    root=insertBST(root,190);
    root=insertBST(root,7);
    root=insertBST(root,5);
    root=insertBST(root,15);
    root=insertBST(root,12);
    root=insertBST(root,1);
    root=insertBST(root,-10);
    root=insertBST(root,9);
    inorder(root);
    return 0;
}