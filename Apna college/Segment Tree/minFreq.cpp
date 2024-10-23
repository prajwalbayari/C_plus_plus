//Given an array of n elements find the minimum value in a range and its frequency in a raange

#include<iostream>
#include<algorithm>
#include<vector>
#include<limits.h>
// #include<utility>
using namespace std;

vector<pair<int,int>> tree;

void construct(int index,int start,int end,vector<int> v)
{
    if(start==end)
    {
        tree[index].first=v[start];
        tree[index].second=1;
        return;
    }
    int mid=(start+end)/2;
    construct(index*2,start,mid,v);
    construct(index*2+1,mid+1,end,v);
    if(tree[index*2].first<tree[2*index+1].first)
    {
        tree[index].first=tree[index*2].first;
        tree[index].second=tree[index*2].second;
    }
    else if(tree[index*2+1].first<tree[2*index].first)
    {
        tree[index].first=tree[index*2+1].first;
        tree[index].second=tree[index*2+1].second;
    }
    else
    {
        tree[index].first=tree[2*index].first;
        tree[index].second=tree[2*index].second+tree[2*index+1].second;
    }
}

pair<int,int> find(int node,int start,int end,int l,int r)
{
    if(start>=l && end<=r)
        return tree[node];

    if(start>r || end<l)
        return make_pair(INT_MAX,-1);
    
    int mid=(start+end)/2;
    pair<int,int> f1=find(2*node,start,mid,l,r),f2=find(2*node+1,mid+1,end,l,r);
    if(f1.first<f2.first)   
        return f1;
    else if(f2.first<f1.first)
        return f2;
    return {f1.first,f1.second+f2.second};
}

void update(int node,int start,int end,int val,int pos)
{
    if(start==end)
    {
        tree[node].first=val;
        tree[node].second=1;
        return;
    }
    if(pos<start || pos>end)
        return;

    int mid=(start+end)/2;

    if(pos<=mid)
        update(2*node,start,mid,val,pos);
    else    
        update(2*node+1,mid+1,end,val,pos);

    if(tree[node*2].first<tree[2*node+1].first)
    {
        tree[node].first=tree[node*2].first;
        tree[node].second=tree[node*2].second;
    }
    else if(tree[node*2+1].first<tree[2*node].first)
    {
        tree[node].first=tree[node*2+1].first;
        tree[node].second=tree[node*2+1].second;
    }
    else
    {
        tree[node].first=tree[2*node].first;
        tree[node].second=tree[2*node].second+tree[2*node+1].second;
    }
}

int main()
{
    int n,ch=0;
    cout<<"Enter the number of elements: ";
    cin>>n;
    cout<<"Enter array elements: ";
    vector<int> vec(n);
    pair<int,int> ans;
    for(int i=0;i<n;i++)
        cin>>vec[i];
    tree=vector<pair<int,int>>(4*n);
    construct(1,0,n-1,vec);

    while(ch!=5)
    {
        cout<<"\n1.Show tree\n2.Update element\n3.Find minimum and it's frequency\n4.Show array\n5.Exit\nEnter your choice: ";
        cin>>ch;
        switch(ch)
        {
            case 1:cout<<"Tree values: ";
                    for(int i=1;i<2*n;i++)
                        cout<<tree[i].first<<" ";
                    cout<<endl;
                    break;
            case 2:int val,idx;
                    cout<<"Enter a valid index and new value: ";
                    cin>>idx>>val;
                    update(1,0,n-1,val,idx);
                    vec[idx]=val;
                    cout<<"Value updated successfully\n";
                    break;
            case 3:int left,right;
                    cout<<"Enter a valid range (0 to "<<n-1<<") : ";
                    cin>>left>>right;
                    ans=find(1,0,n-1,left,right);
                    cout<<"Minimum in the range is: "<<ans.first<<" with a frequency "<<ans.second<<endl;
                    break;
            case 4:cout<<"Array elements: ";
                    for(int i=0;i<n;i++)
                        cout<<vec[i]<<" ";
                    cout<<endl;
                    break; 
            case 5:cout<<"Thank you\n\n";
                    break;
            default:cout<<"Invalid input!!!\n";
                    break;
        }
    }
}