#include<iostream>
#include<vector>
#include<climits>
using namespace std;

int n;

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

//Build BST from inorder

Node* constructBST(vector<int> preorder,int* preOrderidx,int key,int min,int max)
{
    if(*preOrderidx>=n)
    {
        return NULL;
    }
    Node* root=NULL;
    if(key>min && key<max)
    {
        root=new Node(key);
        *preOrderidx+=1;
        if(*preOrderidx<n)
        {
            root->left=constructBST(preorder,preOrderidx,preorder[*preOrderidx],min,key);
        }
        if(*preOrderidx<n)
        {
            root->right=constructBST(preorder,preOrderidx,preorder[*preOrderidx],key,max);
        }
    }
    return root;
}

void printPreOrder(Node *root)
{
    if(root!=NULL)
    {
        cout<<root->data<<" ";
        printPreOrder(root->left);
        printPreOrder(root->right);
    }
}

int main()
{
    cout<<"Enter the number of nodes in the BST: ";
    cin>>n;
    int m;
    vector<int> preOrder;
    cout<<"Enter the preorder of the BST: ";
    for(int i=0;i<n;i++)
    {
        cin>>m;
        preOrder.push_back(m);
    }
    m=0;
    Node* root=constructBST(preOrder,&m,preOrder[m],INT_MIN,INT_MAX);
    printPreOrder(root);
    return 0;
}