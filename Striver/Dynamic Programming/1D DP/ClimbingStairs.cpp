//Given a number of stairs (n) in a single jump you can climb down 1 or 2 stairs find the total
//number of ways to climb down the stairs 1<=n<=10^18

#include<iostream>
#include<vector>
using namespace std;

int stairs(int n,vector<int>& dp){
    if(n==0 || n==1)
        return n;
    if(dp[n]!=-1)
        dp[n];
    return dp[n]=stairs(n-1,dp)+stairs(n-2,dp);
}

int main(){
    int n;
    cout<<"Enter the number of stairs: ";
    cin>>n;
    vector<int> dp(n+1,-1);
    cout<<"The total number of ways to climb down the stairs is: "<<stairs(n,dp);
}

//Memoization
//Time compelxity: O(n)
//Space complexity: O(n)+O(n)