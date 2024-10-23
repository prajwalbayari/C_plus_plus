#include<iostream>
#include<string>
#include<vector>
#include<stdio.h>
#include<algorithm>
using namespace std;

int p=31;
const int N=1e5+3,m=1e9+7;
vector<long long> powers(N);

int main()
{
    string text,pattern;
    cout<<"Enter the text\n";
    getline(cin,text);

    cout<<"Enter the pattern\n";
    getline(cin,pattern);

    int T=text.size(),S=pattern.size();
    powers[0]=1;
    for(int i=1;i<N;i++)
        powers[i]=(powers[i-1]*p)%m;

    vector<long long> hash(T+1,0);
    for(int i=0;i<T;i++)
        hash[i+1]=(hash[i]+(text[i]-'a'+1)*powers[i])%m;
        
    long long hash_s=0;
    for(int i=0;i<S;i++)
        hash_s=(hash_s+(pattern[i]-'a'+1)*powers[i])%m;

    for(int i=0;i+S-1<T;i++)
    {
        long long cur_hash=(hash[i+S]-hash[i]+m)%m;
        if(cur_hash==(hash_s*powers[i])%m)
            cout<<"Found at index "<<i<<endl;
    }
}