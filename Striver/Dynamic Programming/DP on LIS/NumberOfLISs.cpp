// Given an array, ‘Arr’ of length ‘n’, count the number of longest increasing subsequences (LIS).

#include<iostream>
#include<vector>
using namespace std;

int subseq(vector<int>& arr){
    int n=arr.size(),ans=0,maxi=0;
    vector<int> dp(n,1),cnt(n,1);
    for(int i=0;i<n;i++){
        for(int j=0;j<i;j++){
            if(arr[j]<arr[i]){
                if(dp[j]+1==dp[i])
                    cnt[i]+=cnt[j];
                else if(1+dp[j]>dp[i])
                    dp[i]=dp[j]+1,cnt[i]=cnt[j];
            }
        }
        maxi=max(maxi,dp[i]);
    }
    for(int i=0;i<n;i++){
        if(dp[i]==maxi)
            ans+=cnt[i];
    }
    return ans;
}

int main(){
    int n;
    cout<<"Enter the size of the array: ";
    cin>>n;
    cout<<"Enter the array elements\n";
    vector<int> arr(n);
    for(int i=0;i<n;i++)
        cin>>arr[i];
    cout<<"The number of longest increasing subsequences is: "<<subseq(arr)<<endl;
}

//Time complexity : O(n*n)
//Space complexity : O(n)