// We are given two strings ‘S1’ and ‘S2’. We need to return their shortest common supersequence. A supersequence is defined as the string which contains both the strings S1 and S2 as subsequences.

#include<iostream>
#include<vector>
#include<limits.h>
#include<string>
using namespace std;

//Memoization (Gives MLE)
string shortestCommonSuperSeq(int idx1,int idx2,string str1,string str2,vector<vector<string>>& dp){
    if(idx1<0 && idx2<0)
        return "";
    if(idx1<0)
        return str2.substr(0,idx2+1);
    if(idx2<0)
        return str1.substr(0,idx1+1);
    if(dp[idx1][idx2]!="")
        return dp[idx1][idx2];
    if(str1[idx1]==str2[idx2])
        return dp[idx1][idx2]=shortestCommonSuperSeq(idx1-1,idx2-1,str1,str2,dp)+str2[idx2];
    string left=shortestCommonSuperSeq(idx1-1,idx2,str1,str2,dp)+str1[idx1];
    string right=shortestCommonSuperSeq(idx1,idx2-1,str1,str2,dp)+str2[idx2];
    return dp[idx1][idx2]=(right.size()<left.size())? right:left;
}

//Tabulation
string shortestCommonSuperSeq(string str1,string str2,vector<vector<int>>& dp){
    int m=str1.size(),n=str2.size();
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            if(str1[i-1]==str2[j-1])
                dp[i][j]=dp[i-1][j-1]+1;
            else
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        }
    }
    string ans="";
    int i=m,j=n;
    while(i>0 && j>0){
        if(str1[i-1]==str2[j-1]){
            ans=str1[i-1]+ans;
            i--,j--;
        }else{
            if(dp[i-1][j]>dp[i][j-1]){
                ans=str1[i-1]+ans;
                i--;
            }
            else{
                ans=str2[j-1]+ans;
                j--;
            }
        }
    }
    while(i>0)
        ans=str1[--i]+ans;
    while(j>0)
        ans=str2[--j]+ans;
    return ans;
}

int main(){
    string str1,str2;
    cout<<"Enter the first strings: ";
    cin>>str1;
    cout<<"Enter the second string: ";
    cin>>str2;
    int m=str1.size(),n=str2.size();

    //For memoization
    // vector<vector<string>> dp(m+1,vector<string>(n+1,""));

    //For tabulation
    vector<vector<int>> dp(m+1,vector<int>(n+1,0));
    cout<<"The shortest common supersequence is: "<<shortestCommonSuperSeq(str1,str2,dp)<<endl;
}