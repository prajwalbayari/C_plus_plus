// We are given an array Arr[] of length n. It represents the price of a stock on ‘n’ days. The following guidelines need to be followed:

// We can buy and sell the stock any number of times.
// In order to sell the stock, we need to first buy it on the same or any previous day.
// We can’t buy a stock again after buying it once. In other words, we first buy a stock and then sell it. After selling we can buy and sell again. But we can’t sell before buying and can’t buy before selling any previously bought stock.
// We can do at most 2 transactions.

#include<iostream>
#include<vector>
using namespace std;

//Memoization
int stock(int idx,int buy,int n,int cnt,vector<int>& vec,vector<vector<vector<int>>>& dp){
    if(cnt==2 || idx==n)
        return 0;
    if(dp[idx][buy][cnt]!=-1)
        return dp[idx][buy][cnt];
    if(buy)
        return dp[idx][buy][cnt]=max(stock(idx+1,0,n,cnt,vec,dp)-vec[idx],stock(idx+1,1,n,cnt,vec,dp));
    return dp[idx][buy][cnt]=max(stock(idx+1,1,n,cnt+1,vec,dp)+vec[idx],stock(idx+1,0,n,cnt,vec,dp));
}

//Tabulation
int stock(int n,vector<int>& vec,vector<vector<vector<int>>>& dp){
    for(int i=n-1;i>=0;i--){
        for(int j=0;j<2;j++){
            for(int k=1;k<3;k++){
                if(j)
                    dp[i][j][k]=max(dp[i+1][0][k]-vec[i],dp[i+1][1][k]);
                else
                    dp[i][j][k]=max(dp[i+1][1][k-1]+vec[i],dp[i+1][0][k]);
            }
        }
    }
    return dp[0][1][2];
}

//Space optimization
int stock(int n,vector<int>& vec){
    vector<vector<int>> ahead(2,vector<int>(3,0)),cur(2,vector<int>(3,0));
    for(int i=n-1;i>=0;i--){
        for(int j=0;j<2;j++){
            for(int k=1;k<3;k++){
                if(j)
                    cur[j][k]=max(ahead[0][k]-vec[i],ahead[1][k]);
                else
                    cur[j][k]=max(ahead[1][k-1]+vec[i],ahead[0][k]);
            }
        }
        ahead=cur;
    }
    return ahead[1][2];
}

int main(){
    int n;
    cout<<"Enter the number of days: ";
    cin>>n;
    vector<int> vec(n);
    cout<<"Enter the values of the stocks\n";
    for(int i=0;i<n;i++)
        cin>>vec[i];
    vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(2,vector<int>(3,0)));
    cout<<"The maximum profit is: "<<stock(n,vec);
}

//Memoiztion
//Time complexity: O(n*6)
//Space complexity: O(n*6)+O(n)

//Tabulation
//Time complexity: O(n*6)
//Space complexity: O(n*6)

//Space optimization
//Time complexity: O(n*6)
//Space complexity: O(6)