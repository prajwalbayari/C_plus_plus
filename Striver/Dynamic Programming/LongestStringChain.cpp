// Problem Statement: We are given an array of strings (sat words[ ]), and we need to return the longest string chain. This longest string chain is defined as:

// A subsequence of words[ ] of the string.
// Every element of this subsequence ( a string) except the first one can be formed by inserting a single character into the previous element.
// The first element of this subsequence can be any string from the words[ ] array

#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

bool compare(string s1,string s2){
    int j=0,m=s1.size(),n=s2.size(),temp=0;
    if(m+1!=n)
        return false;
    for(int i=0;i<n && j<m;i++){
        if(s1[j]!=s2[i]){
            if(temp)
                return false;
            temp++;
        }else
            j++;
    }
    return true;
}

bool comp(string& s1,string& s2){
    return s1.size()<s2.size();
}

int chain(vector<string>& arr){
    int n=arr.size(),ans=1;
    sort(arr.begin(),arr.end(),comp);
    vector<int> dp(n,1);
    for(int i=0;i<n;i++){
        for(int j=i-1;j>=0;j--){
            if(compare(arr[j],arr[i]) && dp[i]<dp[j]+1)
                dp[i]=dp[j]+1;
        }
        ans=max(ans,dp[i]);
    }
    return ans;
}

int main(){
    cout<<"Enter the number of words: ";
    int n;
    cin>>n;
    cout<<"Enter the strings\n";
    vector<string> arr(n);
    for(int i=0;i<n;i++)
        cin>>arr[i];
    cout<<"The length of the longest string chaining possible is: "<<chain(arr);
}

//Time complexity : O(n*n*(max length of string))
//Space complexity : O(n)