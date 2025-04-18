// You are given n balloons, indexed from 0 to n - 1. Each balloon is painted with a number on it represented by an array. You are asked to burst all the balloons.

// If you burst the ith balloon, you will get arr[i - 1] * arr[i] * arr[i + 1] coins. If i - 1 or i + 1 goes out of the array's bounds, then treat it as if there is a balloon with a 1 painted on it.

// Return the maximum coins you can collect by bursting the balloons wisely.

#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;

//Memoization
long Burst(int i,int j,vector<int>& arr,vector<vector<long>>& dp){
    if(i>j)
        return 0;
    if(dp[i][j]!=-1)
        return dp[i][j];
    long ans=LONG_MIN;
    for(int k=i;k<=j;k++){
        long temp=arr[i-1]*arr[k]*arr[j+1]+Burst(i,k-1,arr,dp)+Burst(k+1,j,arr,dp);
        if(ans<temp)
            ans=temp;
    }
    return dp[i][j]=ans;
}

//Tabulation
long Burst(vector<int>& arr,vector<vector<long>>& dp){
    int n=arr.size()-2;
    for(int i=n;i>0;i--){
        for(int j=i;j<=n;j++){
            long temp=LONG_MIN;
            for(int k=i;k<=j;k++){
                temp=max(temp,(arr[i-1]*arr[k]*arr[j+1]+dp[i][k-1]+dp[k+1][j]));
            }
            dp[i][j]=temp;
        }
    }
    return dp[1][n];
}

int main(){
    int n;
    cout<<"Enter the number of balloon: ";
    cin>>n;
    cout<<"Enter the values of the balloon: ";
    vector<int> vec(n+2);
    for(int i=1;i<=n;i++)
        cin>>vec[i];
    vec[0]=vec[n+1]=1;
    vector<vector<long>> dp(n+2,vector<long>(n+2,0));
    cout<<"The maximum coins that can be obtained is "<<Burst(vec,dp);
}

//Memoization
//Time complexity : O(n*n*n)
//Space complexity : O(n*n)+O(n)

//Tabulation
//Time complexity : O(n*n*n)
//Space complexity : O(n*n)