// We are given a target sum of ‘X’ and ‘N’ distinct numbers denoting the coin denominations. We need to tell the minimum number of coins required to reach the target sum. We can pick a coin denomination for any number of times we want.

#include<iostream>
#include<vector>
#include<limits.h>
#include<algorithm>
using namespace std;

//Memoization
int minCoins(int idx,int sum,vector<int>& vec,vector<vector<int>>& dp){
    if(sum==0)
        return 0;
    if(idx<0)
        return 1e8;
    if(dp[idx][sum]!=-1)
        return dp[idx][sum];
    int dont=minCoins(idx-1,sum,vec,dp),take=1e8;
    if(sum>=vec[idx])
        take=minCoins(idx,sum-vec[idx],vec,dp)+1;
    return dp[idx][sum]=min(dont,take);
}

//Tabulation
int minCoins(int sum,vector<int>& vec,vector<vector<int>>& dp){
    int n=vec.size();
    for(int i=0;i<=sum;i++){
        if(i%vec[0]==0)
            dp[0][i]=i/vec[0];
        else
            dp[0][i]=1e8;
    }

    for(int i=1;i<n;i++){
        for(int j=0;j<=sum;j++){
            int dont=dp[i-1][j],take=1e8;
            if(j>=vec[i])
                take=dp[i][j-vec[i]]+1;
            dp[i][j]=min(take,dont);
        }
    }
    return dp[n-1][sum];
}

//Space optimization
int minCoins(int sum,vector<int>& vec){
    int n=vec.size();
    vector<int> prev(sum+1,1e8),cur(sum+1,1e8);
    for(int i=0;i<=sum;i++){
        if(i%vec[0]==0)
            prev[i]=i/vec[0];
    }

    for(int i=1;i<n;i++){
        for(int j=0;j<=sum;j++){
            int dont=prev[j],take=1e8;
            if(j>=vec[i])
                take=cur[j-vec[i]]+1;
            cur[j]=min(take,dont);
        }
        prev=cur;
    }
    return prev[sum];
}

int main(){
    int n,sum;
    cout<<"Enter the number of coins: ";
    cin>>n;
    cout<<"Enter the coin values: ";
    vector<int> vec(n);
    for(int i=0;i<n;i++)
        cin>>vec[i];
    sort(vec.begin(),vec.end());
    cout<<"Enter the target sum: ";
    cin>>sum;
    vector<vector<int>> dp(n,vector<int>(sum+1,-1));
    cout<<"The minimum number of coins to reach the target sum is: "<<minCoins(n-1,sum,vec,dp)<<endl;
}

//Memoization
//Time complexity: O(n*sum)
//Space complexity: O(n*sum)+O(sum)

//Tabulation
//Time complexity: O(n*sum)
//Space complexity: O(n*sum)

//Space optimization
//Time complexity: O(n*sum)
//Space complexity: O(sum)