#include<iostream>
#include<vector>
using namespace std;


//Using preorder and inorder


// struct Node
// {
//     int data;
//     struct Node* left;
//     struct Node* right;

//     Node(int val)
//     {
//         data=val;
//         left=NULL;
//         right=NULL;
//     }
// };

// int search(vector<int> inorder,int start,int end,int cur)
// {
//     for(int i=start;i<=end;i++)
//     {
//         if(inorder[i]==cur)
//         {
//             return i;
//         }
//     }
//     return -1;
// }

// Node* buildTree(vector<int> preorder,vector<int> inorder,int start,int end)
// {
//     static int idx=0;
//     if(start>end)
//     {
//         return NULL;
//     }
//     int cur=preorder[idx++];
//     Node* node=new Node(cur);
//     if(start==end)
//     {
//         return node;
//     }
//     int pos=search(inorder,start,end,cur);
//     node->left=buildTree(preorder,inorder,start,pos-1);
//     node->right=buildTree(preorder,inorder,pos+1,end);
//     return node;
// }

// void inorderPrint(Node* root)
// {
//     if(root==NULL)
//     {
//         return;
//     }
//     inorderPrint(root->left);
//     cout<<root->data<<" ";
//     inorderPrint(root->right);
// }

// int main()
// {
//     vector<int> preorder;
//     vector<int> inorder;
//     int n,m;
//     cout<<"Enter the number of elements: ";
//     cin>>n;
//     cout<<"Enter the preorder array: ";
//     for(int i=0;i<n;i++)
//     {
//         cin>>m;
//         preorder.push_back(m);
//     }
//     cout<<"Enter the inorder array: ";
//     for(int i=0;i<n;i++)
//     {
//         cin>>m;
//         inorder.push_back(m);
//     }
//     Node* root=buildTree(preorder,inorder,0,n-1);
//     inorderPrint(root);
// }

//Using postorder and inorder

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

int search(vector<int> inorder,int start,int end,int cur)
{
    for(int i=start;i<=end;i++)
    {
        if(inorder[i]==cur)
        {
            return i;
        }
    }
    return -1;
}

Node* BuildTree(vector<int> postorder,vector<int> inorder,int s,int e)
{
    static int idx=postorder.size()-1;
    if(s>e)
    {
        return NULL;
    }
    int val=postorder[idx--];
    Node* curr=new Node(val);
    if(s==e)
    {
        return curr;
    }
    int i=search(inorder,s,e,val);
    curr->right=BuildTree(postorder,inorder,i+1,e);
    curr->left=BuildTree(postorder,inorder,s,i-1);
    return curr;
}

void inorderPrint(Node* root)
{
    if(root==NULL)
    {
        return;
    }
    inorderPrint(root->left);
    cout<<root->data<<" ";
    inorderPrint(root->right);
}

int main()
{
    vector<int> postorder,inorder;
    int n,m;
    cout<<"Enter the number of nodes in the tree: ";
    cin>>n;
    cout<<"Enter the postorder sequence: ";
    for(int i=0;i<n;i++)
    {
        cin>>m;
        postorder.push_back(m);
    }
    printf("Enter the inorder sequence: ");
    for(int i=0;i<n;i++)
    {
        cin>>m;
        inorder.push_back(m);
    }
    Node* root=BuildTree(postorder,inorder,0,n-1);
    inorderPrint(root); 
}