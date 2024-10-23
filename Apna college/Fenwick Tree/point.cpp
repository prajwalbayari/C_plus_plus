//Range sum with point updates: We have to update a single value

//Updating takes O(log(n)) time

#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int n;
vector<int> arr,Fen;

void update(int idx,int val)
{
    while(idx<=n)
    {
        Fen[idx]+=val;
        idx+=idx&(-idx);
    }
}

int query(int a)
{
    int ans=0;
    while(a>0)
    {
        ans+=Fen[a];
        a-=a&(-a);
    }
    return ans;
}

int main()
{
    int a=1,l,r;
    cout<<"Enter the size of the array: ";
    cin>>n;
    Fen=vector<int>(n+1);
    arr=vector<int>(n+1);
    cout<<"Enter the array elements: ";
    for(int i=1;i<n+1;i++)
    {
        cin>>arr[i];
        update(i,arr[i]);
    }
    while(a)
    {
        cout<<"\n1.Get sum of range\n2.Update a number\n3.Exit\n Enter your choice: ";
        int ch;
        cin>>ch;
        switch(ch)
        {
            case 1:cout<<"Enter range:(Consider 1 based indexing) ";
                    cin>>l>>r;
                    cout<<"Sum of elements in range: "<<query(r)-query(l-1)<<endl;
                    break;
            case 2:cout<<"Enter index and new value: ";
                    cin>>l>>r;
                    update(l,-arr[l]);
                    arr[l]=r;
                    update(l,r);
                    cout<<"Update successfull\n";
                    break;
            case 3:cout<<"Thank you!!!\n\n";
                    a=0;
                    break;
            default:cout<<"Invalid input\n";
        }
    }
    return 0;
}