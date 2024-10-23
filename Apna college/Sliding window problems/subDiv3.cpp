// Form a subarray so that we can form a number using this subarray we can form a number divisible by 3

#include<iostream>
#include<vector>
using namespace std;

void findSubarray(vector<int> v,int k)
{
    int sum=0;
    bool f=false;
    pair<int,int> ans;

    for(int i=0;i<k;i++)
    {
        sum+=v[i];
    }
    if(sum%3==0)
    {
        ans=make_pair(0,k);
        f=true;
    }

    for(int i=k;i<v.size();i++)
    {
        sum+=v[i]-v[i-k];
        if(sum%3==0)
        {
            ans=make_pair(i-k+1,i);
            f=true;
        }
    }
    if(!f)
    {
        cout<<"No subarray found to satisfy given condition\n";
    }
    else
    {
        cout<<"Subarray found the number formed is: ";
        for(int i=ans.first;i<=ans.second;i++)
        {
            cout<<v[i];
        }
        cout<<endl;
    }
}

int main()
{
    vector<int> v={10,23,56,7,8,9,10};
    findSubarray(v,5);
    return 0;
}