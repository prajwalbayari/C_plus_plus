// Given a binary array nums and an integer goal. Return the number of non-empty subarrays with a sum goal.

#include<iostream>
#include<vector>
using namespace std;

int findSubarrays(int g,vector<int>& vec){
    int l=0,r=0,n=vec.size(),ans=0,cur=0;
    while(r<n){
        cur+=vec[r];
        while(cur>g){
            cur=cur-vec[l];
            l++;
        }
        ans=ans+(r-l);
        r++;
    }
    return ans;
}

int main(){
    int n;
    cout<<"Enter the size of the array: ";
    cin>>n;
    cout<<"Enter the array elements: ";
    vector<int> vec(n);
    for(int i=0;i<n;i++)
        cin>>vec[i];
    int g;
    cout<<"Enter the goal: ";
    cin>>g;
    if(g<0)
        cout<<"Number of subarrays is 0\n";
    else
        cout<<"The number of subarrays is: "<<findSubarrays(g,vec)-findSubarrays(g-1,vec)<<endl;
}

// Time complexity: O(2*2*n)
// Space complexity: O(1)