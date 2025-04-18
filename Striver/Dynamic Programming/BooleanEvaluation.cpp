// Given an expression, A, with operands and operators (OR, AND, XOR), in how many ways can you evaluate the expression to be true, by grouping it in different ways?

// Operands are only true and false.

// Return the number of ways to evaluate the expression modulo 1e3 + 3.

#include<iostream>
#include<vector>
#include<string>
#include<limits.h>
using namespace std;

//Memoization
long evaluate(int i,int j,int isTrue,string exp,vector<vector<vector<long>>>& dp){
    if(i>j)
        return 0;
    if(i==j){
        if(isTrue)
            return exp[i]=='T';
        else
            return exp[i]=='F';
    }
    if(dp[i][j][isTrue]!=-1)
        return dp[i][j][isTrue];
    long ans=0;
    for(int k=i+1;k<j;k+=2){
        long leftTrue=evaluate(i,k-1,1,exp,dp);
        long leftFalse=evaluate(i,k-1,0,exp,dp);
        long rightTrue=evaluate(k+1,j,1,exp,dp);
        long rightFalse=evaluate(k+1,j,0,exp,dp);
        if(exp[k]=='&'){
            if(isTrue)
                ans=ans+leftTrue*rightTrue;
            else
                ans=ans+(leftFalse*rightTrue+leftTrue*rightFalse+leftFalse*rightFalse);
        }
        else if(exp[k]=='|'){
            if(isTrue)
                ans=ans+leftFalse*rightTrue+leftTrue*rightFalse+leftTrue*rightTrue;
            else
                ans=ans+leftFalse*rightFalse;
        }else{
            if(isTrue)
                ans=ans+leftFalse*rightTrue+leftTrue*rightFalse;
            else
                ans=ans+leftFalse*rightFalse+leftTrue*rightTrue;
        }
    }

    return dp[i][j][isTrue]=ans;
}

int main(){
    string exp;
    cout<<"Enter the expression: ";
    cin>>exp;
    int n=exp.size();
    vector<vector<vector<long>>> dp(n,vector<vector<long>>(n,vector<long>(2,-1)));
    cout<<"The total number of partitions is: "<<evaluate(0,n-1,1,exp,dp)<<endl;
}

//Memoization
//Time complexity: O(n*n*n*2)
//Space complexity: O(n*n*2)