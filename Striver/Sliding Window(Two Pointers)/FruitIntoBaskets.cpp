// There is only one row of fruit trees on the farm, oriented left to right. An integer array called fruits represents the trees, where fruits[i] denotes the kind of fruit produced by the ith tree.
// The goal is to gather as much fruit as possible, adhering to the owner's stringent rules:
// 1) There are two baskets available, and each basket can only contain one kind of fruit. The quantity of fruit each basket can contain is unlimited.
// 2) Start at any tree, but as you proceed to the right, select exactly one fruit from each tree, including the starting tree. One of the baskets must hold the harvested fruits.
// 3) Once reaching a tree with fruit that cannot fit into any basket, stop.
// Return the maximum number of fruits that can be picked.

#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

int optimized(vector<int>& vec){
    int n=vec.size(),l=0,r=0,ans=0;
    unordered_map<int,int> mp;
    while(r<n){
        mp[vec[r]]++;
        if(mp.size()==3){
            mp[vec[l]]--;
            if(mp[vec[l]]==0){
                mp.erase(vec[l]);
                l++;
            }else{
                l++;
                continue;
            }
        }
        int temp=0;
        for(auto it:mp)
            temp+=it.second;
        
        ans=max(ans,temp);
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
    
    unordered_map<int,int> mp;
    int left=0,right=0,ans=0;
    while(right<n){
        mp[vec[right]]++;
        while(mp.size()==3){
            mp[vec[left]]--;
            if(mp[vec[left]]==0)
                mp.erase(vec[left]);
            left++;
        }
        int temp=0;
        for(auto ele:mp)
            temp+=ele.second;
        ans=max(ans,temp);
        right++;
    }

    cout<<"The maximum answer is: "<<ans<<endl;
    cout<<"(Optimized)The maximum answer is: "<<ans<<endl;
}

// Time complexity: O(n+n)
// Space complexity: O(3)

// Optimized
// Time complexity: O(n+n)
// Space complexity: O(3)