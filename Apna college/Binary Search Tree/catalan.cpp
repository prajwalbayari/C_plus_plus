#include<iostream>
#include<vector>
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

int catalan(int n)
{
    if(n<=1)
    {
        return 1;
    }
    int res=0;
    for(int i=0;i<=n-1;i++)
    {
        res+=catalan(i)*catalan(n-i-1);
    }
    return res;
}

//Total possible BSTs

vector<Node*> constructTrees(int s,int e)
{
    vector<Node*> trees;
    if(s>e)
    {
        trees.push_back(NULL);
        return trees;
    }
    for(int i=s;i<=e;i++)
    {
        vector<Node*> leftSubtree=constructTrees(s,i-1);
        vector<Node*> rightSubtree=constructTrees(i+1,e);
        for(int j=0;j<leftSubtree.size();j++)
        {
            Node* left=leftSubtree[j];
            for(int k=0;k<rightSubtree.size();k++)
            {
                Node* right=rightSubtree[k];
                Node* node=new Node(i);
                node->left=left;
                node->right=right;
                trees.push_back(node);
            }
        }
    }
    return trees;
}

void preorder(Node* root)
{
    if(root!=NULL)
    {
        cout<<root->data<<" ";
        preorder(root->left);
        preorder(root->right);
    }
}

// int main()
// {
//     cout<<"Enter the limit: ";
//     int n;
//     cin>>n;
//     cout<<"The catalan series is: ";
//     for(int i=0;i<=n-1;i++)
//     {
//         cout<<catalan(i)<<" ";
//     }
//     cout<<endl;
//     return 0;
// }

int main()
{
    int e,s;
    cout<<"Enter the stareting and ending point: ";
    cin>>s>>e;
    vector<Node*> totalTrees=constructTrees(s,e);
    for(int i=0;i<totalTrees.size();i++)
    {
        cout<<i+1<<" : ";
        preorder(totalTrees[i]);
        cout<<endl;
    }
    return 0;
}