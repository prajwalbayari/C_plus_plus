// Given two strings s and t. Find the smallest window substring of s that includes all characters in t (including duplicates) , in the window. Return the empty string "" if no such substring exists.

#include<iostream>
#include<string>
#include<unordered_map>
using namespace std;

int main(){
    string s,t;
    cout<<"Enter the string s: ";
    cin>>s;
    cout<<"Enter the string t: ";
    cin>>t;
    unordered_map<char,int> mp;
    for(char c:t)
        mp[c]++;
    
    int l=0,r=0,cnt=0,idx=-1,minLen=1e9;
    while(r<s.size()){
        if(mp[s[r]]>0)
            cnt++;
        mp[s[r]]--;
        while(cnt==t.size()){
            if(minLen>r-l+1){
                minLen=r-l+1;
                idx=l;
            }
            mp[s[l]]++;
            if(mp[s[l]]>0)
                cnt--;
            l++;
        }
        r++;
    }
    if(idx==-1)
        cout<<"No substrings found!\n";
    else 
        cout<<"Minimum window substring is: "<<s.substr(idx,minLen)<<endl;
}   

// Time complexity: O(2*n+m)
// Space complexity: O(256)