// You are given an integer array nums of 2 * n integers. You need to partition nums into two arrays of length n to minimize the absolute difference of the sums of the arrays. To partition nums, put each element of nums into one of the two arrays.

// Return the minimum possible absolute difference

#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;

//Tabulation
void partition(int sum,int n,vector<int>& vec,vector<vector<bool>>& dp){
    for(int i=0;i<n;i++)
        dp[i][0]=true;
    dp[0][vec[0]]=true;
    for(int i=1;i<n;i++){
        for(int j=1;j<=sum;j++){
            bool drop=dp[i-1][j],take=false;
            if(j>=vec[i])
                take=dp[i-1][j-vec[i]];
            dp[i][j]=(take||drop);
        }
    }
}

int main(){
    int n,sum=0,ans=INT_MAX;
    cout<<"Enter the size of the array: ";
    cin>>n;
    vector<int> vec(n);
    cout<<"Enter the array elements\n";
    for(int i=0;i<n;i++){
        cin>>vec[i];
        sum+=vec[i];
    }
    vector<vector<bool>> dp(n,vector<bool>(sum+1));
    partition(sum,n,vec,dp);

    for(int i=0;i<=sum/2;i++){
        if(dp[n-1][i])
            ans=min(ans,abs(sum-(2*i)));
    }

    cout<<"The minimum possible difference is: "<<ans<<endl;
}

//Tabulation
//Time complexity: O(n*k)
//Space complexity: O(n*k)