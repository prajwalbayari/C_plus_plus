// Given an array of integers nums sorted in non-decreasing order, find the starting and ending position of a given target value. If the target is not found in the array, return [-1, -1].

#include<iostream>
#include<vector>
using namespace std;

void lowerBound(int ele,vector<int>& vec){
    int high=vec.size()-1,low=0,ans=vec.size();
    while(low<=high){
        int mid=low+(high-low)/2;
        if(vec[mid]>=ele){
            ans=mid;
            high=mid-1;
        }else   
            low=mid+1;
    }
    if(ans!=vec.size() && (vec[ans]==ele ||(ans!=0 && vec[ans-1]==ele)))
        cout<<"First occurence index of elements is: "<<ans<<endl;
    else
        cout<<"No occurence of element in array"<<endl;
}

void upperBound(int ele,vector<int>& vec){
    int high=vec.size()-1,low=0,ans=vec.size();
    while(low<=high){
        int mid=low+(high-low)/2;
        if(vec[mid]>ele){
            ans=mid;
            high=mid-1;
        }else   
            low=mid+1;
    }
    if(ans!=0 && vec[ans-1]==ele)
        cout<<"Last occurence index of elements is: "<<ans-1<<endl;
    else
        cout<<"No occurence of element in array"<<endl;
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
    lowerBound(ele,vec);
    upperBound(ele,vec);
}

// Time complexity: O(2*log(n))
// Space complexity: O(1)

//Similar to number of occurences of a number in an array (return the result of subtraction of last index and first index)