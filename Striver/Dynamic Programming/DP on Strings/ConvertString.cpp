// We are given two strings, str1 and str2. We are allowed the following operations:

// Delete any number of characters from string str1.
// Insert any number of characters in string str1.
// We need to tell the minimum operations required to convert str1 to str2.

#include<iostream>
#include<vector>
#include<string>
using namespace std;

//Memoization
int LCS(int idx1,int idx2,string str1,string str2,vector<vector<int>>& dp){
    if(idx1==0 || idx2==0)
        return 0;
    if(dp[idx1][idx2]!=-1)
        return dp[idx1][idx2];
    if(str1[idx1-1]==str2[idx2-1])
        return 1+LCS(idx1-1,idx2-1,str1,str2,dp);
    int pickLeft=LCS(idx1-1,idx2,str1,str2,dp);
    int pickRight=LCS(idx1,idx2-1,str1,str2,dp);
    return dp[idx1][idx2]=max(pickLeft,pickRight);
}

//Tabulation
int LCS(string str1,string str2,vector<vector<int>>& dp){
    int m=str1.size(),n=str2.size();
    for(int i=0;i<=m;i++)
        dp[i][0]=0;
    for(int j=0;j<=n;j++)
        dp[0][j]=0;
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            if(str1[i-1]==str2[j-1])
                dp[i][j]=dp[i-1][j-1]+1;
            else
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        }
    }
    return dp[m][n];
}

//Space optimization
int LCS(string str1,string str2){
    int m=str1.size(),n=str2.size();
    vector<int> prev(n+1,0),cur(n+1);
    cur[0]=0;
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            if(str1[i-1]==str2[j-1])
                cur[j]=prev[j-1]+1;
            else
                cur[j]=max(prev[j],cur[j-1]);
        }
        prev=cur;
    }
    return prev[n];
}

int main(){
    string str1,str2;
    cout<<"Enter the first string: ";
    cin>>str1;
    cout<<"Enter the second string: ";
    cin>>str2;
    int m=str1.size(),n=str2.size();
    vector<vector<int>> dp(m+1,vector<int>(n+1,-1));
    cout<<"The minimum number of operations to convert string is: "<<(m+n-2*LCS(str1,str2))<<endl;
}