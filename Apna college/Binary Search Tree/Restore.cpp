#include<iostream>
using namespace std;

struct Node
{
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

void swap(Node* a,Node* b)
{
    int temp=a->data;
    a->data=b->data;
    b->data=temp;
}

void pointers(Node* r,Node* f,Node* m,Node* l,Node* p)
{
    if(r==NULL)
    {
        return;
    }
    pointers(r->left,f,m,l,p);
    if(p!=NULL && r->data<p->data)
    {
        if(f==NULL)
        {
            f=p;
            m=r;
        }
        else
        {
            l=r;
        }
    } 
    p=r;
    pointers(r->right,f,m,l,p);
}

void restore(Node* root)
{
    Node *first=NULL;
    Node *last=NULL;
    Node *mid=NULL;
    Node *prev=NULL;
    pointers(root,first,mid,last,prev);
    if(first!=NULL && last!=NULL)
    {
        cout<<first->data<<" "<<last->data<<endl;
        swap(first,last);
    }
    else if(first!=NULL && mid!=NULL)
    {
        cout<<first->data<<" "<<mid->data<<endl;
        swap(first,mid);
    }
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
    Node* root=new Node(6);
    root->left=new Node(9);
    root->right=new Node(3);
    root->left->left=new Node(-1);
    root->left->right=new Node(4);
    root->right->right=new Node(13);
    inorder(root);
    cout<<endl;
    restore(root);
    inorder(root);
    cout<<endl;
    return 0;
}