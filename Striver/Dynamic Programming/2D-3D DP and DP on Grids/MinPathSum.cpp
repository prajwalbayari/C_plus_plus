// Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right, which minimizes the sum of all numbers along its path.

// Note: You can only move either down or right at any point in time.

#include<iostream>
#include<vector>
using namespace std;

//Memoization
int minPathSum(int row,int col,vector<vector<int>>& dp,vector<vector<int>>& grid){
    if(row==0 && col==0)    
        return grid[row][col];
    if(row<0 || col<0)
        return 1e9;
    if(dp[row][col]!=-1)
        return dp[row][col];
    int up=minPathSum(row-1,col,dp,grid);
    int left=minPathSum(row,col-1,dp,grid);
    return dp[row][col]=(grid[row][col]+min(up,left));
}

//Tabulation
int MinPathSum(int m,int n,vector<vector<int>>& dp,vector<vector<int>>& grid){
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(i==0 && j==0){
                dp[i][j]=grid[i][j];
                continue;
            }
            int temp=1e9;
            if(i-1>=0)
                temp=dp[i-1][j];
            if(j-1>=0)
                temp=min(temp,dp[i][j-1]);
            dp[i][j]=grid[i][j]+((temp==1e9)? 0:temp);
        }
    }
    return dp[m-1][n-1];
}

//Space optimization
int MinPathSum(int m,int n,vector<vector<int>>& grid){
    vector<int> prev=grid[0];
    for(int i=1;i<n;i++)
        prev[i]+=prev[i-1];
    
    for(int i=1;i<m;i++){
        vector<int> temp(n,0);
        for(int j=0;j<n;j++){
            temp[j]=prev[j];
            if(j>0)
                temp[j]=min(temp[j-1],temp[j]);
            temp[j]+=grid[i][j];
        }
        prev=temp;
    }
    return prev[n-1];
}

int main(){
    int m,n;
    cout<<"Enter the order of the matrix: ";
    cin>>m>>n;
    cout<<"Enter the grid values\n";
    vector<vector<int>> grid(m,vector<int>(n)),dp(m,vector<int>(n,-1));
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin>>grid[i][j];
        }
    }
    cout<<"The minimum cost is: "<<MinPathSum(m,n,grid)<<endl;
}