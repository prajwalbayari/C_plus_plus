// You are given a rows x cols matrix grid representing a field of cherries where grid[i][j] represents the number of cherries that you can collect from the (i, j) cell.

// You have two robots that can collect cherries for you:

// Robot #1 is located at the top-left corner (0, 0), and
// Robot #2 is located at the top-right corner (0, cols - 1).
// Return the maximum number of cherries collection using both robots by following the rules below:

// From a cell (i, j), robots can move to cell (i + 1, j - 1), (i + 1, j), or (i + 1, j + 1).
// When any robot passes through a cell, It picks up all cherries, and the cell becomes an empty cell.
// When both robots stay in the same cell, only one takes the cherries.
// Both robots cannot move outside of the grid at any moment.
// Both robots should reach the bottom row in grid.

#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;

//Memoization
int Cherrypickup(int row,int col1,int col2,int m,int n,vector<vector<int>>& vec,vector<vector<vector<int>>>& dp){
    if(col1<0 || col1>=n || col2<0 || col2>=n)
        return INT_MIN;
    if(row==m-1){
        if(col1==col2)
            return vec[row][col1];
        return vec[row][col1]+vec[row][col2];
    }
    if(dp[row][col1][col2]!=-1)
        return dp[row][col1][col2];
    int ans=INT_MIN;
    for(int i=-1;i<=1;i++){
        for(int j=-1;j<=1;j++){
            ans=max(ans,Cherrypickup(row+1,col1+i,col2+j,m,n,vec,dp));
        }
    }
    if(col1==col2)
        ans=ans+vec[row][col1];
    else
        ans=ans+vec[row][col2]+vec[row][col1];
    return dp[row][col1][col2]=ans;
}

//Tabulation
int Cherrypickup(int m,int n,vector<vector<int>>& vec,vector<vector<vector<int>>>& dp){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i==j)
                dp[m-1][i][j]=vec[m-1][i];
            else
                dp[m-1][i][j]=vec[m-1][i]+vec[m-1][j];
        }
    }

    for(int i=m-2;i>=0;i--){
        for(int j=0;j<n;j++){
            for(int k=0;k<n;k++){
                int ans=INT_MIN;
                for(int dirj=-1;dirj<=1;dirj++){
                    for(int dirk=-1;dirk<=1;dirk++){
                        int col1=j+dirj,col2=k+dirk;

                        if(col1>=0 && col1<n && col2>=0 && col2<n)
                            ans=max(ans,dp[i+1][col1][col2]);
                    }
                }
                if(j==k)
                    ans=ans+vec[i][j];
                else
                    ans=ans+vec[i][j]+vec[i][k];
                dp[i][j][k]=ans;
            }
        }
    }

    return dp[0][0][n-1];
}

//Space optimization
int Cherrypickup(int m,int n,vector<vector<int>>& vec){
    vector<vector<int>> prev(n,vector<int>(n));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i==j)
                prev[i][j]=vec[m-1][i];
            else
                prev[i][j]=vec[m-1][i]+vec[m-1][j];
        }
    }

    for(int i=m-2;i>=0;i--){
        vector<vector<int>> cur(n,vector<int>(n));
        for(int j=0;j<n;j++){
            for(int k=0;k<n;k++){
                int ans=INT_MIN;
                for(int dirj=-1;dirj<=1;dirj++){
                    for(int dirk=-1;dirk<=1;dirk++){
                        int col1=j+dirj,col2=k+dirk;

                        if(col1>=0 && col1<n && col2>=0 && col2<n)
                            ans=max(ans,prev[col1][col2]);
                    }
                }
                if(j==k)
                    ans=ans+vec[i][j];
                else
                    ans=ans+vec[i][j]+vec[i][k];
                cur[j][k]=ans;
            }
        }
        prev=cur;
    }

    return prev[0][n-1];
}

int main(){
    int m,n;
    cout<<"Enter the order of the matrix: ";
    cin>>m>>n;
    vector<vector<int>> vec(m,vector<int>(n));
    vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(n, -1)));
    cout<<"Enter the values of the grid\n";
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++)
            cin>>vec[i][j];
    }
    cout<<"The total number of candies is: "<<Cherrypickup(m,n,vec);
}

//Memoization
//Time complexity: O(m*n*n*9)
//Space complexity: O(m*n*n)+O(n)

//Tabulation
//Time complexity: O(m*n*n*9)
//Space complexity: O(m*n*n)

//Space optimization
//Time complexity: O(m*n*n*9)
//Space complexity: O(n*n)