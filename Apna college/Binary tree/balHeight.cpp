#include<iostream>
#include<algorithm>
using namespace std;

class Node
{
    public:
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data=val;
        left=right=NULL;
    }
};

int height(Node* root)
{
    if(root==NULL)
    {
        return 0;
    }
    return 1+max(height(root->left),height(root->right));
}

bool balance(Node* root)
{
    if(root==NULL)
    {
        return true;
    }
    if(balance(root->left)==false || balance(root->right)==false)
    {
        return false;
    }
    if(abs(height(root->left)-height(root->right))<=1)
    {
        return true;
    }
    return false;
}

bool isBalanced(Node* root,int* height)
{
    int lh=0,rh=0;
    if(root==NULL)
    {
        return true;
    }
    if(isBalanced(root->left,&lh)==false || isBalanced(root->right,&rh)==false)
    {
        return false;
    }
    *height=max(lh,rh)+1;
    if(abs(lh-rh)<=1)
    {
        return true;
    }
    return false;
}

int main()
{
    int h=0;
    Node *root=new Node(1);
    root->left=new Node(2);
    root->right=new Node(3);
    root->left->left=new Node(4);
    root->left->left->right=new Node(5);
    if(isBalanced(root,&h))
    {
        printf("Balanced tree\n");
    }
    else
    {
        printf("Not a balanced tree\n");
    }
    return 0;
}