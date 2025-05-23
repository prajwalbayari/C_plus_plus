//You are a professional robber planning to rob houses along a street. Each house has a 
//certain amount of money stashed, the only constraint stopping you from robbing each of 
//them is that adjacent houses have security systems connected and it will automatically 
//contact the police if two adjacent houses were broken into on the same night.

// Given an integer array nums representing the amount of money of each house, return 
//the maximum amount of money you can rob tonight without alerting the police.

#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;

//Memoization
int houseRobber(int idx,vector<int>& vec,vector<int>& dp){
    if(idx<0)
        return 0;
    if(idx==0)
        return vec[0];
    if(dp[idx]!=-1)
        return dp[idx];
    
    int take=houseRobber(idx-2,vec,dp)+vec[idx];
    int dont=houseRobber(idx-1,vec,dp);
    return dp[idx]=max(take,dont);
}

//Tabulation
int HouseRobber(int n,vector<int>& vec,vector<int>& dp){
    dp[0]=vec[0];
    for(int i=1;i<n;i++){
        int dont=dp[i-1],take=INT_MIN;
        if(i>1)
            take=dp[i-2]+vec[i];
        dp[i]=max(take,dont);
    }
    return dp[n-1];
}

//Space optimization
int HouseRobberOpt(int n,vector<int>& vec){
    int first=vec[0],second=0;
    for(int i=1;i<n;i++){
        int take=vec[i]+second,dont=first;
        int ans=max(take,dont);
        second=first,first=ans;
    }
    return first;
}

int main(){
    int n;
    cout<<"Enter the number of houses: ";
    cin>>n;
    cout<<"Enter the worth of each house: ";
    vector<int> vec(n),dp(n,-1);
    for(int i=0;i<n;i++)
        cin>>vec[i];

    cout<<"The maximum amount of money that can be robbed is: "<<HouseRobberOpt(n,vec);
}