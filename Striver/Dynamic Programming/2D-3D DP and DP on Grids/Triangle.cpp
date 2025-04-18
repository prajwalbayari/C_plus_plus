// Given a triangle array, return the minimum path sum from top to bottom.

// For each step, you may move to an adjacent number of the row below. More formally, if you are on index i on the current row, you may move to either index i or index i + 1 on the next row

#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;

//Memoization
int Triangle(int row,int col,int n,vector<vector<int>>& triangle,vector<vector<int>>& dp){
    if(row==n-1)
        return triangle[row][col];
    if(col>row || col<0)
        return INT_MAX;
    if(dp[row][col]!=-1)
        return dp[row][col];
    int left=Triangle(row+1,col,n,triangle,dp);
    int right=Triangle(row+1,col+1,n,triangle,dp);
    return dp[row][col]=triangle[row][col]+min(left,right);
}

//Tabulation
int Triangle(int n,vector<vector<int>>& triangle,vector<vector<int>>& dp){
    dp[0][0]=triangle[0][0];
    for(int i=1;i<n;i++){
        for(int j=0;j<i+1;j++){
            if(j==0)
                dp[i][j]=triangle[i][j]+dp[i-1][j];
            else if(j==i)
                dp[i][j]=triangle[i][j]+dp[i-1][j-1];
            else    
                dp[i][j]=triangle[i][j]+min(dp[i-1][j],dp[i-1][j-1]);
        }
    }
    int ans=INT_MAX;
    for(int i=0;i<n;i++)
        ans=min(ans,dp[n-1][i]);
    return ans;
}

//Space optimization
int Triangle(int n,vector<vector<int>>& triangle){
    vector<int> prev={triangle[0][0]};
    for(int i=1;i<n;i++){
        vector<int> cur(i+1);
        for(int j=0;j<i+1;j++){
            if(j==0)
                cur[j]=triangle[i][j]+prev[j];
            else if(j==i)
                cur[j]=triangle[i][j]+prev[j-1];
            else    
                cur[j]=triangle[i][j]+min(prev[j],prev[j-1]);
        }
        prev=cur;
    }
    int ans=INT_MAX;
    for(int i=0;i<n;i++)
        ans=min(ans,prev[i]);
    return ans;
}

int main(){
    int n;
    cout<<"Enter the number of rows of the triangle: ";
    cin>>n;
    cout<<"Enter the values:\n";
    vector<vector<int>> triangle,dp;
    for(int i=0;i<n;i++){
        vector<int> vec(i+1,-1);
        dp.push_back(vec);
        for(int j=0;j<i+1;j++)
            cin>>vec[j];
        triangle.push_back(vec);
    }
    cout<<"Minimum cost to reach last row is: "<<Triangle(n,triangle);
}