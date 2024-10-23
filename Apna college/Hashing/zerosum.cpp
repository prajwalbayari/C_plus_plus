//Count all the subarray with sum zero 

#include<iostream>
#include<vector>
#include<map>
using namespace std;

int main()
{
    int n,pref=0,c=0;
    cout<<"Enter the size of the array: ";
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++)
        cin>>v[i];
    map<int,int> mp;
    for(int i=0;i<n;i++)
    {
        pref+=v[i];
        mp[pref]++;
    }
    for(auto it=mp.begin();it!=mp.end();it++)
    {
        int a=it->second;
        c+=(a*(a-1))/2;
        if(it->first==0)
            c+=a;
    }
    cout<<"Number of subarrays whose sum is zero is: "<<c<<endl;
    return 0;
}