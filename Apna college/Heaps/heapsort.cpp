#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void heapify(vector<int>& v,int n,int i)
{
    int maxIdx=i,l=2*i+1,r=2*i+2;
    if(l<n && v[l]>v[maxIdx])
    {
        maxIdx=l;
    }
    if(r<n && v[r]>v[maxIdx])
    {
        maxIdx=r;
    }
    if(maxIdx!=i)
    {
        swap(v[i],v[maxIdx]);
        heapify(v,n,maxIdx);
    }
}

void heapsort(vector<int>& v)
{
    int n=v.size();
    for(int i=n/2-1;i>=0;i--)             //Traverse from first non leaf node
    {
        heapify(v,n,i);
    }
    for(int i=n-1;i>0;i--)
    {
        swap(v[0],v[i]);
        heapify(v,i,0);
    }
}

int main()
{
    int n;
    cout<<"Enter the number of elements: \n";
    cin>>n;
    vector<int> v(n);
    cout<<"Enter the elements of the array: ";
    for(int i=0;i<n;i++)
    {
        cin>>v[i];
    }
    heapsort(v);
    for(int i=0;i<n;i++)
    {
        cout<<v[i]<<" ";
    }
    cout<<endl;
    return 0;
}