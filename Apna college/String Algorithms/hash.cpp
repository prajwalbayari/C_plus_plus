//Hashing in strings


//Final time complexity O(nm+ nlog(n))

// #include"bits/stdc++.h"
#include<algorithm>
#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<vector>
#include<string>
using namespace std;

int p=31;
const int N=1e5+3,m=1e9+7;
vector<long long> power(N);

long long calculate(string s)
{
    long long ans=0;
    for(int i=0;i<s.size();i++)
        ans=ans+((s[i]-'a'+1)*power[i])%m;
    return ans;
}

int main()
{
    power[0]=1;
    for(int i=1;i<N;i++)
        power[i]=(power[i-1]*p)%m;
    cout<<"Enter the number of strings\n";
    int n;
    cin>>n;
    vector<string> vec(n);
    cout<<"Enter the strings:\n";
    for(int i=0;i<n;i++)
        cin>>vec[i];
    vector<long long> hashes;

    for(int i=0;i<n;i++)
        hashes.push_back(calculate(vec[i]));
    sort(hashes.begin(),hashes.end());
    int u=1;
    for(int i=1;i<n;i++)
    {
        if(hashes[i]!=hashes[i-1])
            u++;
    }
    cout<<"Number of unique strings is: "<<u<<endl;
}