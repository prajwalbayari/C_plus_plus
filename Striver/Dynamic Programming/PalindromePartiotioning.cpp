// Given a string s, partition s such that every substring of the partition is a palindrome. Return the minimum cuts needed for a palindrome partitioning of s.

#include<iostream>
#include<vector>
#include<string>
#include<limits.h>
using namespace std;

bool isPalindrome(int i,int j,string str){
    while(i<j){
        if(str[i]!=str[j])
            return false;
        i++,j--;
    }
    return true;
}

//Memoization
int partition(int i,int n,string str,vector<int>& dp){
    if(i==n)
        return -1;
    if(dp[i]!=-1)
        return dp[i];
    int ans=1e9;
    for(int j=i;j<n;j++){
        if(isPalindrome(i,j,str))
            ans=min(ans,partition(j+1,n,str,dp)+1);
    }
    return dp[i]=ans;
}

//Tabulation
int partition(int n,string str,vector<int>& dp){
    for(int i=n-1;i>=0;i--){
        int cost=INT_MAX;
        for(int j=i;j<n;j++){
            if(isPalindrome(i,j,str))
                cost=min(cost,dp[j+1]+1);
        }
        dp[i]=cost;
    }
    return dp[0]-1;
}

int main(){
    string str;
    cout<<"Enter the string: ";
    cin>>str;
    int n=str.size();
    vector<int> dp(n+1,-1);
    cout<<"The minimum number of partition required is : "<<partition(0,n,str,dp)<<endl;
}

//Memoization
//Time complexity : O(n*n)
//Space complexity : O(n)+O(n)

//Tabulation
//Time complexity : O(n*n)
//Space complexity : O(n)