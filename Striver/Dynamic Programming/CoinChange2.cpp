// We are given an array Arr with N distinct coins and a target. We have an infinite supply of each coin denomination. We need to find the number of ways we sum up the coin values to give us the target.

#include<iostream>
#include<vector>
#include<limits.h>
#include<algorithm>
using namespace std;

//Memoization
int coinExchange(int idx,int val,vector<int>& vec,vector<vector<int>>& dp){
    if(val==0)
        return 1;
    if(idx<0)
        return val==0;
    if(dp[idx][val]!=-1)
        return dp[idx][val];
    int drop=coinExchange(idx-1,val,vec,dp),take=0;
    if(vec[idx]<=val)
        take=coinExchange(idx,val-vec[idx],vec,dp);
    return dp[idx][val]=drop+take;
}

//Tabulation
int coinExchange(int val,vector<int>& vec,vector<vector<int>>& dp){
    int n=vec.size();
    for(int i=0;i<=val;i++){
        dp[0][i]=(i%vec[0]==0);
    }

    for(int i=1;i<n;i++){
        for(int j=0;j<=val;j++){
            dp[i][j]=dp[i-1][j];
            if(j>=vec[i])
                dp[i][j]+=dp[i][j-vec[i]];
        }
    }
    return dp[n-1][val];
}

//Space optimization
int coinExchange(int val,vector<int>& vec){
    int n=vec.size();
    vector<int> prev(val+1,0),cur(val+1,0);
    for(int i=0;i<=val;i++){
        prev[i]=(i%vec[0]==0);
    }

    for(int i=1;i<n;i++){
        for(int j=0;j<=val;j++){
            cur[j]=prev[j];
            if(j>=vec[i])
                cur[j]+=cur[j-vec[i]];
        }
        prev=cur;
    }
    return prev[val];
}

int main(){
    int n,val;
    cout<<"Enter the number of the coins: ";
    cin>>n;
    cout<<"Enter the values of the coins: ";
    vector<int> vec(n);
    for(int i=0;i<n;i++)
        cin>>vec[i];
    sort(vec.begin(),vec.end());
    cout<<"Enter the coin values: ";
    cin>>val;
    vector<vector<int>> dp(n,vector<int>(val+1,0));
    cout<<"The total number of ways we can find the coins is: "<<coinExchange(val,vec)<<endl;
}