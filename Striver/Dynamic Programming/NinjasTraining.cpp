// A Ninja has an ‘N’ Day training schedule. He has to perform one of these three activities
// (Running, Fighting Practice, or Learning New Moves) each day. There are merit points 
// associated with performing an activity each day. The same activity can’t be performed on 
// two consecutive days. We need to find the maximumimum merit points the ninja can attain in N Days.

// We are given a 2D Array POINTS of size ‘N*3’ which tells us the merit point of specific 
// activity on that particular day. Our task is to calculate the maximum number of merit 
// points that the ninja can earn.

#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;

//Memoization
int ninjaTraining(int idx,int last,vector<vector<int>>& train,vector<vector<int>>& dp){
    if(dp[idx][last]!=-1)
        return dp[idx][last];
    if(idx==0){
        int maximum=0;
        for(int i=0;i<3;i++){
            if(i!=last)
                maximum=max(maximum,train[0][i]);
        }
        return dp[idx][last]=maximum;
    }
    int maximum=0;
    for(int i=0;i<3;i++){
        if(i!=last){
            maximum=max(maximum,ninjaTraining(idx-1,i,train,dp)+train[idx][i]);
        }
    }
    return dp[idx][last]=maximum;
}

//Tabulation
int ninjaTraining(int n,vector<vector<int>>& train,vector<vector<int>>& dp){
    dp[0][0]=max(train[0][1],train[0][2]);
    dp[0][1]=max(train[0][0],train[0][2]);
    dp[0][2]=max(train[0][0],train[0][1]);
    dp[0][3]=max(train[0][0],max(train[0][1],train[0][1]));

    for(int i=1;i<n;i++){
        for(int j=0;j<4;j++){
            for(int k=0;k<3;k++){
                if(j!=k)
                    dp[i][j]=max(dp[i][j],dp[i-1][k]+train[i][k]);
            }
        }
    }

    return dp[n-1][3];
}

//Space optimization
int ninjaTraining(int n,vector<vector<int>>& train){
    vector<int> dp(4);
    dp[0]=max(train[0][2],train[0][1]),dp[1]=max(train[0][0],train[0][2]),dp[2]=max(train[0][0],train[0][1]),dp[3]=max(max(train[0][0],train[0][1]),train[0][2]);
    for(int i=1;i<n;i++){
        vector<int> temp(4,0);
        for(int j=0;j<4;j++){
            for(int k=0;k<3;k++){
                if(j!=k)
                    temp[j]=max(dp[k]+train[i][k],temp[j]);
            }
        }
        dp=temp;
    }
    return dp[3];
}

int main(){
    int n;
    cout<<"Enter the number of days: ";
    cin>>n;
    vector<vector<int>> Train(n,vector<int>(3));
    vector<vector<int>> dp(n,vector<int>(4,-1));
    cout<<"Enter the merit points:\n";
    for(int i=0;i<n;i++){
        for(int j=0;j<3;j++)
            cin>>Train[i][j];
    }

    cout<<"The maximum merit points gained by ninja through training is: "<<ninjaTraining(n,Train);
}

//Memoization
//Time complexity: O(n*4*3)
//Space complexity : O(n)+O(n*4)

//Tabulation
//Time complexity: O(n*4*3)
//Space complexity : O(n*4)

//Space optimization
//Time complexity: O(n*4*3)
//Space complexity : O(4)