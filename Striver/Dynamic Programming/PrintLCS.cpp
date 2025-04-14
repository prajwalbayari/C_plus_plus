//Print the longest common subsequence of 2 strings

#include<iostream>
#include<vector>
#include<limits.h>
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
string LCS(string str1,string str2,vector<vector<int>>& dp){
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
    string ans="";
    for(int i=1;i<=n;i++){
        if(dp[m][i]!=dp[m][i-1])
        ans+=str2[i-1];
    }
    return ans;
}

//Space optimization
string LCS(string str1,string str2){
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
    string ans="";
    for(int i=1;i<=n;i++){
        if(prev[i]!=prev[i-1])
            ans+=str2[i-1];
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

    //For Space optimization and tabulation
    // cout<<"The longest common subsequence is: "<<LCS(str1,str2)<<endl;
    
    //For memoization
    string ans="";
    int len=LCS(m,n,str1,str2,dp),i=m,j=n;
    while(i>0 && j>0){
        if(str1[i-1]==str2[j-1]){
            ans=str1[i-1]+ans;
            i--,j--;
        }else{
            if(dp[i-1][j]>dp[i][j-1])
                j--;
            else
                i--;
        }
    }
    cout<<"The longest common subsequence is: "<<ans<<endl; 
}

//Memoization
//Time complexity : O(m*n)
//Space complexity : O(m*n)+O(m+n)

//Tabulation
//Time complexity : O(m*n)
//Space complexity : O(m*n)

//Space optimization
//Time complexity : O(m*n)
//Space complexity : O(n)
