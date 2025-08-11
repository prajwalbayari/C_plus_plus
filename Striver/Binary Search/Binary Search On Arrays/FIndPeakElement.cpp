// Given an array arr of integers. A peak element is defined as an element greater than both of its neighbors.
// Formally, if arr[i] is the peak element, arr[i - 1] < arr[i] and arr[i + 1] < arr[i].
// Find the index(0-based) of a peak element in the array. If there are multiple peak numbers, return the index of any peak number.
// Note:
// As there can be many peak values, 1 is given as output if the returned index is a peak number, otherwise 0.

#include<iostream>
#include<vector>
using namespace std;

int main(){
    int n;
    cout<<"Enter the size of the array: ";
    cin>>n;
    vector<int> vec(n);
    cout<<"Enter the array elements: ";
    for(int i=0;i<n;i++)
        cin>>vec[i];
    
    if(n==0 || vec[0]>vec[1]){
        cout<<"Peak element is: "<<vec[0];
        return 0;
    }
    if(vec[n-1]>vec[n-2]){
        cout<<"Peak element is: "<<vec[n-1];
        return 0;
    }

    int low=1,high=n-2;
    while(low<=high){
        int mid=low+(high-low)/2;
        if(vec[mid-1]<vec[mid] && vec[mid]>vec[mid+1]){
            cout<<"Peak element is: "<<vec[mid];
            break;
        }
        if(vec[mid]>vec[mid-1]){
            low=mid+1;
        }else if(vec[mid]>vec[mid+1])
            high=mid-1;
        else
            low=mid+1; // Can also write high=mid-1;
    }
    return 0;
}

// Time complexity: O(log(n))
// Space complexity: O(1)