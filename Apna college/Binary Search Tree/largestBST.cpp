#include<iostream>
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

struct Info
{
    int size;
    int mi;
    int ma;
    int ans;
    bool isBST;
};

Info BSTinBT(Node* root)
{
    if(root==NULL)
    {
        return {0,INT_MAX,INT_MIN,0,true};
    }
    if(root->left==NULL && root->right==NULL)
    {
        return {1,root->data,root->data,1,true};
    }

    Info left=BSTinBT(root->left);
    Info right=BSTinBT(root->right);

    Info curr;
    curr.size=(1+left.size+right.size);

    if(left.isBST && right.isBST && root->data<right.mi && root->data>left.ma)
    {
        curr.isBST=true;
        curr.mi=min(left.mi, min(right.mi,root->data));
        curr.ma=max(left.ma, max(right.ma,root->data));
        curr.ans=curr.size;
        return curr;
    }
    curr.ans=max(left.ans,right.ans);
    curr.isBST=false;
    return curr;
}

int main()
{
    Node* root=new Node(15);
    root->left=new Node(10);
    root->left->left=new Node(5);
    root->right=new Node(20);

    cout<<"Size of largest Binary search Tree in Binary Tree is: "<<BSTinBT(root).ans<<endl;
    return 0;
}