// Given an array nums sorted in non-decreasing order. Every number in the array except one appears twice. Find the single number in the array.

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
    if(n==0){
        cout<<"The single number is: "<<vec[0]<<endl;
        return 0;
    }
    if(vec[0]!=vec[1]){
        cout<<"The single number is: "<<vec[0]<<endl;
        return 0;
    }
    if(vec[n-2]!=vec[n-1]){
        cout<<"The single number is: "<<vec[n-1]<<endl;
        return 0;
    }
    
    int low=1,high=n-2;
    while(low<=high){
        int mid=low+(high-low)/2;
        if(vec[mid-1]!=vec[mid] && vec[mid]!=vec[mid+1]){
            cout<<"The single number is: "<<vec[mid]<<endl;
            break;
        }
        if((mid%2!=0 && vec[mid-1]==vec[mid]) || (mid%2==0 && vec[mid+1]==vec[mid]))
            low=mid+1;
        else
            high=mid-1;
    }
    return 0;
}

//Time complexity: O(log(n))
//Space complexity: O(1)