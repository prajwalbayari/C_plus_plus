//Given an array of n elements find the least index j suxh that arr[j]>=m where m is given by user

#include<iostream>
#include<algorithm>
#include<limits.h>
#include<vector>
using namespace std;

vector<int> Tree;

void build(int Node,int start,int end,vector<int> vec)
{
    if(start==end)
    {
        Tree[Node]=vec[start];
        return;
    }

    int mid=(start+end)/2;
    build(Node*2,start,mid,vec);
    build(Node*2+1,mid+1,end,vec);

    Tree[Node]=max(Tree[2*Node],Tree[2*Node+1]);
}

int find(int node,int start,int end,int l,int r)
{
    if(start>=l && end<=r)
        return Tree[node];

    if(start>r || end<l)
        return INT_MIN;
    
    int mid=(start+end)/2;
    return max(find(2*node,start,mid,l,r),find(2*node+1,mid+1,end,l,r));
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
    
    Tree[node]=max(Tree[node*2],Tree[node*2+1]);
}

int main()
{
    int n,ch;
    cout<<"Enter the number of elements in the array: ";
    cin>>n;
    vector<int> arr(n);
    Tree=vector<int>(4*n);
    cout<<"Enter the array elements: ";
    for(int i=0;i<n;i++)
        cin>>arr[i];
    build(1,0,n-1,arr);

    while(ch!=5)
    {
        int ans=n,low=0,high=n-1,val,idx;
        cout<<"\n1.Show Tree\n2.Update element\n3.Find index\n4.Show array\n5.Exit\nEnter your choice: ";
        cin>>ch;
        switch(ch)
        {
            case 1:cout<<"Tree values: ";
                    for(int i=1;i<2*n;i++)
                        cout<<Tree[i]<<" ";
                    cout<<endl;
                    break;
            case 2:cout<<"Enter a valid index and new value: ";
                    cin>>idx>>val;
                    update(1,0,n-1,val,idx);
                    arr[idx]=val;
                    cout<<"Value updated successfully\n";
                    break;
            case 3:ans=n;
                    cout<<"Enter the number: ";
                    cin>>val;
                    while(low<=high)
                    {
                        int mid=(low+high)/2;
                        if(find(1,0,n-1,low,mid)<val)
                            low=mid+1;
                        else
                        {
                            high=mid-1;
                            ans=min(ans,mid);
                        }
                    }
                    if(ans==n)
                        cout<<"No such element found\n";
                    else
                        cout<<"Element found at index "<<ans<<endl;
                    break;
            case 4:cout<<"Array elements: ";
                    for(int i=0;i<n;i++)
                        cout<<arr[i]<<" ";
                    cout<<endl;
                    break; 
            case 5:cout<<"Thank you\n\n";
                    break;
            default:cout<<"Invalid input!!!\n";
                    break;
        }
    }
}