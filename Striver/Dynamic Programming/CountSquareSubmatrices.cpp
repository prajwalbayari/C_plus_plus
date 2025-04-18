// Given an n * m matrix of ones and zeros, return how many square submatrices have all ones

#include<iostream>
#include<vector>
using namespace std;

int main(){
    int m,n,ans=0;
    cout<<"Enter the order of the matrix: ";
    cin>>m>>n;
    cout<<"Enter the matrix\n";
    vector<vector<int>> mat(m,vector<int>(n)),dp(m,vector<int>(n,0));
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin>>mat[i][j];
            if(i==0 || j==0)
                dp[i][j]=mat[i][j],ans+=mat[i][j];
        }
    }

    for(int i=1;i<m;i++){
        for(int j=1;j<n;j++){
            if(mat[i][j])
                dp[i][j]=1+min(dp[i-1][j-1],min(dp[i-1][j],dp[i][j-1]));
            ans+=dp[i][j];
        }
    }
    cout<<"The total number of square submatrices is: "<<ans<<endl;
}

//Time complexity : O(m*n)
//Space complexity : O(m*n)