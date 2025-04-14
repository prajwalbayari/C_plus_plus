// We are given two strings ‘S1’ and ‘S2’. We need to convert S1 to S2. The following three operations are allowed:

// Deletion of a character.
// Replacement of a character with another one.
// Insertion of a character.
// We have to return the minimum number of operations required to convert S1 to S2 as our answer

#include<iostream>
#include<vector>
#include<string>
using namespace std;

//Memoization
int convert(int idx1,int idx2,string str1,string str2,vector<vector<int>>& dp){
    if(idx1<0)
        return idx2+1;
    if(idx2<0)
        return idx1+1;
    if(dp[idx1][idx2]!=-1)
        return dp[idx1][idx2];
    if(str1[idx1]==str2[idx2])
        return dp[idx1][idx2]=convert(idx1-1,idx2-1,str1,str2,dp);
    int insert=convert(idx1,idx2-1,str1,str2,dp);
    int remove=convert(idx1-1,idx2,str1,str2,dp);
    int replace=convert(idx1-1,idx2-1,str1,str2,dp);
    int ans=min(insert,min(remove,replace));
    return dp[idx1][idx2]=ans+1;
}

//Tabulation
int convert(string str1,string str2,vector<vector<int>>& dp){
    int m=str1.size(),n=str2.size();
    for(int i=0;i<=n;i++)
        dp[0][i]=i;
    for(int i=0;i<=m;i++)
        dp[i][0]=i;
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            if(str1[i-1]==str2[j-1])
                dp[i][j]=dp[i-1][j-1];
            else
                dp[i][j]=min(dp[i-1][j],min(dp[i-1][j-1],dp[i][j-1]))+1;
        }
    }
    return dp[m][n];
}

//Space optimization
int convert(string str1,string str2){
    int m=str1.size(),n=str2.size();
    vector<int> prev(n+1,0),cur(n+1,0);
    cur[0]=1;
    for(int i=0;i<=n;i++)
        prev[i]=i;
    for(int i=1;i<=m;i++){
        cur[0]=i;
        for(int j=1;j<=n;j++){
            if(str1[i-1]==str2[j-1])
                cur[j]=prev[j-1];
            else
                cur[j]=min(prev[j],min(prev[j-1],cur[j-1]))+1;
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
    vector<vector<int>> dp(m+1,vector<int>(n+1,0));
    cout<<"The minimum number of operations to convert string is: "<<convert(str1,str2)<<endl;
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