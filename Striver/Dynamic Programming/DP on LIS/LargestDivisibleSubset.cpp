// Given an array with distinct elements, we need to print its longest divisible subset. We can print any answer.

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void divisible(vector<int>& arr){
    int n=arr.size(),ans=1,last=0;
    vector<int> dp(n,1),hash(n,0);
    sort(arr.begin(),arr.end());
    for(int i=1;i<n;i++){
        hash[i]=i;
        for(int j=i-1;j>=0;j--){
            if(arr[i]%arr[j]==0 && dp[j]>=dp[i]){
                dp[i]=dp[j]+1;
                hash[i]=j;
            }
        }
        if(dp[i]>ans){
            ans=dp[i];
            last=i;
        }
    }

    vector<int> fin;
    cout<<"The longest divisible subset is: ";
    cout<<arr[last]<<" ";
    while(last!=hash[last]){
        last=hash[last];
        cout<<arr[last]<<" ";
    }
    cout<<endl;
}

int main(){
    int n;
    cout<<"Enter the size of the array: ";
    cin>>n;
    cout<<"Enter the array elements: ";
    vector<int> arr(n);
    for(int i=0;i<n;i++)
        cin>>arr[i];
    divisible(arr);
}

//Time complexity: O(n*n)
//Space complexity: O(n)