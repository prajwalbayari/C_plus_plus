// Given a sorted array of integers nums with 0-based indexing, find the index of a specified target integer. If the target is found in the array, return its index. If the target is not found, return -1.

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// Time complexity: O(log(n))
// Space complexity: O(1)
void iterative(vector<int>& vec,int ele){
    int low=0,high=vec.size()-1;
    while(high>=low){
        int mid=low+(high-low)/2;
        if(vec[mid]==ele){
            cout<<"Element found at index: "<<mid<<endl;
            return;
        }else if(ele>vec[mid])
        low=mid+1;
        else 
        high=mid-1;
    }
    cout<<"Element not found!\n";
}

// Time complexity: O(log(n))
// Space complexity: O(log(1))
int recursive(vector<int>& vec,int ele,int low,int high){
    if(low>high)
        return -1;
    int mid=low+(high-low)/2;
    if(vec[mid]==ele)
        return mid;
    else if(vec[mid]<ele)
        return recursive(vec,ele,mid+1,high);
    return recursive(vec,ele,low,mid-1);
}

int main(){
    int n;
    cout<<"Enter the size of the array: ";
    cin>>n;
    vector<int> vec(n);
    cout<<"Enter array elements in sorted order: ";
    for(int i=0;i<n;i++)
        cin>>vec[i];

    int key;
    cout<<"Enter the element to search: ";
    cin>>key;
    iterative(vec,key);
    // if(recursive(vec,key,0,n-1)==-1){
    //     cout<<"Element not found\n";
    // }else{
    //     cout<<"Element found\n";
    // }
}