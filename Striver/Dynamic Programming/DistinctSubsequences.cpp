// We are given two strings S1 and S2, we want to know how many distinct subsequences of S2 are present in S1.

#include<iostream>
#include<vector>
#include<string>
using namespace std;

//Memoization
int occurences(int idx1,int idx2,string str1,string str2,vector<vector<long long>>& dp){
    if(idx1<0 || idx2<0)
        return 0;
    if(dp[idx1][idx2]!=-1)
        return dp[idx1][idx2];
    int dont=dp[idx1][idx2]=occurences(idx1-1,idx2,str1,str2,dp),take=0;
    if(str1[idx1]==str2[idx2]){
        if(idx2!=0)
            take=occurences(idx1-1,idx2-1,str1,str2,dp);
        else
            take=1;
    }
    return dp[idx1][idx2]=dont+take;
}

//Tabulation
int occurences(string str1,string str2,vector<vector<long long>>& dp){
    int m=str1.size(),n=str2.size();
    for(int i=0;i<=m;i++)
        dp[i][0]=1;
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            if(str1[i-1]==str2[j-1])
                dp[i][j]=dp[i-1][j-1]+dp[i-1][j];
            else
                dp[i][j]=dp[i-1][j];
        }
    }
    return dp[m][n];
}

//Space optimization
int occurences(string str1,string str2){
    int m=str1.size(),n=str2.size();
    vector<double> prev(n+1,0),cur(n+1,0);
    prev[0]=cur[0]=1;
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            if(str1[i-1]==str2[j-1])
                cur[j]=prev[j-1]+prev[j];
            else
                cur[j]=prev[j];
        }
        prev=cur;
    }
    return (int)prev[n];
}

int main(){
    string str1,str2;
    cout<<"Enter the first string: ";
    cin>>str1;
    cout<<"Enter the second string: ";
    cin>>str2;
    int m=str1.size(),n=str2.size();
    vector<vector<long long>> dp(m+1,vector<long long>(n+1,0));
    cout<<"The number of occurences of string 2 in string 1 is: "<<occurences(str1,str2)<<endl;
}

//Memoization
//Time complexity: O(m*n)
//Space complexity: O(m*n)+O(m+n)

//Tabulation
//Time complexity: O(m*n)
//Space complexity: O(m*n)

//Space optimization
//Time complexity: O(m*n)
//Space complexity: O(n)