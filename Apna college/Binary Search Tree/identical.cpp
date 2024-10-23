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

bool isIdentical(Node* root1,Node* root2)
{
    if(root1==NULL && root2==NULL)
    {
        return true;
    }
    else if(root1==NULL || root2==NULL)
    {
        return false;
    }
    else
    {    
        bool a=isIdentical(root1->left,root2->left);
        bool b=isIdentical(root1->right,root2->right);
        bool c=root1->data==root2->data;
        if(a && b && c)
        {
            return true;
        }
        return false;
    }
}

int main()
{
    Node* root1=new Node(3);
    root1->left=new Node(2);
    root1->right=new Node(4);
    root1->right->right=new Node(8);
    Node* root2=new Node(2);
    root2->left=new Node(1);
    root2->right=new Node(4);
    root2->left->left=new Node(0);
    if(isIdentical(root1,root2)==true)
    {
        cout<<"Trees are identical\n";
    }
    else
    {
        cout<<"Trees are not identical\n";
    }
    return 0;
}