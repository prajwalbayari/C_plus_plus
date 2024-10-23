#include<iostream>
#include<vector>
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

bool getpath(Node* root,int key,vector<int> &path)
{
    if(root==NULL)
    {
        return false;
    }
    path.push_back(root->data);
    if(root->data==key)
    {
        return true;
    }
    if(getpath(root->left,key,path) || getpath(root->right,key,path))
    {
        return true;
    }
    path.pop_back();
    return false;
}

int LCA(Node *root,int n1,int n2)
{
    vector<int> path1,path2;
    if(!getpath(root,n1,path1) || !getpath(root,n2,path2))
    {
        return -1;
    }

    int pc;
    for(pc=0;pc<path1.size()&&pc<path2.size();pc++)
    {
        if(path1[pc]!=path2[pc])
        {
            break;
        }
    }
    return path1[pc-1];
}

Node* LCA2(Node *root,int n1,int n2)
{
    if(root==NULL)
    {
        return NULL;
    }
    if(root->data==n1 || root->data==n2)
    {
        return root;
    }
    Node* l=LCA2(root->left,n1,n2);
    Node* r=LCA2(root->right,n1,n2);
    if(l&&r)
    {
        return root;
    }
    if(l!=NULL)
    {
        return l;
    }
    return r;
}

int main()
{
    Node* root=new Node(0);
    root->left= new Node(1);
    root->right= new Node(2);
    root->left->left= new Node(3);
    root->left->right= new Node(4);
    root->right->left=new Node(5);
    root->right->right=new Node(6);
    root->left->left->left=new Node(7);
    root->left->left->right=new Node(8);
    root->left->right->left=new Node(9);
    root->left->right->right=new Node(10);
    root->right->left->left=new Node(11);
    root->right->left->right=new Node(12);
    root->right->right->left=new Node(13);
    root->right->right->right=new Node(14);
    int l=LCA(root,0,15);
    if(l==-1)
    {
        cout<<"LCA does not exist\n";
    }
    else
    {
        cout<<"LCA is "<<l<<endl;
    }
    Node* lca=LCA2(root,12,14);
    if(lca==NULL)
    {
        cout<<"LCA does not exist\n";
    }
    else
    {
        cout<<"LCA is "<<lca->data<<endl;
    }
    return 0;
}