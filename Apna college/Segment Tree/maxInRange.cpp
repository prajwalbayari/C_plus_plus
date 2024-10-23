//Find maximum element in a range of an array

#include<iostream>
#include<algorithm>
#include<vector>
#include<limits.h>
using namespace std;

vector<int> tree;

void construct(int index,int start,int end,vector<int> v)
{
    if(start==end)
    {
        tree[index]=v[start];
        return;
    }
    int mid=(start+end)/2;
    construct(index*2,start,mid,v);
    construct(index*2+1,mid+1,end,v);

    tree[index]=max(tree[index*2],tree[index*2+1]);

    return;
}

int find(int node,int start,int end,int l,int r)
{
    if(start>=l && end<=r)
        return tree[node];

    if(start>r || end<l)
        return INT_MIN;
    
    int mid=(start+end)/2;
    return max(find(2*node,start,mid,l,r),find(2*node+1,mid+1,end,l,r));
}

void update(int node,int start,int end,int val,int pos)
{
    if(start==end)
    {
        tree[node]=val;
        return;
    }
    if(pos<start || pos>end)
        return;

    int mid=(start+end)/2;

    if(pos<=mid)
        update(2*node,start,mid,val,pos);
    else    
        update(2*node+1,mid+1,end,val,pos);
    
    tree[node]=max(val,tree[node]);
    return;
}

int main()
{
    int n,ch=0;
    cout<<"Enter the number of elements: ";
    cin>>n;
    cout<<"Enter array elements: ";
    vector<int> vec(n);
    for(int i=0;i<n;i++)
        cin>>vec[i];
    tree=vector<int>(4*n);
    construct(1,0,n-1,vec);

    while(ch!=5)
    {
        cout<<"\n1.Show tree\n2.Update element\n3.Find maximum\n4.Show array\n5.Exit\nEnter your choice: ";
        cin>>ch;
        switch(ch)
        {
            case 1:cout<<"Tree values: ";
                    for(int i=1;i<2*n;i++)
                        cout<<tree[i]<<" ";
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
                    cout<<"Maximum in range is: "<<find(1,0,n-1,left,right)<<endl;
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