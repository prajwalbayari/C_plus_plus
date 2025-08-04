//Jump game 1

// Given an array of integers nums, each element in the array represents the maximum jump length at that position. 
// Initially starting at the first index of the array, determine if it is possible to reach the last index. 
// Return true if the last index can be reached, otherwise return false.

//Jump game 2

//Find minimum jumps to reach the end (It is guaranteed that an answer exists)

#include<iostream>
#include<vector>
using namespace std;

void jumpGame1(vector<int>& vec){
    int maxIdx=0,n=vec.size();
    for(int i=0;i<n;i++){
        if(maxIdx<i){
            cout<<"Not possible to reach the end\n";
            return;
        }
        maxIdx=max(maxIdx,vec[i]+i);
    }
    cout<<"Possible to reach the end\n";
}

int jumpGame2Recurse(vector<int>& vec,int idx){
    if(idx>=vec.size()-1)
        return 0;
    int ans=1e9;
    for(int i=1;i<=vec[idx];i++){
        ans=min(ans,jumpGame2Recurse(vec,idx+i));
    }
    return ans+1;
}

void jumpGame2Iterative(vector<int>& vec){
    int n=vec.size(),ans=0,l=0,r=0;
    while(r<n-1){
        int farthest=0;
        for(int i=l;i<=r;i++)
            farthest=max(farthest,i+vec[i]);
        
        l=r+1,r=farthest;
        ans++;
    }
    cout<<"Minimum number of jumps to reach goal is: "<<ans<<endl;
}

int main(){
    int n;
    cout<<"Enter the size of the array: ";
    cin>>n;
    vector<int> vec(n);
    cout<<"Enter the array elements: ";
    for(int i=0;i<n;i++)
        cin>>vec[i];
    // jumpGame1(vec);
    cout<<"Minimum number of jumps to reach goal is: "<<jumpGame2Recurse(vec,0)<<endl;
    // jumpGame2Iterative(vec);
    return 0;
}

// Jump game 1
// Time complexity: O(n)
// Space complexity: O(1)

// Jump game 2
// Recursion
// Time complexity: O(n^n)
// Space complexity: O(n)

// Iterative
// Time complexity: O(n)
// Space complexity: O(1)