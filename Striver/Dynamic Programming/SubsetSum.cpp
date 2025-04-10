// You are given an array/list ‘ARR’ of ‘N’ positive integers and an integer ‘K’. Your task is to check if there exists a subset in ‘ARR’ with a sum equal to ‘K’.

// Note: Return true if there exists a subset with sum equal to ‘K’. Otherwise, return false

#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;

//Memoization
bool subsetSum(int idx,int target,vector<int>& vec,vector<vector<int>>& dp){
    if(target==0)
        return true;
    if(idx==0)
        return target==vec[0];
    if(dp[idx][target])   
        return dp[idx][target];
    bool drop=subsetSum(idx-1,target,vec,dp),take=false;
    if(target>=vec[idx])
        take=subsetSum(idx-1,target-vec[idx],vec,dp);
    return dp[idx][target]=(drop || take);
}

//Tabulation
bool subsetSum(int target,vector<int>& vec,vector<vector<int>>& dp){
    int n=vec.size();
    for(int i=0;i<n;i++)
        dp[i][0]=true;
    dp[0][vec[0]]=true;
    for(int i=1;i<n;i++){
        for(int j=1;j<=target;j++){
            bool drop=dp[i-1][j],take=false;
            if(vec[i]<=j)
                take=dp[i-1][j-vec[i]];
            dp[i][j]=(drop||take);
        }
    }

    return dp[n-1][target];
}

//Space optimization
bool subsetSum(int target,vector<int>& vec){
    int n=vec.size();
    vector<bool> prev(target+1,false),cur(target+1,false);
    prev[0]=true,prev[vec[0]]=true,cur[0]=true;
    for(int i=1;i<n;i++){
        for(int j=1;j<=target;j++){
            bool drop=prev[j],take=false;
            if(vec[i]<=j)
                take=prev[j-vec[i]];
            cur[j]=(drop||take);
        }
        prev=cur;
    }

    return prev[target];
}

int main(){
    int n,k;
    cout<<"Enter the size of the array: ";
    cin>>n;
    cout<<"Enter the array elements\n";
    vector<int> vec(n);
    vector<vector<int>> dp(n,vector<int>(k+1,false));
    for(int i=0;i<n;i++)
        cin>>vec[i];
    cout<<"Enter the sum of the subset: ";
    cin>>k;
    if(subsetSum(k,vec,dp))
        cout<<"There is a subset in the array with the given sum\n";
    else
        cout<<"There is no subset with the given sum\n";
}

//Memoization
//Time complexity: O(n*k)
//Space complexity: O(n*k)+O(n)

//Memoization
//Time complexity: O(n*k)
//Space complexity: O(n*k)

//Space optimization
//Time complexity: O(n*k)
//Space complexity: O(k)