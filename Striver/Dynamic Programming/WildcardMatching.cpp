// We are given two strings ‘S1’ and ‘S2’. String S1 can have the following two special characters:

// ‘?’ can be matched to a single character of S2.
// ‘*’ can be matched to any sequence of characters of S2. (sequence can be of length zero or more).
// We need to check whether strings S1 and S2 match or not.

#include<iostream>
#include<vector>
#include<string>
using namespace std;

//Memoization
bool match(int idx1,int idx2,string str1,string str2,vector<vector<bool>>& dp){
    if(idx1<0 && idx2<0)
        return true;
    if(idx1<0 && idx2>=0)
        return false;
    if(idx1>=0 && idx2<0){
        for(int i=idx1;i>=0;i--){
            if(str1[i]!='*')
                return false;
        }
        return true;
    }
    if(dp[idx1][idx2])
        return true;
    if(str1[idx1]==str2[idx2] || str1[idx1]=='?')
        return dp[idx1][idx2]=match(idx1-1,idx2-1,str1,str2,dp);
    if(str1[idx1]=='*')
        return dp[idx1][idx2]=match(idx1,idx2-1,str1,str2,dp)||match(idx1-1,idx2,str1,str2,dp);
    return false;
}

//Tabulation
bool match(string str1,string str2,vector<vector<bool>>& dp){
    int m=str1.size(),n=str2.size();
    dp[0][0]=true;
    for(int i=1;i<=m;i++){
        if(str1[i-1]!='*')
            break;
        dp[i][0]=true;
    }
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            if(str1[i-1]==str2[j-1] || str1[i-1]=='?')
                dp[i][j]=dp[i-1][j-1];
            else if(str1[i-1]=='*')
                dp[i][j]=(dp[i][j-1]|dp[i-1][j]);
        }
    }
    return dp[m][n];
}

//Space optimization
bool match(string str1,string str2){
    int m=str1.size(),n=str2.size();
    vector<bool> prev(n+1,false),cur(n+1,false);
    cur[0]=prev[0]=true;
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            if(str1[i-1]==str2[j-1] || str1[i-1]=='?')
                cur[j]=prev[j-1];
            else if(str1[i-1]=='*')
                cur[j]=(cur[j-1]|prev[j]);
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
    vector<vector<bool>> dp(m+1,vector<bool>(n+1,false));
    if(match(str1,str2))
        cout<<"The two strings match\n";
    else
        cout<<"The two strings don't match\n";
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