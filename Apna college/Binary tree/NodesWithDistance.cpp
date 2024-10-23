#include<iostream>
using namespace std;

class Node
{
    public:
    int data;
    struct Node* left;
    struct Node* right;

    Node(int val)
    {
        data=val;
        left=NULL;
        right=NULL;
    }
};

//Case 1: Search for the nodes with the given distance from the target node in it's right and left subtree (Descendants)
void printSubtreeNodes(Node *root,int k)
{
    if(root==NULL || k<0)
    {
        return;
    }
    if(k==0)
    {
        cout<<root->data<<" ";
        return;
    }
    printSubtreeNodes(root->left,k-1);
    printSubtreeNodes(root->right,k-1);
}

//Case 2: Search for the nodes with given distance among the ancestor and their descendants
int printNodeAtK(Node *root,Node *target,int k)
{
    if(root==NULL)
    {
        return -1;
    }
    if(root==target)
    {
        printSubtreeNodes(root,k);
        return 0;
    }
    int l=printNodeAtK(root->left,target,k);
    if(l!=-1)
    {
        if(l+1==k)
        {
            cout<<root->data<<" ";
        }
        else
        {
            printSubtreeNodes(root->right,k-l-2);
        }
        return 1+l;
    }
    int r=printNodeAtK(root->right,target,k);
    if(r!=-1)
    {
        if(r+1==k)
        {
            cout<<root->data<<" ";
        }
        else
        {
            printSubtreeNodes(root->left,k-r-2);
        }
        return 1+r;
    }
    return -1;
}

int main()
{
    Node* root=new Node(0);
    root->left= new Node(1);
    root->right= new Node(2);
    root->left->left= new Node(3);
    root->left->right= new Node(4);
    printNodeAtK(root,root->right,3);
}
