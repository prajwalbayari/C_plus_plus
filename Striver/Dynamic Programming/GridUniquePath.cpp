// There is a robot on an m x n grid. The robot is initially located at the top-left corner (i.e., grid[0][0]). The robot tries to move to the bottom-right corner (i.e., grid[m - 1][n - 1]). The robot can only move either down or right at any point in time.

// Given the two integers m and n, return the number of possible unique paths that the robot can take to reach the bottom-right corner.

// The test cases are generated so that the answer will be less than or equal to 2 * 109.

#include<iostream>
#include<limits.h>
#include<vector>
using namespace std;

//Memoization
int UniquePaths(int row,int col,int m,int n,vector<vector<int>>& dp){
    if(row==m-1 && col==n-1)
        return 1;
    if(row>=m || col>=n)
        return 0;
    if(dp[row][col]!=-1)
        return dp[row][col];
    
    int up=UniquePaths(row+1,col,m,n,dp);
    int left=UniquePaths(row,col+1,m,n,dp);

    return dp[row][col]=up+left;
}

//Tabulation
int UniquePaths(int m,int n,vector<vector<int>>& dp){
    dp[0][0]=1;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(i==0 && j==0)
                continue;
            int ans=0;
            if(i-1>=0)
                ans=ans+dp[i-1][j];
            if(j-1>=0)
                ans=ans+dp[i][j-1];
            dp[i][j]=ans;
        }
    }
    return dp[m-1][n-1];
}

//Space optimization
int UniquePaths(int m,int n){
    vector<int> dp(n,1);
    for(int i=1;i<m;i++){
        vector<int> temp(n,0);
        for(int j=0;j<n;j++){
            if(j>0)
                temp[j]=temp[j-1];
            temp[j]+=dp[j];
        }
        dp=temp;
    }
    return dp[n-1];
}

int main(){
    int m,n;
    cout<<"Enter the size of the grid: ";
    cin>>m>>n;
    vector<vector<int>> dp(m,vector<int>(n,-1));
    cout<<"The number of unique paths are: "<<UniquePaths(0,0,m,n,dp)<<endl;
}

//Memoization
//Time complexity: O(m*n)
//Space complexity: O((n-1)+(m-1))+O(n*m)

//Tabulation
//Time complexity: O(m*n)
//Space complexity: O(m*n)

//Tabulation
//Time complexity: O(m*n)
//Space complexity: O(n)