// Given an integer array arr, partition the array into (contiguous) subarrays of length at most k. After partitioning, each subarray has its values changed to become the maximum value of that subarray.

// Return the largest sum of the given array after partitioning.

#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;

//Memoization
int part(int idx,int n,int k,vector<int>& arr,vector<int>& dp){
    if(idx==n)
        return 0;
    if(dp[idx]!=-1)
        return dp[idx];
    int ans=INT_MIN,cur=arr[idx];
    for(int i=idx;i<min(idx+k,n);i++){
        cur=max(cur,arr[i]);
        ans=max(ans,(cur*(i-idx+1)+part(i+1,n,k,arr,dp)));
    }
    return dp[idx]=ans;
}

//Tabulation
int part(int n,int k,vector<int>& arr,vector<int>& dp){
    for(int i=n-1;i>=0;i--){
        int cur=INT_MIN,ans=INT_MIN;
        for(int j=i;j<min(i+k,n);j++){
            cur=max(arr[j],cur);
            ans=max(ans,(cur*(j-i+1)+dp[j+1]));
        }
        dp[i]=ans;
    }
    return dp[0];
}

int main(){
    int n,k;
    cout<<"Enter the size of the array: ";
    cin>>n;
    cout<<"Enter the array elements: ";
    vector<int> arr(n);
    for(int i=0;i<n;i++)
        cin>>arr[i];
    cout<<"Enter the subarray limit: ";
    cin>>k;
    vector<int> dp(n+1,0);
    cout<<"The maximum possible sum is: "<<part(n,k,arr,dp);
}

//Memoization
//Time complexity: O(n*k)
//Space complexity: O(n)+O(n)

//Memoization
//Time complexity: O(n*k)
//Space complexity: O(n)