// A monkey is given n piles of bananas, where the 'ith' pile has nums[i] bananas. An integer h represents the total time in hours to eat all the bananas.
// Each hour, the monkey chooses a non-empty pile of bananas and eats k bananas. If the pile contains fewer than k bananas, the monkey eats all the bananas in that pile and does not consume any more bananas in that hour.
// Determine the minimum number of bananas the monkey must eat per hour to finish all the bananas within h hours.

#include<vector>
#include<iostream>
#include<stdio.h>
using namespace std;

bool totalHours(vector<int>& piles,int n,int total){
    int tot=0;
    for(int num:piles){
        tot=tot+num/n+((num%n==0)?0:1);
        if(total<tot)
            return false;
    }
    return true;
}

int main(){
    int n,high=-1,tot;
    cout<<"Enter the number of piles: ";
    cin>>n;
    cout<<"Enter the number of bananas in each pile: ";
    vector<int> piles(n);
    for(int i=0;i<n;i++){
        cin>>piles[i];
        high=max(high,piles[i]);
    }
    cout<<"Enter the total hours: ";
    cin>>tot;
    int low=0,ans=high;
    while(low<=high){
        int mid=low+(high-low)/2;
        if(totalHours(piles,mid,tot)){
            ans=mid;
            high=mid-1;
        }else{
            low=mid+1;
        }
    }
    cout<<"The minimum bananas to be eaten in an hour is: "<<ans<<endl;
    return 0;
}

// Time complexity: O(n*log(k)) where k is maximum number in the array
// Space complexity: O(1)