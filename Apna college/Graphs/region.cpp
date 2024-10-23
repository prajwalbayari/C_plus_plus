//Surrounding region

#include<iostream>
#include<stdlib.h>
#include<vector>
using namespace std;

void change(vector<vector<char>> &A,int i,int j)
{
    A[i][j]='*';
    int di[]={0,0,-1,1};
    int dj[]={1,-1,0,0};
    for(int k=0;k<4;k++)
    {
        int ci=i+di[k];
        int cj=j+dj[k];
        if( ci>=0 && ci<A.size() && cj>=0 && cj<A[0].size() && A[ci][cj]=='O')
            change(A,ci,cj);
    }
}

int main()
{
    int m,n;
    cout<<"Enter the size of grid\n";
    cin>>m>>n;
    vector<vector<char>> A(n,vector<char>(m));
    cout<<"Enter the components of the grid:\n";
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
            cin>>A[i][j];
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if((i==0 || i==n-1 || j==0 || j==m-1) && A[i][j]=='O')
                change(A,i,j);
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(A[i][j]=='O') 
                A[i][j]='X';
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(A[i][j]=='*')
                A[i][j]='O';
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
            cout<<A[i][j]<<" ";
        cout<<endl;
    }
    return 0;
}