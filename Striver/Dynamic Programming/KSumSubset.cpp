// We are given an array ‘ARR’ with N positive integers and an integer K. We need to find the number of subsets whose sum is equal to K.

#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;

//Memoization
int subsetSum(int idx,vector<int>& vec,int k,vector<vector<int>>& dp){
    if(k==0)
        return 1;
    if(idx==0)
        return k==vec[0];
    if(dp[idx][k]!=-1)
        return dp[idx][k];
    int dont=subsetSum(idx-1,vec,k,dp),take=0;
    if(k>=vec[idx])
        take=subsetSum(idx-1,vec,k-vec[idx],dp);
    return dp[idx][k]=(take+dont);
}

//Tabulation
int subsetSum(int k,vector<int>& vec,vector<vector<int>>& dp){
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
int subsetSum(int k,vector<int>& vec){
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
    int n,k;
    cout<<"Enter the size of the array: ";
    cin>>n;
    vector<int> vec(n);
    cout<<"Enter the array elements\n";
    for(int i=0;i<n;i++)
        cin>>vec[i];
    cout<<"Enter the value of k: ";
    cin>>k;
    vector<vector<int>> dp(n,vector<int>(k+1,0));
    cout<<"The number of subsets with given sum is: "<<subsetSum(k,vec);
}

//Memoization
//Time complexity: O(n*k)
//Space complexity: O(n*k)+O(n)

//Tabulation
//Time complexity: O(n*k)
//Space complexity: O(n*k)

//Space optimization
//Time complexity: O(n*k)
//Space complexity: O(k)