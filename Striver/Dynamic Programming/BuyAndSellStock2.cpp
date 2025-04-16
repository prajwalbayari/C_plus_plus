// We are given an array Arr[] of length n. It represents the price of a stock on ‘n’ days. The following guidelines need to be followed:

// We can buy and sell the stock any number of times.
// In order to sell the stock, we need to first buy it on the same or any previous day.
// We can’t buy a stock again after buying it once. In other words, we first buy a stock and then sell it. After selling we can buy and sell again. But we can’t sell before buying and can’t buy before selling any previously bought stock.

#include<iostream>
#include<vector>
using namespace std;

//Memoization
int stock(int idx,int buy,int n,vector<int>& vec,vector<vector<int>>& dp){
    if(idx==n)
        return 0;
    if(dp[idx][buy]!=-1)
        return dp[idx][buy];
    if(buy)
        return dp[idx][buy]=max(stock(idx+1,0,n,vec,dp)-vec[idx],stock(idx+1,1,n,vec,dp));
    return dp[idx][buy]=max(stock(idx+1,1,n,vec,dp)+vec[idx],stock(idx+1,0,n,vec,dp));
}

//Tabulation
int stock(int n,vector<int>& vec,vector<vector<int>>& dp){
    for(int i=n-1;i>=0;i--){
        for(int j=0;j<2;j++){
            if(j)
                dp[i][j]=max(dp[i+1][0]-vec[i],dp[i+1][1]);
            else
                dp[i][j]=max(dp[i+1][1]+vec[i],dp[i+1][0]);
        }
    }
    return dp[0][1];
}

//Space optimization
int stock(int n,vector<int>& vec){
    vector<int> next(n+1,0),cur(n+1,0);
    for(int i=n-1;i>=0;i--){
        for(int j=0;j<2;j++){
            if(j)
                cur[j]=max(next[0]-vec[i],next[1]);
            else
                cur[j]=max(next[1]+vec[i],next[0]);
        }
        next=cur;
    }
    return next[1];
}


int main(){
    int n;
    cout<<"Enter the number of days: ";
    cin>>n;
    cout<<"Enter the stock values: ";
    vector<int> stocks(n);
    for(int i=0;i<n;i++)
        cin>>stocks[i];
    vector<vector<int>> dp(n+1,vector<int>(2,0));
    cout<<"The maximum profit is: "<<stock(n,stocks)<<endl;
}

//Memoization
//Time complexity: O(2*n)
//Space complexity: O(2*n)+O(n)

//Tabulation
//Time complexity: O(2*n)
//Space complexity: O(2*n)

//Space optimization
//Time complexity: O(2*n)
//Space complexity: O(n)