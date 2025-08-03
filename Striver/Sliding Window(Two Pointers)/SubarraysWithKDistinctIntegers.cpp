// Given an integer array find the total number of subarrays that have k distinct integers

#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

int subarrays(vector<int>& vec,int k){
    int l=0,r=0,cnt=0;
    unordered_map<int,int> mp;
    while(r<vec.size()){
        mp[vec[r]]++;
        while(mp.size()>k){
            mp[vec[l]]--;
            if(mp[vec[l]]==0)
                mp.erase(vec[l]);
            l++;
        }
        cnt=cnt+(r-l);
        r++;
    }
    return cnt;
}

int main(){
    int n;
    cout<<"Enter the size of the array: ";
    cin>>n;
    cout<<"Enter the array elements: ";
    vector<int> vec(n);
    for(int i=0;i<n;i++)
        cin>>vec[i];

    int k;
    cout<<"Enter the value of k: ";
    cin>>k;
    cout<<"The number if valid subarrays is: "<<subarrays(vec,k)-subarrays(vec,k-1)<<endl;
}

// Time complexity : O(2*n)
// Space complexity : O(n)