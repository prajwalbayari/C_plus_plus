// Given an sorted array find the kth missing positive number in it

#include<iostream>
#include<vector>
using namespace std;

int main(){
    int n,k;
    cout<<"Enter the size of the array and the value of k: ";
    cin>>n>>k;
    vector<int> vec(n);
    cout<<"Enter the array elements: ";
    for(int i=0;i<n;i++){
        cin>>vec[i];
    }
    int low=0,high=n-1;
    while(low<=high){
        int mid=low+(high-low)/2;
        int missing=vec[mid]-(mid+1);
        if(missing>k){
            high=mid-1;
        }else{
            low=mid+1;
        }
    }
    cout<<"The missing number is: "<<low+k<<endl; //high+1+low is also valid
}

// Time complexity: O(log(n))
// Space complexity: O(1)