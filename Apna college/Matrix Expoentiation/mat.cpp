//Given a square matrix a we have to calculate a power n where n is a positive integer
//For this code time complexity is O(k^3 logn) k is size of array a

#include<vector>
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;

//Fibonacci series using matrix exponentiation

//Function to multiply

vector<vector<int>> multiply(vector<vector<int>> a,vector<vector<int>> b)
{
    int n=a.size();
    vector<vector<int>> ans(n,vector<int>(n,0));
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            for(int k=0;k<n;k++)
                ans[i][j]+=a[i][k]*b[k][j];
    return ans;
}

//Function to exponentiate
vector<vector<int>> matrixExponentiate(vector<vector<int>> a,int n)
{
    if(n==0)
    {
        vector<vector<int>> ans(a.size(),vector<int>(a.size(),0));
        for(int i=0;i<a.size();i++)
            ans[i][i]=1;
        return ans;
    }
    if(n==1)
        return a;
    vector<vector<int>> temp=matrixExponentiate(a,n/2);
    temp=multiply(temp,temp);
    if(n&1)
        temp=multiply(a,temp);
    return temp;
}

int main()
{
    int n;
    cout<<"Enter the value of n:\n";
    cin>>n;
    vector<vector<int>> a={{1,1},{1,0}};
    vector<vector<int>> ans=matrixExponentiate(a,n);
    int s=ans.size();
    for(int i=0;i<s;i++)
    {
        for(int j=0;j<s;j++)
        {
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
    //N th fibonacci number is ans[0][1]
}