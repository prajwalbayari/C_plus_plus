// A thief wants to rob a store. He is carrying a bag of capacity W. The store has ‘n’ items of infinite supply. Its weight is given by the ‘wt’ array and its value by the ‘val’ array. He can either include an item in its knapsack or exclude it but can’t partially have it as a fraction. We need to find the maximum value of items that the thief can steal. He can take a single item any number of times he wants and put it in his knapsack.

#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;

//Memoization
int unboundedKnapsack(int idx,int capacity,vector<int>& weight,vector<int>& value,vector<vector<int>>& dp){
    if(capacity==0 || idx<0)
        return 0;
    if(dp[idx][capacity]!=-1)
        return dp[idx][capacity];
    int drop=unboundedKnapsack(idx-1,capacity,weight,value,dp),take=0;
    if(capacity>=weight[idx])
        take=unboundedKnapsack(idx,capacity-weight[idx],weight,value,dp)+value[idx];
    return dp[idx][capacity]=max(drop,take);
}

//Tabulation
int unboundedKnapsack(int capacity,vector<int>& weight,vector<int>& value,vector<vector<int>>& dp){
    int n=weight.size();
    for(int i=0;i<=capacity;i++)
        dp[0][i]=(i/weight[0])*value[0];
    
    for(int i=1;i<n;i++){
        for(int j=0;j<=capacity;j++){
            int drop=dp[i-1][j],take=0;
            if(j>=weight[i])
                take=dp[i][j-weight[i]]+value[i];
            dp[i][j]=max(drop,take);
        }
    }
    return dp[n-1][capacity];
}

//Space optimization
int unboundedKnapsack(int capacity,vector<int>& weight,vector<int>& value){
    int n=weight.size();
    vector<int> prev(capacity+1,0),cur(capacity+1,0);
    for(int i=0;i<=capacity;i++)
        prev[i]=(i/weight[0])*value[0];
    
    for(int i=1;i<n;i++){
        for(int j=0;j<=capacity;j++){
            int drop=prev[j],take=0;
            if(j>=weight[i])
                take=cur[j-weight[i]]+value[i];
            cur[j]=max(drop,take);
        }
        prev=cur;
    }
    return prev[capacity];
}

int main(){
    int n,capacity;
    cout<<"Enter the number of items: ";
    cin>>n;
    vector<int> weight(n),value(n);
    cout<<"Enter the weight and value of each item\n";
    for(int i=0;i<n;i++)
        cin>>weight[i]>>value[i];
    cout<<"Enter the capacity of the Knapsack: ";
    cin>>capacity;
    vector<vector<int>> dp(n,vector<int>(capacity+1,0));
    cout<<"The maximum value that can be obtained is: "<<unboundedKnapsack(capacity,weight,value);
}