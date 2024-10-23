//It gives the number of pairs of inices in an array such that i<j and arr[i]>arr[j]

//Time comlexity= O(nlog(n))

#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

vector<int> fen;

void update(int n,int idx,int val)
{
    while(idx<=n)
    {
        fen[idx]+=val;
        idx+=(idx&(-idx));
    }
}

int getSum(int idx)
{
    int ans=0;
    while(idx>0)
    {
        ans+=fen[idx];
        idx-=idx&(-idx);
    }
    return ans;
}

int main()
{
    int n;
    cout<<"Enter the number of elements: ";
    cin>>n;
    cout<<"Enter the number of elements: ";
    vector<int> arr(n);
    for(int i=0;i<n;i++)
        cin>>arr[i];
    vector<int> temp=arr;
    sort(temp.begin(),temp.end());
    for(int i=0;i<n;i++)
        arr[i]=lower_bound(temp.begin(),temp.end(),arr[i])-temp.begin()+1;
    fen=vector<int>(n+1);
    int inv=0;
    for(int i=n-1;i>=0;i--)
    {
        inv+=getSum(arr[i]-1);
        update(n,arr[i],1);
    }
    cout<<"The total number of count inversions in the array is: "<<inv<<endl;
}