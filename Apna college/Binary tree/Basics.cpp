#include<iostream>
using namespace std;

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

int main()
{
    struct Node* root=new Node(0);
    root->left= new Node(1);
    root->right= new Node(2);
    root->left->left= new Node(3);
    root->left->right= new Node(4);
}
