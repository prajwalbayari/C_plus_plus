#include<vector>
#include<iostream>
#include<algorithm>
#include<stdlib.h>
using namespace std;

class Trie
{
    public:
    Trie* next[2];
    Trie()
    {
        next[0]=NULL;   
        next[1]=NULL;
    }
};

Trie* build(vector<int>& a)
{
    int n=a.size();
    Trie* root=new Trie();
    for(int i=0;i<n;i++)
    {
        int num=a[i];
        Trie* T=root;
        for(int j=31;j>=0;j--)
        {
            int b=(num>>j)&1;
            if(T->next[b]==NULL)
                T->next[b]=new Trie();
            T=T->next[b];
        }
    }
    return root;
}

int find_max(Trie* root,vector<int>& a)
{
    int res=0;
    for(int i=0;i<a.size();i++)
    {
        int num=a[i],cur_max=0;
        Trie* cur=root;
        for(int j=31;j>=0;j--)
        {
            int b=((num>>j)&1)? 0:1;
            if(cur->next[b])
            {
                cur_max<<=1;
                cur_max|=1;
                cur=cur->next[b];
            }
            else
            {
                cur_max<<=1;
                cur_max|=0;
                cur=cur->next[b^1];
            }
        }
        res=max(res,cur_max);
    }
    return res;
}

int main()
{
    int n;
    cout<<"Enter the size of the array: ";
    cin>>n;
    vector<int> v(n);
    cout<<"Enter the array elements:\n";
    for(int i=0;i<n;i++)
        cin>>v[i];
    Trie* T=build(v);
    cout<<"Maximum XOR of the array is: "<<find_max(T,v)<<endl;
}