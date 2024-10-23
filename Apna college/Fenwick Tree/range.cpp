//Range sum with range updates: We have to update all values in the range of given indices

#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int query(int ind,vector<int> fen,int n)
{
    int ans=0;
    while(ind>0)
    {
        ans+=fen[ind];
        ind-=(ind&(-ind));
    }
    return ans;
}

void update(vector<int>& fen,int i,int n,int val)
{
    while(i<=n)
    {
        fen[i]+=val;
        i+=(i&(-i));
    }
}

int main()
{
    int test;
    cout<<"Enter the number of testcases: ";
    cin>>test;
    while(test--)
    {
        int n,u,s;
        cout<<"\nEnter the number of elements: ";
        cin>>n;
        vector<int> fen(n+1);
        cout<<"Enter the number of update queries: ";
        cin>>u;
        while(u--)
        {
            int l,r,val;
            cout<<"\nEnter the range(1 to "<<n<<") and value: ";
            cin>>l>>r>>val;
            update(fen,l,n,val);
            update(fen,r+1,n,-val);
        }
        cout<<"\n\nEnter the number of sum queries: ";
        cin>>s;
        while(s--)
        {
            int w;
            cout<<"Enter the index(1 to "<<n<<"): ";
            cin>>w;
            cout<<"The sum is: "<<query(w,fen,n)<<endl;
        }
    }
}