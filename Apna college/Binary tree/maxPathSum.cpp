#include<iostream>
#include<stdlib.h>
#include<climits>
using namespace std;

struct Node
{
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

int maxPathSumUtil(Node* root,int &ans)
{
    if(root==NULL)
    {
        return 0;
    }
    int l=maxPathSumUtil(root->left,ans);
    int r=maxPathSumUtil(root->right,ans);
    int nodeMax=max(max(root->data,root->data+l+r),max(root->data+l,root->data+r));
    ans=max(ans,nodeMax);
    int singlePathSum=max(root->data,max(root->data+l,root->data+r));
    return singlePathSum;
}

int maxPathSum(Node *root)
{
    int ans=INT_MIN;
    maxPathSumUtil(root,ans);
    return ans;
}

int main()
{
    struct Node* root=new Node(1);
    root->left= new Node(12);
    root->right= new Node(3);
    root->left->left= new Node(4);
    root->right->left= new Node(5);
    root->right->right= new Node(6);
    cout<<maxPathSum(root);
}