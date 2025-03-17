//Given an array containing 2 unique elements and all other elements occuring twice return the unique elements

#include<iostream>
#include<vector>
using namespace std;

void singleNumber3(vector<int> arr){
    int n=arr.size(),ans=0;
    for(int i=0;i<n;i++)
        ans=ans^arr[i];
    
    int rightMost=((ans&(ans-1))^ans);
    int setBit=0,notSet=0;
    for(int i=0;i<n;i++){
        if(rightMost&arr[i])
            setBit=setBit^arr[i];
        else
            notSet=notSet^arr[i];
    }

    cout<<"The two unique numbers are: "<<setBit<<" "<<notSet<<endl;
}

int main(){
    int n;
    cout<<"Enter the size of the array: ";
    cin>>n;
    vector<int> arr(n);
    cout<<"Enter the array elements: ";
    for(int i=0;i<n;i++)   
        cin>>arr[i];

    singleNumber3(arr);
}

//Time complexity : O(2*n) 