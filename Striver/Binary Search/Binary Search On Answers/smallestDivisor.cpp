// Given an array of integers nums and an integer limit as the threshold value, find the smallest positive integer divisor such that upon dividing all the elements of the array by this divisor, the sum of the division results is less than or equal to the threshold value.
// Each result of the division is rounded up to the nearest integer greater than or equal to that element.

#include<vector>
#include<iostream>
#include<stdio.h>
#include<cmath>
using namespace std;

int totalSum(vector<int>& vec,int num){
    int sum=0;
    for(int n:vec){
        sum=sum+ceil((double)n / num);
    }
    return sum;
}

int main(){
    int n,thresh;
    cout<<"Enter the number of elements and the threshold: ";
    cin>>n>>thresh;
    vector<int> nums(n);
    int low=1,high=0,ans=-1;
    cout<<"Enter the array elements: ";
    for(int i=0;i<n;i++){
        cin>>nums[i];
        high=max(high,nums[i]);
    }
    while(low<=high){
        int mid=low+(high-low)/2;
        if(totalSum(nums,mid)<=thresh){
            ans=mid;
            high=mid-1;
        }else{
            low=mid+1;
        }
    }
    if(ans==-1){
        cout<<"No such number found\n";
    }else{
        cout<<"Minimum divisor is: "<<ans<<endl;
    }
    return 0;
}

// Time complexity: O(n*log(k)) k is the maximum number in the array
// Space complexity: O(1)