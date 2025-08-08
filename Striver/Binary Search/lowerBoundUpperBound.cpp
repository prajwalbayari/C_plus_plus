#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// Given a sorted array of nums and an integer x, write a program to find the lower bound of x.
// The lower bound algorithm finds the first and smallest index in a sorted array where the value at that index is greater than or equal to a given key i.e. x.
// If no such index is found, return the size of the array.
void LowerBound(vector<int>& vec,int ele){
    int low=0,high=vec.size()-1,ans=vec.size();
    while(high>=low){
        int mid=low+(high-low)/2;
        if(vec[mid]>=ele){
            ans=mid;
            high=mid-1;
        }else{
            low=mid+1;
        }
    }
    cout<<"Lower bound of element found at index: "<<ans<<endl;
}
// Time complexity: O(log(n))
// Space complexity: O(1)


// Given a sorted array of nums and an integer x, write a program to find the upper bound of x.
// The upper bound algorithm finds the first and smallest index in a sorted array where the value at that index is greater than a given key i.e. x.
// If no such index is found, return the size of the array.
void UpperBound(vector<int>& vec,int ele){
    int low=0,high=vec.size()-1,ans=vec.size();
    while(high>=low){
        int mid=low+(high-low)/2;
        if(vec[mid]>ele){
            ans=mid;
            high=mid-1;
        }else{
            low=mid+1;
        }
    }
    cout<<"Upper bound of element found at index: "<<ans<<endl;
}
// Time complexity: O(log(n))
// Space complexity: O(1)

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
    UpperBound(vec,key);
}