// Given an integer array nums, return true if you can partition the array into two subsets such that the sum of the elements in both subsets is equal or false otherwise.

#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;

//Memoization
bool partition(int idx,int target,vector<int>& vec,vector<vector<bool>>& dp){
    if(idx==0)
        return target==vec[0];
    if(target==0)
        return true;
    if(dp[idx][target])
        return dp[idx][target];
    bool drop=partition(idx-1,target,vec,dp),pick=false;
    if(target>=vec[idx])
        pick=partition(idx-1,target-vec[idx],vec,dp);
    return dp[idx][target]=(drop || pick);
}

//Tabulation
bool partition(int target,vector<int>& vec,vector<vector<bool>>& dp){
    int n=vec.size();
    for(int i=0;i<n;i++)
        dp[i][0]=true;
    dp[0][vec[0]]=true;
    for(int i=1;i<n;i++){
        for(int j=1;j<=target;j++){
            bool drop=dp[i-1][j],take=false;
            if(j>=vec[i])
                take=dp[i-1][j-vec[i]];
            dp[i][j]=(drop||take);
        }
    }
    return dp[n-1][target];
}

//Space optimization
bool partition(int target,vector<int>& vec){
    int n=vec.size();
    vector<int> prev(target+1),cur(target+1);
    prev[0]=true,cur[0]=true;
    prev[vec[0]]=true;
    for(int i=1;i<n;i++){
        for(int j=1;j<=target;j++){
            bool drop=prev[j],take=false;
            if(j>=vec[i])
                take=prev[j-vec[i]];
            cur[j]=(drop||take);
        }
        prev=cur;
    }
    return prev[target];
}

int main(){
    int n,sum=0;
    cout<<"Enter the size of the array: ";
    cin>>n;
    vector<int> vec(n);
    cout<<"Enter the array elements\n";
    for(int i=0;i<n;i++){
        cin>>vec[i];
        sum+=vec[i];
    }
    if(sum%2!=0 || n==1){
        cout<<"\nIt is not possible to partition the array\n";
        return 0;
    }
    vector<vector<bool>> dp(n,vector<bool>(sum/2+1));
    if(partition(sum/2,vec))
        cout<<"\nIt is possible to partition the array\n";
    else
        cout<<"\nIt is not possible to partition the array\n";
    
    return 0;
}

//Memoization
//Time complexity: O(n*(sum/2+1))+O(n)
//Space complexity: O(n*(sum/2+1))+O(n)

//Memoization
//Time complexity: O(n*(sum/2+1))+O(n)
//Space complexity: O(n*(sum/2+1))

//Space optimization
//Time complexity: O(n*(sum/2+1))+O(n)
//Space complexity: O(sum/2+1)