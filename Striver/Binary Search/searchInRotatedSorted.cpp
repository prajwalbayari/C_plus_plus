// Given an integer array nums, sorted in ascending order (with distinct values) and a target value k. The array is rotated at some pivot point that is unknown. Find the index at which k is present and if k is not present return -1.

#include<iostream>
#include<vector>
using namespace std;

int searchInRotatedSorted(int ele,vector<int>& vec){
    int high=vec.size()-1,low=0;
    while(low<=high){
        int mid=low+(high-low)/2;
        if(vec[mid]==ele)
            return mid;
        if(vec[low]<=vec[mid]){
            if(vec[low]<=ele && ele<=vec[mid])
                high=mid-1;      
            else   
                low=mid+1;
        }else{
            if(vec[mid]<=ele && vec[high]>=ele)
                low=mid+1;
            else
                high=mid-1;
        }
    }
    return -1;
}

int main(){
    int n;
    cout<<"Enter the size of the array: ";
    cin>>n;
    cout<<"Enter the array elements: ";
    vector<int> vec(n);
    for(int i=0;i<n;i++)
        cin>>vec[i];
    int ele;
    cout<<"Enter the element: ";
    cin>>ele;
    int idx=searchInRotatedSorted(ele,vec);
    if(idx==-1)
        cout<<"Element not found!\n";
    else
        cout<<"Element found at index: "<<idx<<endl;
    return 0;
}

//Time complexity: O(log(n))
//Space complexity: O(1)