// Given an integer array a of size n and an integer k. Split the array a into k non-empty subarrays such that the largest sum of any subarray is minimized. Return the minimized largest sum of the split.

#include<iostream>
#include<stdio.h>
#include<vector>
using namespace std;

bool isFeasible(vector<int>& vec,int thresh,int k){
    int sum=0,cnt=1;
    for(int i=0;i<vec.size();i++){
        if(sum+vec[i]>thresh){
            cnt++;
            sum=vec[i];
        }else{
            sum+=vec[i];
        }
        if(cnt>k)
            return false;
    }
    return true;
}
int main(){
    int n,k,low=0,high=0;
    cout<<"Enter the size of array and number of painters: ";
    cin>>n>>k;
    cout<<"Enter the paint array: ";
    vector<int> vec(n);
    for(int i=0;i<n;i++){
        cin>>vec[i];
        low=max(low,vec[i]);
        high+=vec[i];
    }
    while(low<=high){
        int mid=low+(high-low)/2;
        if(isFeasible(vec,mid,k)){
            high=mid-1;
        }else{
            low=mid+1;
        }
    }
    cout<<"The minimized largest sum is: "<<low<<endl;
    return 0;
}

// Time complexity: O(n*log(sum of array))
// Space complexity: O(1)