//Given an binary array of size n that contains only 0's and 1's we have 2 operations
//(i) Given an index change the bit of that idex (0 to 1 or 1 to 0)
//(ii) Find the ith 1 bit in the binary array (The i will be valid all the time)

#include<iostream>
#include<algorithm>
#include<limits.h>
#include<vector>
using namespace std;

vector<int> Tree;

void build(int Node,int start,int end,vector<int> v)
{
    if(start==end)
    {
        Tree[Node]=v[start];
        return;
    }

    int mid=(start+end)/2;
    build(2*Node,start,mid,v);
    build(2*Node+1,mid+1,end,v);

    Tree[Node]=Tree[Node*2]+Tree[Node*2+1];
}

void update(int Node,int start,int end,int idx)
{
    if(start==end)
    {
        Tree[Node]^=1;
        return;
    }
    int mid=(end+start)/2;
    if(idx<=mid)
        update(2*Node,start,mid,idx);
    else
        update(2*Node+1,mid+1,end,idx);
    Tree[Node]=Tree[Node*2]+Tree[Node*2+1];
}

int query(int Node,int start,int end,int k)
{
    if(start==end)
        return start;
    int mid=(start+end)/2;
    if(k<=Tree[2*Node])
        return query(2*Node,start,mid,k);
    else 
        return query(2*Node+1,mid+1,end,k); 
}

int main()
{
    int n,ch;
    cout<<"Enter the size of the array: ";
    cin>>n;
    vector<int> arr(n);
    cout<<"Enter the binary array: ";
    for(int i=0;i<n;i++)
        cin>>arr[i];
    Tree=vector<int>(4*n);
    build(1,0,n-1,arr);

    while(ch!=5)
    {
        cout<<"\n1.Show Tree \n2.Update element\n3.Find occurence\n4.Show array\n5.Exit\nEnter your choice: ";
        cin>>ch;
        switch(ch)
        {
            case 1:cout<<"Tree values: ";
                    for(int i=1;i<2*n;i++)
                        cout<<Tree[i]<<" ";
                    cout<<endl;
                    break;
            case 2:int idx;
                    cout<<"Enter a valid index: ";
                    cin>>idx;
                    update(1,0,n-1,idx);
                    arr[idx]^=1;
                    cout<<"Value updated successfully\n";
                    break;
            case 3:int k;
                    cout<<"Enter the occurence number: ";
                    cin>>k;
                    cout<<"Index of "<<k<<"th occurence of 1 is in index: "<<query(1,0,n-1,k)<<endl;
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