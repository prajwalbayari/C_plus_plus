// You are given an m x n integer array grid. There is a robot initially located at the top-left corner (i.e., grid[0][0]). The robot tries to move to the bottom-right corner (i.e., grid[m - 1][n - 1]). The robot can only move either down or right at any point in time.

// An obstacle and space are marked as 1 or 0 respectively in grid. A path that the robot takes cannot include any square that is an obstacle.

// Return the number of possible unique paths that the robot can take to reach the bottom-right corner.

// The testcases are generated so that the answer will be less than or equal to 2 * 10^9.

#include<iostream>
#include<vector>
using namespace std;

//Memoization
int uniquePaths(int row,int col,vector<vector<int>>& dp,vector<vector<int>>& grid){
    if(row==0 && col==0)
        return 1;
    if(row<0 || col<0 || grid[row][col]==1)
        return 0;
    if(dp[row][col]!=-1)
        return dp[row][col];
    
    int up=uniquePaths(row-1,col,dp,grid);
    int left=uniquePaths(row,col-1,dp,grid);

    return dp[row][col]=up+left;
}

//Tabulation
int UniquePaths(int m,int n,vector<vector<int>>& dp,vector<vector<int>>& grid){
    dp[0][0]=1;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(i==0 && j==0 || grid[i][j]==1)
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
int UniquePaths(int m,int n,vector<vector<int>>& grid){
    vector<int> dp(n,1);
    for(int i=0;i<n;i++){
        if(grid[0][i]==1)
            dp[i]=0;
    }
    for(int i=1;i<m;i++){
        vector<int> temp(n,0);
        for(int j=0;j<n;j++){
            if(grid[i][j]==1)
                continue;
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
    cout<<"Enter the grid:\n";
    vector<vector<int>> dp(m,vector<int>(n,0)),grid(m,vector<int>(n));
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++)
            cin>>grid[i][j];
    }
    cout<<"The number of unique paths are: "<<UniquePaths(m,n,grid)<<endl;
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