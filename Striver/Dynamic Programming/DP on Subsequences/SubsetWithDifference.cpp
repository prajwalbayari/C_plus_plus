// We are given an array ‘ARR’ with N positive integers and an integer D. We need to count the number of ways we can partition the given array into two subsets, S1 and S2 such that S1 - S2 = D and S1 is always greater than or equal to S2.

#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;

//Memoization
int subsetSumWithDifferenceK(int idx,vector<int>& vec,int k,vector<vector<int>>& dp){
    if(k==0)
        return 1;
    if(idx==0)
        return k==vec[0];
    if(dp[idx][k]!=0)
        return dp[idx][k];
    int dont=subsetSumWithDifferenceK(idx-1,vec,k,dp),take=0;
    if(k>=vec[idx])
        take=subsetSumWithDifferenceK(idx-1,vec,k-vec[idx],dp);
    return dp[idx][k]=(take+dont);
}

//Tabulation
int subsetSumWithDifferenceK(int k,vector<int>& vec,vector<vector<int>>& dp){
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
int subsetSumWithDifferenceK(int k,vector<int>& vec){
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
    int n,d,sum=0;
    cout<<"Enter the size of the array: ";
    cin>>n;
    vector<int> vec(n);
    cout<<"Enter the array elements\n";
    for(int i=0;i<n;i++){
        cin>>vec[i];
        sum+=vec[i];
    }
    cout<<"Enter the difference: ";
    cin>>d;
    if(sum<d || (sum+d)%2==1){
        cout<<"The number of subsets with given sum is zero\n";
        return 0;
    }
    int k=(sum+d)/2;
    vector<vector<int>> dp(n,vector<int>(k+1,0));
    cout<<"The number of subsets with given sum is: "<<subsetSumWithDifferenceK(n-1,vec,k,dp)<<endl;
}