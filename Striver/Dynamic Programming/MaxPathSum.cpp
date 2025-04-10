// Given an n x n array of integers matrix, return the maximum sum of any falling path through matrix.

// A falling path starts at any element in the first row and chooses the element in the next row that is either directly below or diagonally left/right. Specifically, the next element from position (row, col) will be (row + 1, col - 1), (row + 1, col), or (row + 1, col + 1).

//Note: Set dp array with INT_MIN to find maximum falling path and INT_MAX to find minimum

#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;

//Memoization
int maxPathSum(int row,int col,int m,int n,vector<vector<int>>& vec,vector<vector<int>>& dp){
    if(col<0 || col>=n)
        return INT_MIN;
    if(row==m-1)
        return vec[row][col];
    if(dp[row][col]!=INT_MIN)
        return dp[row][col];
    int ans=maxPathSum(row+1,col-1,m,n,vec,dp);
    ans=max(maxPathSum(row+1,col,m,n,vec,dp),ans);
    ans=max(maxPathSum(row+1,col+1,m,n,vec,dp),ans);

    return dp[row][col]=(vec[row][col]+ans);
}

//Tabulation
void maxPathSum(int m,int n,vector<vector<int>>& vec,vector<vector<int>>& dp){
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(i==0){
                dp[i][j]=vec[i][j];
                continue;
            }
            if(dp[i][j]!=INT_MIN)
                continue;
            if(j>0)
                dp[i][j]=dp[i-1][j-1];
            if(j<n-1)
                dp[i][j]=max(dp[i][j],dp[i-1][j+1]);
            dp[i][j]=max(dp[i][j],dp[i-1][j])+vec[i][j];
        }
    }
}

//Space optimization
int maxPathSum(int m,int n,vector<vector<int>>& vec){
    vector<int> prev=vec[0];
    for(int i=1;i<m;i++){
        vector<int> cur(n,INT_MIN);
        for(int j=0;j<n;j++){
            if(j>0)
                cur[j]=prev[j-1];
            if(j<n-1)
                cur[j]=max(cur[j],prev[j+1]);
            cur[j]=max(cur[j],prev[j])+vec[i][j];
        }
        prev=cur;
    }
    int ans=INT_MIN;
    for(int i=0;i<n;i++)
        ans=max(ans,prev[i]);
    return ans;
}

int main(){
    int m,n;
    cout<<"Enter the order of the matrix: ";
    cin>>m>>n;
    cout<<"Enter the values in the matrix\n";
    vector<vector<int>> vec(m,vector<int>(n)),dp(m,vector<int>(n,INT_MIN));
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++)
            cin>>vec[i][j];
    }
    int ans=INT_MIN;

    //For memoization
    // for(int i=0;i<n;i++)
    //     ans=max(ans,maxPathSum(0,i,m,n,vec,dp));
    
    //For tabulation
    // maxPathSum(m,n,vec,dp);
    // for(int i=0;i<n;i++)
    //     ans=max(ans,dp[n-1][i]);
    
    cout<<"The maximum falling sum is: "<<maxPathSum(m,n,vec)<<endl;
}