// In the coming articles, we will discuss problems related to ‘Longest Increasing Subsequence’. Before proceeding further, let us understand the “Longest Increasing Subsequence”, or rather what is a “subsequence”?

// A subsequence of an array is a list of elements of the array where some elements are deleted ( or not deleted at all) and they should be in the same order in the subsequence as in the original array.

// For example, for the array: [2,3,1] , the subsequences will be [{2},{3},{1},{2,3},{2,1},{3,1},{2,3,1}} but {3,2} is not a subsequence because its elements are not in the same order as the original array.

// What is the Longest Increasing Subsequence?

// The longest increasing subsequence is described as a subsequence of an array where:

// All elements of the subsequence are in increasing order.
// This subsequence itself is of the longest length possible.

#include<iostream>
#include<vector>
using namespace std;

//Memoization
int subseq(int idx,int prev,vector<int>& arr,vector<vector<int>>& dp){
    if(idx==arr.size())
        return 0;
    if(dp[idx][prev]!=-1)
        return dp[idx][prev];
    int leave=subseq(idx+1,idx,arr,dp);
    int dont=subseq(idx+1,prev,arr,dp);
    if(arr[idx]>arr[prev])
        leave++;
    return dp[idx][prev]=max(leave,dont);
}

//Tabulation
int subseq(vector<int>& arr,vector<vector<int>>& dp){
    int n=arr.size();
    for(int i=n-1;i>=0;i--){
        for(int j=i-1;j>=-1;j--){
            if(j==-1 || arr[i]>arr[j])
                dp[i][j+1]=max(dp[i+1][i+1]+1,dp[i+1][j+1]);
            else
                dp[i][j+1]=dp[i+1][j+1];
        }
    }
    return dp[0][0];
}

//Space optimization
int subseq(vector<int>& arr){
    int n=arr.size();
    vector<int> prev(n+1,0),cur(n+1,0);
    for(int i=n-1;i>=0;i--){
        for(int j=i-1;j>=-1;j--){
            if(j==-1 || arr[i]>arr[j])
                cur[j+1]=max(prev[i+1]+1,prev[j+1]);
            else
                cur[j+1]=prev[j+1];
        }
        prev=cur;
    }
    return cur[0];
}
 
//Algorithm to print LIS
int algo(vector<int>& vec){
    int n=vec.size(),ans=-1,last=0;
    vector<int> dp(n,1),hash(n);
    for(int i=0;i<n;i++){
        hash[i]=i;
        for(int j=i-1;j>=0;j--){
            if(vec[j]<vec[i] && dp[i]<dp[j]+1)
                dp[i]=dp[j]+1,hash[i]=j;
        }
        if(dp[i]>ans)
            ans=dp[i],last=i;
    }
    vector<int> fin;
    fin.push_back(vec[last]);
    while(last!=hash[last]){
        last=hash[last];
        fin.push_back(vec[last]);
    }

    cout<<"The longest increasing subsequence is: ";
    for(int i=ans-1;i>=0;i--)
        cout<<fin[i]<<" ";
    cout<<endl;
}

int main(){
    int n;
    cout<<"Enter the number of elements in the array: ";
    cin>>n;
    cout<<"Enter the array elements: ";
    vector<int> vec(n);
    for(int i=0;i<n;i++)
        cin>>vec[i];
    vector<vector<int>> dp(n+1,vector<int>(n+1,0));
    algo(vec);
    // cout<<"The length of the longest increasing subsequence is: "<<algo(vec)<<endl;
}

//Memoization
//Time complexity: O(n*n)
//Space complexity: O(n*n)+O(n)

//Tabulation
//Time complexity: O(n*n)
//Space complexity: O(n*n)