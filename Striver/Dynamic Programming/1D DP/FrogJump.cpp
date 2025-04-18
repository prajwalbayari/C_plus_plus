//Given a array heights that represent the heights of the cosecutive stairs the frog can jump
//from one stair to ith or (i+1)th stair find it will take height[j]-height[cur] energy to
//jump to the stair where cur is the current stair and j is the stair we are about to jump to
//Find the minimum energy needed to reach the last stair

#include<iostream>
#include<vector>
using namespace std;

//Memoization
int minEnergy(int idx,vector<int>& vec,vector<int>& dp){
    if(dp[idx]!=-1)
        return dp[idx];
    if(idx==0)
        return dp[idx]=0;
    if(idx==1)
        return dp[idx]=abs(vec[0]-vec[1]);
    int step1=minEnergy(idx-1,vec,dp)+abs(vec[idx]-vec[idx-1]);
    int step2=minEnergy(idx-2,vec,dp)+abs(vec[idx]-vec[idx-2]);
    return dp[idx]=min(step1,step2);
}

//Tabulation
int MinEnergy(int n,vector<int>& vec,vector<int>& dp){
    dp[0]=0;
    for(int i=1;i<n;i++){
        int step1=dp[i-1]+abs(vec[i]-vec[i-1]),step2=1e9;
        if(i>1)
            step2=dp[i-2]+abs(vec[i]-vec[i-2]);
        dp[i]=min(step1,step2);
    }

    return dp[n-1];
}

//Optimized
int MinEnergy(int n,vector<int>& vec){
    int temp1=0,temp2=0;
    for(int i=1;i<n;i++){
        int t1=temp1+abs(vec[i]-vec[i-1]),t2=1e9;
        if(i>1)
            t2=temp2+abs(vec[i]-vec[i-2]);
        temp2=temp1;
        temp1=min(t1,t2);
    }

    return temp1;
}

int main(){
    int n;
    cout<<"Enter the number of stairs: ";
    cin>>n;
    cout<<"Enter the heights of the stairs: ";
    vector<int> vec(n);
    vector<int> dp(n+1,0); //Initialize -1 for memoization and 0 for tabulation
    for(int i=0;i<n;i++)
        cin>>vec[i];
    cout<<"The minimum energy required to reach the goal is: "<<MinEnergy(n,vec)<<endl;
}

//Memoization
//Time complexity: O(n)
//Space complexity: O(n)+O(n)

//Tabbulation
//Time complexity: O(n)
//Space complexity: O(n)

//Optimized
//Time complexity: O(n)
//Space complexity: O(1)