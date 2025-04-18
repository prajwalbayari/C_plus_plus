// We are given a stick of length N and a CUTS array of size C. The stick has markings as shown, and the CUTS array depicts the marking at which the stick needs to be cut
// Whenever we make a cut, we incur a cost. This cost is equal to the length of the stick on which we are making the cut.
// We need to find the minimum cost incurred to cut the stick at all the cut points.

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//Memoization
int cuts(int i,int j,vector<int>& arr,vector<vector<int>>& dp){
    if(i>j)
        return 0;
    if(dp[i][j]!=-1)
        return dp[i][j];
    int ans=1e8;
    for(int k=i;k<=j;k++){
        int temp=(arr[j+1]-arr[i-1]+cuts(i,k-1,arr,dp)+cuts(k+1,j,arr,dp));
        ans=min(temp,ans);
    }
    return dp[i][j]=ans;
}

//Tabulation
int cuts(vector<int>& arr,vector<vector<int>>& dp,int n){
    for(int i=n;i>0;i--){
        for(int j=i;j<=n;j++){
            int temp=1e8;
            for(int k=i;k<=j;k++){
                temp=min(temp,(arr[j+1]-arr[i-1]+dp[i][k-1]+dp[k+1][j]));
            }
            dp[i][j]=temp;
        }
    }
    return dp[1][n];
}

int main(){
    int n,len;
    cout<<"Enter the length of the stick: ";
    cin>>len;
    cout<<"Enter the total numbver of cuts: ";
    cin>>n;
    cout<<"Enter the cuts: ";
    vector<int> cut(n+2);
    for(int i=1;i<=n;i++)
        cin>>cut[i];
    cut[0]=0,cut[n+1]=len;
    sort(cut.begin(),cut.end());
    vector<vector<int>> dp(n+2,vector<int>(n+2,0));
    cout<<"The minimum cost to cut the stick is: "<<cuts(cut,dp,n)<<endl;
}

//Memoization
//Time complexity : O(n*n*n)
//Space complexity : O(n*n)+O(n)

//Tabulation
//Time complexity : O(n*n*n)
//Space complexity : O(n*n)