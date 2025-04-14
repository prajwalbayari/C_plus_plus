// We are given an array ‘ARR’ of size ‘N’ and a number ‘Target’. Our task is to build an expression from the given array where we can place a ‘+’ or ‘-’ sign in front of an integer. We want to place a sign in front of every integer of the array and get our required target. We need to count the number of ways in which we can achieve our required target.

#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;

//Memoization
int targetSum(int idx,vector<int>& vec,int k,vector<vector<int>>& dp){
    if(idx<0)
        return k==0;
    if(dp[idx][k]!=-1)
        return dp[idx][k];
    int dont=targetSum(idx-1,vec,k,dp),take=0;
    if(k>=vec[idx])
        take=targetSum(idx-1,vec,k-vec[idx],dp);
    return dp[idx][k]=(take+dont);
}

//Tabulation
int targetSum(int k,vector<int>& vec,vector<vector<int>>& dp){
    int n=vec.size();
    for(int i=0;i<n;i++)
        dp[i][0]=1;
    if(vec[0]<=k)
        dp[0][vec[0]]=1;
    for(int i=1;i<n;i++){
        for(int j=0;j<=k;j++){
            int dont=dp[i-1][j],take=0;
            if(j>=vec[i])
                take=dp[i-1][j-vec[i]];
            dp[i][j]=take+dont;
        }
    }
    return dp[n-1][k];
}

//Space optimization
int targetSum(int k,vector<int>& vec){
    int n=vec.size();
    vector<int> prev(k+1,0),cur(k+1,0);
    cur[0]=prev[0]=1;
    if(vec[0]<=k)
        prev[vec[0]]=1;
    for(int i=1;i<n;i++){
        for(int j=0;j<=k;j++){
            int dont=prev[j],take=0;
            if(j>=vec[i])
                take=prev[j-vec[i]];
            cur[j]=take+dont;
        }
        prev=cur;
    }
    return prev[k];
}

int main(){
    int n,target,sum=0;
    cout<<"Enter the size of the array: ";
    cin>>n;
    vector<int> vec(n);
    cout<<"Enter the array elements\n";
    for(int i=0;i<n;i++){
        cin>>vec[i];
        sum+=vec[i];
    }
    cout<<"Enter the target sum: ";
    cin>>target;
    if(abs(target)>sum || (sum-target)%2!=0){
        cout<<"The total number of ways to reach target is zero\n";
        return 0;
    }

    int k=(sum-target)/2;
    vector<vector<int>> dp(n,vector<int>(k+1,-1));

    cout<<"The total number of ways to reach target is: "<<targetSum(k,vec);
}