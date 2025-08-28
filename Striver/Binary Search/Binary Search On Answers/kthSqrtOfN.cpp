// Given two numbers N and M, find the Nth root of M. The Nth root of a number M is defined as a number X such that when X is raised to the power of N, it equals M. If the Nth root is not an integer, return -1.

#include<iostream>
#include<stdio.h>
#include<math.h>
using namespace std;

int main(){
    int n,k;
    cout<<"Enter the number and power: ";
    cin>>n>>k;
    int high=n,low=1;
    while(low<=high){
        int mid=low+(high-low)/2;
        int num=pow(mid,k);
        if(num==n){
            cout<<"The "<<k<<"th power of "<<mid<<" is "<<n<<endl;
            return 0;
        }else if(num>n){
            high=mid-1;
        }else{
            low=mid+1;
        }
    }
    cout<<n<<" cannot represented as "<<k<<"th power of "<<"any number\n";
    return 0;
}

// Time complexity: O(log(n)*k)
// Space complexity: O(1)