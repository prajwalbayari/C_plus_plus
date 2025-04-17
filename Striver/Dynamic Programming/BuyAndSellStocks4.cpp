// We are given an array Arr[] of length n. It represents the price of a stock on ‘n’ days. The following guidelines need to be followed:

// We can buy and sell the stock any number of times.
// In order to sell the stock, we need to first buy it on the same or any previous day.
// We can’t buy a stock again after buying it once. In other words, we first buy a stock and then sell it. After selling we can buy and sell again. But we can’t sell before buying and can’t buy before selling any previously bought stock.
// We can do at-most K transactions.

#include<iostream>
#include<vector>
using namespace std;

//Memoization
int stock(int idx,int tran,int n,int k,vector<int>& vec,vector<vector<int>>& dp){
    if(idx==n || tran==2*k)
        return 0;
    if(dp[idx][tran]!=-1)
        return dp[idx][tran];
    if(tran%2==0)
        return dp[idx][tran]=max(stock(idx+1,tran+1,n,k,vec,dp)-vec[idx],stock(idx+1,tran,n,k,vec,dp));
    return dp[idx][tran]=max(stock(idx+1,tran+1,n,k,vec,dp)+vec[idx],stock(idx+1,tran,n,k,vec,dp));
}

//Tabulation
int stock(int n,vector<int>& vec,vector<vector<int>>& dp,int m){
    for(int i=n-1;i>=0;i--){
        for(int k=2*m-1;k>=0;k--){
            if(k%2==0)
                dp[i][k]=max(dp[i+1][k+1]-vec[i],dp[i+1][k]);
            else
                dp[i][k]=max(dp[i+1][k+1]+vec[i],dp[i+1][k]);
        }
    }
    return dp[0][0];
}

//Space optimization
int stock(int n,vector<int>& vec,int m){
    vector<int> ahead(2*m+1,0),cur(2*m+1,0);
    for(int i=n-1;i>=0;i--){
        for(int k=2*m-1;k>=0;k--){
            if(k%2==0)
                cur[k]=max(ahead[k+1]-vec[i],ahead[k]);
            else
                cur[k]=max(ahead[k+1]+vec[i],ahead[k]);
        }
        ahead=cur;
    }
    return cur[0];
}

int main(){
    int n,k;
    cout<<"Enter the number of days: ";
    cin>>n;
    vector<int> vec(n);
    cout<<"Enter the values of the stocks\n";
    for(int i=0;i<n;i++)
        cin>>vec[i];
    cout<<"Enter k: ";
    cin>>k;
    vector<vector<int>> dp(n+1,vector<int>(2*k+1,0));
    cout<<"The maximum profit is: "<<stock(n,vec,k);
}

//Memoiztion
//Time complexity: O(n*k*2)
//Space complexity: O(n*k*2)+O(n)

//Tabulation
//Time complexity: O(n*k*2)
//Space complexity: O(n*k*2)

//Space optimization
//Time complexity: O(n*k*2)
//Space complexity: O(k*2)