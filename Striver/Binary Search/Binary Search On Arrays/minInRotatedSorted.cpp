// Given an integer array nums of size N, sorted in ascending order with distinct values, and then rotated an unknown number of times (between 1 and N), find the minimum element in the array.

#include<iostream>
#include<vector>
using namespace std;

void minInRotatedSorted(vector<int>& vec){
    int low=0,high=vec.size()-1,ans=1e9;
    while(low<=high){
        if(vec[low]<=vec[high]){
            ans=min(ans,vec[low]);
            break;
        }
        int mid=low+(high-low)/2;
        if(vec[low]<=vec[mid]){
            ans=min(ans,vec[low]);
            low=mid+1;
        }else if(vec[mid]<=vec[high]){
            ans=min(ans,vec[mid]);
            high=mid-1;
        }
    }
    cout<<"The minimum number in the array is: "<<ans<<endl;
}

int main(){
    int n;
    cout<<"Enter the size of the array: ";
    cin>>n;
    vector<int> vec(n);
    cout<<"Enter array elements in sorted order: ";
    for(int i=0;i<n;i++)
        cin>>vec[i];

    minInRotatedSorted(vec);
    return 0;
}

// Time complexity: O(log(n))
// Space complexity: O(1)