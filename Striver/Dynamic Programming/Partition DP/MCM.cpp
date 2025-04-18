//Matrix chain multiplication
// Given a chain of matrices A1,..., An denoted by an array of size n+1, find out the minimum number of operations to multiply these n matrices.

#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;

//Memoization
long MCM(int i,int j,vector<int>& arr,vector<vector<long>>& dp){
    if(i==j)
        return 0;
    if(dp[i][j]!=-1)
        return dp[i][j];
    long ans=LONG_MAX;
    for(int k=i;k<j;k++){
        long temp=arr[i-1]*arr[k]*arr[j]+MCM(i,k,arr,dp)+MCM(k+1,j,arr,dp);
        if(ans>temp)
            ans=temp;
    }
    return dp[i][j]=ans;
}

//Tabulation
long MCM(vector<int>& arr,vector<vector<long>>& dp){
    int n=arr.size();
    for(int i=n-1;i>0;i--){
        for(int j=i+1;j<n;j++){
            long ans=LONG_MAX;
            for(int k=i;k<j;k++){
                long temp=(arr[i-1]*arr[k]*arr[j])+dp[i][k]+dp[k+1][j];
                if(ans>temp)
                    ans=temp;
            }
            dp[i][j]=ans;
        }
    }
    return dp[1][n-1];
}

int main(){
    int n;
    cout<<"Enter the number of matrices: ";
    cin>>n;
    cout<<"Enter the matrix size array: ";
    vector<int> arr(n+1);
    for(int i=0;i<=n;i++)
        cin>>arr[i];
    vector<vector<long>> dp(n+1,vector<long>(n+1,0));
    cout<<"The minimum number of operations to multiply the matrices is: "<<MCM(arr,dp)<<endl;
}

//Memoization
//Time complexity : O(n*n*n)
//Space complexity : O(n*n)+O(n)

//Tabulation
//Time complexity : O(n*n*n)
//Space complexity : O(n*n)