#include<iostream>
using namespace std;

//O(logn)

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

Node* searchInBST(Node *root,int key)
{
    if(root==NULL)
    {
        return NULL;
    }
    if(root->data>key)
    {
        return searchInBST(root->left,key);
    }
    if(root->data<key)
    {
        return searchInBST(root->right,key);
    }
    return root;
}

//Delete in BST

Node* inordersuc(Node* root)
{
    Node *cur=root;
    while(cur && cur->left!=NULL)
    {
        cur=cur->left;
    }
    return cur;
}

Node* deleteinBST(Node * root,int key)
{
    if(key<root->data)
    {
        root->left=deleteinBST(root->left,key);
    }
    else if(key>root->data)
    {
        root->right=deleteinBST(root->right,key);
    }
    else
    {
        if(root->left==NULL)
        {
            Node *temp=root->right;
            free(root);
            return temp;
        }
        else if(root->right==NULL)
        {
            Node *temp=root->left;
            free(root);
            return temp;
        }
        Node *temp=inordersuc(root->right);
        root->data=temp->data;
        root->right=deleteinBST(root->right,temp->data);
    }
    return root;
}

void inorder(Node* root)
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
    Node *root=new Node(4);
    root->left=new Node(2);
    root->right=new Node(6);
    root->left->left=new Node(1);
    root->left->right=new Node(3);
    root->right->left=new Node(5);
    root->right->right=new Node(7);
    // if(searchInBST(root,8)==NULL)
    // {
    //     printf("Key not found\n");
    // }
    // else
    // {
    //     printf("Key found\n");
    // }
    // return 0;
    inorder(root);
    root=deleteinBST(root,2);
    cout<<endl;
    inorder(root);
    cout<<endl;
    return 0;
}