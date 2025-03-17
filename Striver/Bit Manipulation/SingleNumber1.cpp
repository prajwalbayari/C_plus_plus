//Given an array with size n where n/2 elements are repeated twice print the number that is unique

#include<iostream>
using namespace std;

int main(){
    int n,ans=0;
    cout<<"Enter the size of the array: ";
    cin>>n;
    cout<<"Enter the array elements\n";
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        ans=ans^a;
    }
    cout<<"The unique number in the array is: "<<ans<<endl;
}