//Given an array of size 2*n where first n natural numbers are present twice find an interval for each number such
//that the elements in the interval are present twice between the interval of the number

#include<iostream>
#include<algorithm>
#include<limits.h>
#include<vector>
using namespace std;

vector<int> Tree; 

struct triplet
{
    int l,r,idx;
};

bool compare(triplet t1,triplet t2)
{
    return t1.r<t2.r;
}

int find(int node,int start,int end,int l,int r)
{
    if(start>=l && end<=r)
        return Tree[node];

    if(start>r || end<l)
        return 0;
    
    int mid=(start+end)/2;
    return find(2*node,start,mid,l,r)+find(2*node+1,mid+1,end,l,r);
}

void update(int node,int start,int end,int val,int pos)
{
    if(start==end)
    {
        Tree[node]=val;
        return;
    }
    if(pos<start || pos>end)
        return;

    int mid=(start+end)/2;

    if(pos<=mid)
        update(2*node,start,mid,val,pos);
    else    
        update(2*node+1,mid+1,end,val,pos);
    
    Tree[node]=Tree[node*2]+Tree[node*2+1];
}

int main()
{
    int n;
    cout<<"Enter the size of the array: ";
    cin>>n;
    triplet t1;
    t1.l=-1,t1.r=-1,t1.idx=-1;
    vector<triplet> t(n/2,t1);
    Tree=vector<int>(2*n);
    cout<<"Enter array elements: ";
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        if(t[x-1].l==-1)
            t[x-1].l=i;
        else
            t[x-1].r=i;
        t[x-1].idx=x;
    }

    sort(t.begin(),t.end(),compare);

    vector<int> ans(n/2,0);

    for(int i=0;i<n/2;i++)
    {
        ans[t[i].idx-1]=find(1,0,n-1,t[i].l,t[i].r);    
        update(1,0,n-1,1,t[i].l);
    }
    cout<<"Number of elements in interval is: ";
    for(int i=0;i<n/2;i++)
        cout<<ans[i]<<" ";
    cout<<endl;
}