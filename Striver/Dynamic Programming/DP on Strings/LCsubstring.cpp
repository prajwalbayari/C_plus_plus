// A substring of a string is a subsequence in which all the characters are consecutive. Given two strings, we need to find the longest common substring.
// We need to print the length of the longest common substring.

#include<iostream>
#include<string>
#include<vector>
using namespace std;

//Tabulatiom
int LCSubstring(string str1,string str2,vector<vector<int>>& dp){
    int m=str1.size(),n=str2.size(),ans=0;
    for(int i=0;i<=m;i++)
        dp[i][0]=0;
    for(int i=0;i<=n;i++)
        dp[0][i]=0;
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            if(str1[i-1]==str2[j-1]){
                dp[i][j]=1+dp[i-1][j-1];
                ans=max(ans,dp[i][j]);
            }
            else
                dp[i][j]=0;
        }
    }
    return ans;
}

//Space optimization
int LCSubstring(string str1,string str2){
    int m=str1.size(),n=str2.size(),ans=0;
    vector<int> prev(n+1,0),cur(n+1,0);
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            if(str1[i-1]==str2[j-1]){
                cur[j]=1+prev[j-1];
                ans=max(ans,cur[j]);
            }
            else
                cur[j]=0;
        }
        prev=cur;
    }
    return ans;
}

int main(){
    string str1,str2;
    cout<<"Enter the first string: ";
    cin>>str1;
    cout<<"Enter the second string: ";
    cin>>str2;
    int m=str1.size(),n=str2.size();
    vector<vector<int>> dp(m+1,vector<int>(n+1,-1));
    cout<<"The length of the longest common substring is: "<<LCSubstring(str1,str2)<<endl;
}

//Tabulation
//Time complexity : O(m*n)
//Space complexity : O(m*n)

//Space optimization
//Time complexity : O(m*n)
//Space complexity : O(n)