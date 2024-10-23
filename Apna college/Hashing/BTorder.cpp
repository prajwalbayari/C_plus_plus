//Print vertical order of a binary tree

#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;

class node
{
    public:
    int key;
    node *right=NULL,*left=NULL;
    node(int val)
    {
        key=val;
    }
};

void getOrder(node* root,int h,map<int,vector<int>>& m)
{
    if(root==NULL)
        return;
    m[h].push_back(root->key);
    getOrder(root->right,h+1,m);
    getOrder(root->left,h-1,m);
}

int main()
{
    node* root=new node(10);
    root->left=new node(7);
    root->right=new node(4);
    root->left->left=new node(3);
    root->left->right=new node(11);
    root->right->left=new node(14);
    root->right->right=new node(6);
    map<int ,vector<int>> mp;
    int h=0;
    getOrder(root,h,mp);
    for(auto it=mp.begin();it!=mp.end();it++)
    {
        for(int i=0;i<(it->second).size();i++)
        {
            cout<<it->second[i]<<" ";
        }
    }
    cout<<endl;
    return 0;
}