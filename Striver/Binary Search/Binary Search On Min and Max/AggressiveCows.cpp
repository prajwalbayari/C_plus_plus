// Given an array nums of size n, which denotes the positions of stalls, and an integer k, which denotes the number of aggressive cows, assign stalls to k cows such that the minimum distance between any two cows is the maximum possible. Find the maximum possible minimum distance.

#include<vector>
#include<iostream>
#include<stdio.h>
#include<algorithm>
using namespace std;

bool possible(vector<int>& pos,int dis,int c){
    int cnt=1,prev=0;
    for(int i=1;i<pos.size();i++){
        if(pos[i]-pos[prev]>=dis){
            cnt++;
            prev=i;
        }
    }
    return cnt>=c;
}

int main(){
    int n,c;
    cout<<"Enter the number of stalls and number of cows: ";
    cin>>n>>c;
    vector<int> pos(n);
    cout<<"Enter the positions of the stalls: ";
    for(int i=0;i<n;i++)
        cin>>pos[i];
    sort(pos.begin(),pos.end());
    int low=0,high=pos[n-1]-pos[0];
    while(low<=high){
        int mid=low+(high-low)/2;
        if(possible(pos,mid,c)){
            low=mid+1;
        }else{
            high=mid-1;
        }
    }
    cout<<"The maximized minimum distance is: "<<high<<endl;
}

// Time complexity: O(n*log(k)) k is difference between highest and lowest possible positions
// Space complexity: O(1)