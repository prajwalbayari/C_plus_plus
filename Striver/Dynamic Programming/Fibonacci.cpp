#include<iostream>
#include<vector>
using namespace std;

//Memoization
int fibonacci(int n,vector<int>& dp){
    if(n==0 || n==1)
        return n;
    if(dp[n]!=-1)
        return dp[n];
    return dp[n]=fibonacci(n-1,dp)+fibonacci(n-2,dp);
}

int Fibonacci(int n,vector<int>& dp){
    dp[0]=0,dp[1]=1;
    for(int i=2;i<=n;i++)
        dp[i]=dp[i-1]+dp[i-2];
    
    return dp[n];
}

int FibOptimized(int n){
    int num2=0,num1=1;
    for(int i=2;i<=n;i++){
        int temp=num1+num2;
        num2=num1,num1=temp;
    }

    return num1;
}

int main(){
    int n;
    cout<<"Enter the number: ";
    cin>>n;
    vector<int> dp(n+1,-1);
    cout<<"The fibonaaci number is: "<<FibOptimized(n)<<endl;
}

//Memoization
//Time complexity: O(n)
//Space complexity: O(n)+O(n) Array and stack space

//Tabulation
//Time complexity: O(n)
//Space complexity: O(n) Array only

//Optimized
//Time complexity: O(n)
//Space complexity: O(1)