#include<iostream>
using namespace std;

//RAT IN MAZE

// int Safe(int** arr,int x,int y,int n)
// {
//     if(x<n && y<n && arr[x][y]==1)
//     {
//         return true;
//     }
//     return false;
// }

// int ratinmaze(int** arr,int x,int y,int n,int** solArr)
// {
//     if(x==n-1 && y==n-1)
//     {
//         solArr[x][y]=1;
//         return true;
//     }
//     if(Safe(arr,x,y,n))
//     {
//         solArr[x][y]=1;
//         if(ratinmaze(arr,x+1,y,n,solArr))
//         {
//             return true;
//         }
//         if(ratinmaze(arr,x,y+1,n,solArr))
//         {
//             return false;
//         }
//         solArr[x][y]=0;              //BACKTRACKING
//         return false;
//     }
//     return false;

// }
// int main()
// {
//     int n;
//     cout<<"Enter the size\n";
//     cin>>n;

//     int** arr=new int*[n];
//     for(int i=0;i<n;i++)
//     {
//         arr[i]=new int [n];
//     }

//     for(int i=0;i<n;i++)
//     {
//         for(int j=0;j<n;j++)
//         {
//             cin>>arr[i][j];
//         }
//     }

//     int ** solArr=new int*[n];
//     for(int i=0;i<n;i++)
//     {
//         solArr[i]=new int[n];
//         for(int j=0;j<n;j++)
//         {
//             solArr[i][j]=0;
//         }
//     }

//     if(ratinmaze(arr,0,0,n,solArr))
//     {
//         for(int i=0;i<n;i++)
//         {
//             for(int j=0;j<n;j++)
//             {
//                 cout<<solArr[i][j]<<" ";
//             }
//             cout<<endl;
//         }
//     }
//     return 0;
// }

// NQUEEN


bool isSafe(int** arr,int x,int y,int n)
{
    for(int row=0;row<x;row++)
    {
        if(arr[row][y]==1)
        {
            return false;
        }
    }
    int row=x;
    int col=y;
    while(row>=0 && col>=0)
    {
        if(arr[row][col]==1)
        {
            return false;
        }
        row--;
        col--;
    }
    row=x,col=y;
    while(row>=0 && col<n)
    {
        if(arr[row][col]==1)
        {
            return false;
        }
        row--;
        col++;
    }
    return true;
}

int Queen(int** arr,int x,int n)
{
    if(x>=n)
    {
        return true;
    }
    for(int col=0;col<n;col++)
    {
        if(isSafe(arr,x,col,n))
        {
            arr[x][col]=1;
            if(Queen(arr,x+1,n))
            {
                return true;
            }
            arr[x][col]=0;            //BACKTRACKING
        }
    }
    return false;
}
int main()
{
    int n;
    cout<<"Enter the number of queens:\n";
    cin>>n;
    int** arr=new int*[n];
    for(int i=0;i<n;i++)
    {
        arr[i]=new int[n];
        for(int j=0;j<n;j++)
        {
            arr[i][j]=0;
        }
    }

    if(Queen(arr,0,n))
    {
        cout<<"Positions of queens are:\n";
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cout<<arr[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    return 0;
}