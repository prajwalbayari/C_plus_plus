// Given n roses and an array nums where nums[i] denotes that the 'ith' rose will bloom on the nums[i]th day, only adjacent bloomed roses can be picked to make a bouquet. Exactly k adjacent bloomed roses are required to make a single bouquet. Find the minimum number of days required to make at least m bouquets, each containing k roses. Return -1 if it is not possible.

#include<vector>
#include<iostream>
#include<stdio.h>
using namespace std;

bool isPossible(vector<int>& vec,int num,int day,int flo){
    int cnt=0;
    for(int n:vec){
        if(n<=day){
            cnt++;
            if(cnt==flo){
                cnt=0;
                num--;
                if(num==0)
                    return true;
            }
        }else
            cnt=0;
    }
    return false;
}

int main(){
    int n,b,adj;
    cout<<"Enter the number of roses, number of boquets and number of adjacent roses required to make each boquet: ";
    cin>>n>>b>>adj;
    if(b*adj>n){
        cout<<"Not possible to make all boquets\n";
    }
    cout<<"Enter the bloom day of each flower: ";
    vector<int> vec(n);
    int low,high,ans=-1;
    for(int i=0;i<n;i++){
        cin>>vec[i];
        high=max(high,vec[i]);
        low=min(low,vec[i]);
    }

    while(low<=high){
        int mid=low+(high-low)/2;
        if(isPossible(vec,b,mid,adj)){
            ans=mid;
            high=mid-1;
        }else{
            low=mid+1;
        }
    }
        cout<<"Minimum number of days required to make all boquets is: "<<ans<<endl;
    return 0;
}

// Time complexity: O(n*log(k)) where k is the difference between maximum and minimum blooming day
// Space complexity: O(1)