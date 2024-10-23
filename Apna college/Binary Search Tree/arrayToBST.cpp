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

Node* arrayToBST(vector<int> v,int s,int e)
{
    if(s>e)
    {
        return NULL;
    }
    int m=(s+e)/2;
    Node *root=new Node(v[m]);
    root->left=arrayToBST(v,s,m-1);
    root->right=arrayToBST(v,m+1,e);
    return root;
}

void preorder(Node *root)
{
    if(root!=NULL)
    {
        cout<<root->data<<" ";
        preorder(root->left);
        preorder(root->right);
    }
}

int main()
{
    vector<int> v;
    int m,n;
    cout<<"Enter the size of the sorted array: ";
    cin>>n;
    cout<<"Enter array elements in sorted order: ";
    for(int i=0;i<n;i++)
    {
        cin>>m;v.push_back(m);
    }
    Node *root=arrayToBST(v,0,n-1);
    preorder(root);
    cout<<endl;
    return 0;
}