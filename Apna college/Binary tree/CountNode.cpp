#include<iostream>
#include<stdlib.h>
#include<algorithm>
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

//Count the number of nodes in a binary tree

int count(Node* root)
{
    if(root==NULL)
    {
        return 0;
    }
    return 1+count(root->left)+count(root->right);
}

//Calculate sum of all nodes in the binary tree

int sum(Node* root)
{
    if(root==NULL)
    {
        return 0;
    }
    return root->data+sum(root->left)+sum(root->right);
}

//Calculate height of the binary tree

int height(Node* root)
{
    if(root==NULL)
    {
        return 0;
    }
    // int m=height(root->left);
    // int n=height(root->right);
    // return 1+(m>n? m:n);

    return 1+max(height(root->left),height(root->right));
}

//Calculate maximum diameter of the binary tree

int dia(Node *root)
{
    if(root==NULL)
    {
        return 0;
    }
    // int lh=height(root->left);
    // int rh=height(root->right);
    // int cd=lh+rh+1;
    // int ld=dia(root->left);
    // int rd=dia(root->right);
    // return max(cd,max(ld,rd));
    return max(height(root->left)+height(root->right)+1,max(dia(root->left),dia(root->right)));
}

//Optimized

int dia(Node* root,int* height)
{
    if(root==NULL)
    {
        *height=0;
        return 0;
    }
    int lh=0,rh=0;
    int ld=dia(root->left,&lh);
    int rd=dia(root->right,&rh);
    int cd=lh+rh+1;
    *height=max(lh,rh)+1;
    return max(cd,max(ld,rd));
}

int main()
{
    Node* root=new Node(1);
    root->left= new Node(2);
    root->right= new Node(3);
    root->left->left= new Node(4);
    root->left->right= new Node(5);
    root->right->left= new Node(6);
    root->right->right= new Node(7);
    root->left->left->left=new Node(8);
    root->left->left->right=new Node(9);
    root->left->left->left->left=new Node(10);
    root->left->left->left->left->left=new Node(11);
    cout<<"Number of nodes in the binary tree is: "<<count(root)<<endl;
    cout<<"Sum of all the nodes in the tree is: "<<sum(root)<<endl; 
    cout<<"Height of the tree is: "<<height(root)<<endl;
    cout<<"Maximum diameter of the tree is: "<<dia(root);
}