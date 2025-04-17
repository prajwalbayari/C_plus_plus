// Let us first understand what a bitonic subsequence means.

// A bitonic subsequence is a subsequence of an array in which the elements can be any of these three:

// First, increase till a point and then decrease.
// Goes on increasing (Longest increasing subsequence)
// Goes on decreasing (Longest decreasing subsequence)

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void LIS(vector<int>& arr,vector<int>& dp,int n){
    for(int i=0;i<n;i++){
        for(int j=i-1;j>=0;j--){
            if(arr[j]<arr[i] && dp[i]<=dp[j]) 
                dp[i]=dp[j]+1;
        }
    }
}

int bitonic(vector<int>& arr){
    int n=arr.size(),ans=-1;
    vector<int> dp1(n,1),dp2(n,1);
    LIS(arr,dp1,n);
    reverse(arr.begin(),arr.end());
    LIS(arr,dp2,n);
    for(int i=0;i<n;i++)
        ans=max(ans,dp1[i]+dp2[i]-1);
    return ans;
}

int main(){
    int n;
    cout<<"Enter the number of elements in the array: ";
    cin>>n;
    cout<<"Enter the array elements: ";
    vector<int> vec(n);
    for(int i=0;i<n;i++)
        cin>>vec[i];
    cout<<"The length of the longest bitonic subsequence in the given array is: "<<bitonic(vec);
}

//Time complexity : O(n*n)
//Space complexity : O(n)