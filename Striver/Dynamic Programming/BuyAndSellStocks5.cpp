// We are given an array Arr[] of length n. It represents the price of a stock on ‘n’ days. The following guidelines need to be followed:

// We can buy and sell the stock any number of times.
// In order to sell the stock, we need to first buy it on the same or any previous day.
// We can’t buy a stock again after buying it once. In other words, we first buy a stock and then sell it. After selling we can buy and sell again. But we can’t sell before buying and can’t buy before selling any previously bought stock.
// We can’t buy a stock on the very next day of selling it. This is the cooldown clause

#include<iostream>
#include<vector>
using namespace std;

//Memoization
int stock(int idx,int buy,vector<int>& vec,vector<vector<int>>& dp){
    if(idx>=vec.size())
        return 0;
    if(dp[idx][buy]!=-1)
        return dp[idx][buy];
    if(buy)
        return dp[idx][buy]=max(stock(idx+1,0,vec,dp)-vec[idx],stock(idx+1,1,vec,dp));
    return dp[idx][buy]=max(stock(idx+2,1,vec,dp)+vec[idx],stock(idx+1,0,vec,dp));
}

//Tabulation
int stock(int n,vector<int>& vec,vector<vector<int>>& dp){
    for(int i=n-1;i>=0;i--){
        dp[i][1]=max(dp[i+1][0]-vec[i],dp[i+1][1]);
        dp[i][0]=max(dp[i+2][1]+vec[i],dp[i+1][0]);
    }
    return dp[0][1];
}

int main(){
    int n;
    cout<<"Enter the number of days: ";
    cin>>n;
    vector<int> vec(n);
    cout<<"Enter the stock values: ";
    for(int i=0;i<n;i++)
        cin>>vec[i];
    vector<vector<int>> dp(n+2,vector<int>(2,0));
    cout<<"The maximum profit that can be obtained is: "<<stock(n,vec,dp)<<endl;
}

//Memoization
//Time complexity: O(2*n)
//Space complexity: O(2*n)+O(n)

//Tabulation
//Time complexity: O(2*n)
//Space complexity: O(2*n)