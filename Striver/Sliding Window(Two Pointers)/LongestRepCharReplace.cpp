// Given an integer k and a string s, any character in the string can be selected and changed to any other uppercase English character. This operation can be performed up to k times. After completing these steps, return the length of the longest substring that contains the same letter.

#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
using namespace std;

int main(){
    string str;
    cout<<"Enter the string: ";
    cin>>str;
    int k;
    cout<<"Enter the value of k: ";
    cin>>k;

    int maxAns=0,r=0,l=0,maxF=0;
    unordered_map<char,int> mp;
    while(r<str.size()){
        mp[str[r]]++;
        maxF=max(maxF,mp[str[r]]);
        if(r-l-maxF+1<=k)
            maxAns=max(maxAns,r-l+1);
        else{
            mp[str[l]]--;
            if(mp[str[l]]==0)
                mp.erase(str[l]);
            l++;
        }
        r++;
    }

    cout<<"The length of the substring is: "<<maxAns<<endl;
}

// Time complexity: O(n)
// Space complexity: O(26)