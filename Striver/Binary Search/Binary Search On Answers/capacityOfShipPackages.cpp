// Given a list of weights and an integer days. Find out the minimum weight a ship has to carry
// every day to transfer all the weights.
// Note: you have to carry continuous weights

#include<iostream>
#include<vector>
using namespace std;

bool possibleToTrasnport(vector<int>& vec,int w,int days){
    int sum=0,cnt=1;
    for(int n:vec){
        if(sum+n>w){
            cnt++;
            sum=n;
        }else{
            sum+=n;
        }
    }
    return cnt<=days;
}

int main(){
    int n,days;
    cout<<"Enter the number of weights and the number of days: ";
    cin>>n>>days;
    vector<int> weights(n);
    int low=0,high=0,ans=0;
    cout<<"Enter the weights: "<<endl;
    for(int i=0;i<n;i++){
        cin>>weights[i];
        low=max(low,weights[i]);
        high+=weights[i];
    }

    while(low<=high){
        int mid=low+(high-low)/2;
        if(possibleToTrasnport(weights,mid,days)){
            ans=mid;
            high=mid-1;
        }else{
            low=mid+1;
        }
    }
    cout<<"Minimum weight to be carried is: "<<ans<<endl;
    return 0;
}

//Time complexity: O(n*log(k)) where k is difference between summation of weights and maximum weight value
// Space complexity: O(1)