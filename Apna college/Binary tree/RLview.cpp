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

void rview(Node *root)
{
    if(root==NULL)
    {
        return;
    }
    queue<Node*> q;
    q.push(root);
    while(!q.empty())
    {
        int n=q.size();
        for(int i=0;i<n;i++)
        {
            Node* cur=q.front();
            if(i==n-1)
            {
                cout<<cur->data<<" ";
            }
            q.pop();
            if(cur->left!=NULL)
            {
                q.push(cur->left);
            }
            if(cur->right!=NULL)
            {
                q.push(cur->right);
            }
        }
    }
}

void lview(Node *root)
{
    if(root==NULL)
    {
        return;
    }
    queue<Node*> q;
    q.push(root);
    while(!q.empty())
    {
        int n=q.size();
        for(int i=0;i<n;i++)
        {
            Node* cur=q.front();
            if(i==0)
            {
                cout<<cur->data<<" ";
            }
            q.pop();
            if(cur->left!=NULL)
            {
                q.push(cur->left);
            }
            if(cur->right!=NULL)
            {
                q.push(cur->right);
            }
        }
    }
}


int main()
{
    Node *root=new Node(1);
    root->left=new Node(2);
    root->right=new Node(3);
    root->left->left=new Node(4);
    root->right->right=new Node(5);
    cout<<"Left view of the binary tree is: ";
    lview(root);
    cout<<endl;
    cout<<"Right view of the binary tree is: ";
    rview(root);
    cout<<endl;
}