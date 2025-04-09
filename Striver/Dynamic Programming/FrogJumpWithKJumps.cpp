//Improvized Frog jump you can jump upto k stairs 

#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;

//Memoization
int minEnergy(int idx,int k,vector<int>& vec,vector<int>& dp){
    if(idx==0)   
        return 0;
    if(dp[idx]!=-1)
        return dp[idx];
    int minSteps=INT_MAX;
    for(int i=1;i<=k;i++){
        if(idx-i>=0){
            int cur=minEnergy(idx-i,k,vec,dp)+abs(vec[idx]-vec[idx-i]);
            minSteps=min(minSteps,cur);
        }
    }
    return dp[idx]=minSteps;
}

int minEnergy(int k,vector<int>& vec,vector<int>& dp){
    dp[0]=0;
    int n=vec.size();
    for(int i=1;i<n;i++){
        int minPts=INT_MAX;
        for(int j=1;j<=k && i-j>=0;j++){
            minPts=min(minPts,dp[i-j]+abs(vec[i]-vec[i-j]));
        }
        dp[i]=minPts;
    }
    return dp[n-1];
}

int main(){
    int n,k;
    cout<<"Enter the number of steps: ";
    cin>>n;
    cout<<"Enter the stair heights: ";
    vector<int> vec(n);
    for(int i=0;i<n;i++)
        cin>>vec[i];
    cout<<"Enter the value of k: ";
    cin>>k;
    vector<int> dp(n+1,-1);
    cout<<"The minimum energy for frog to reach top is: "<<minEnergy(k,vec,dp);
}

//Memoization
//Time complexity: O(n)*k
//Space complexity: O(n)+O(n)

//Tabulation
//Time complexity: O(n)*k
//Space complexity: O(n)