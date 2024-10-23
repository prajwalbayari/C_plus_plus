#include<iostream>
#include<stdlib.h>
using namespace std;


// Taking input and giving output
// int main()
// {
//     int m,n,i,j,a[10][10];
//     cout<<"Enter the numbers of rows and columns:\n";
//     cin>>m>>n;
//     cout<<"Enter array elements:\n";
//     for(i=0;i<m;i++)
//     {
//         for(j=0;j<n;j++)
//         {
//             cin>>a[i][j];
//         }
//     }
//     cout<<"Array is:\n";
//     for(i=0;i<m;i++)
//     {
//         for(j=0;j<n;j++)
//         {
//             cout<<a[i][j]<<" ";
//         }
//         cout<<endl;
//     }
// }


//Searching
// int main()
// {
//     int m,n,i,j,a[10][10],ele;
//     cout<<"Enter the numbers of rows and columns:\n";
//     cin>>m>>n;
//     cout<<"Enter array elements:\n";
//     for(i=0;i<m;i++)
//     {
//         for(j=0;j<n;j++)
//         {
//             cin>>a[i][j];
//         }
//     }
//     cout<<"Enter the searching elements:\n";
//     cin>>ele;
//     for(i=0;i<m;i++)
//     {
//         for(j=0;j<n;j++)
//         {
//             if(a[i][j]==ele)
//             {
//                 cout<<"Element is found in the array\n";
//                 exit(0);
//             }
//         }
//     }
//     cout<<"Element not found in the array:\n";
// }

//Spiral order matrix traversal CODE BY APNA COLLEGE
// int main()
// {
//     int m,n,i,j,a[10][10];
//     cout<<"Enter the numbers of rows and columns:\n";
//     cin>>m>>n;
//     cout<<"Enter array elements:\n";
//     for(i=0;i<m;i++)
//     {
//         for(j=0;j<n;j++)
//         {
//             cin>>a[i][j];
//         }
//     }
//     cout<<"Array is:\n";
//     for(i=0;i<m;i++)
//     {
//         for(j=0;j<n;j++)
//         {
//             cout<<a[i][j]<<"  ";
//         }
//         cout<<endl;
//     }
//     cout<<"Array in spiral form is:\n";
//     int rend=m-1,rst=0,cend=n-1,cst=0;
//     while(rst<=rend && cst<=cend)
//     {
//         for(j=cst;j<=cend;j++)
//         {
//             cout<<a[rst][j]<<" ";
//         }
//         rst++;
//         for(i=rst;i<=rend;i++)
//         {
//             cout<<a[i][cend]<<" ";
//         }
//         cend--;
//         for(j=cend;j>=cst;j--)
//         {
//             cout<<a[rend][j]<<" ";
//         }
//         rend--;
//         for(i=rend;i>=rst;i--)
//         {
//             cout<<a[i][cst]<<" ";
//         }
//         cst++;
//     }
//     cout<<endl;
// }


// CHALLENGES

//Transpose 
// int display(int m,int n,int z[10][10])
// {
//     int i,j;
//     for(i=0;i<m;i++)
//     {
//         for(j=0;j<n;j++)
//         {
//             cout<<z[i][j]<<"  ";
//         }
//         cout<<endl;
//     }
// }
// int transpose(int m,int n,int x[10][10])
// {
//     int i,j,temp,y[10][10];
//     for(i=0;i<m;i++)
//     {
//         for(j=0;j<n;j++)
//         {
//             y[j][i]=x[i][j];
//         }
//     }
//     display(n,m,y);
// }
// int main()
// {
//     int i,j,m,n,a[10][10];
//     cout<<"Enter the number of rows and coloumns:\n";
//     cin>>m>>n;
//     cout<<"Enter the array elements:\n";
//     for(i=0;i<m;i++)
//     {
//         for(j=0;j<n;j++)
//         {
//             cin>>a[i][j];
//         }
//     }
//     cout<<"Entered matrix is:\n";
//     display(m,n,a);
//     cout<<"Matrix after transpose is:\n";
//     transpose(m,n,a);
// }

//Matrix multiplication
// int main()
// {
//     int m,n,p,i,j,k,q,a[10][10],b[10][10],c[10][10];
//     cout<<"Enter the order of the first matrix:\n";
//     cin>>m>>n;
//     cout<<"Enter the order of second matrix:\n";
//     cin>>p>>q;
//     if(n!=p)
//     {
//         cout<<"Matrices are not compatible\n";
//         exit(0);
//     }
//     cout<<"Enter the elements of the first matrix:\n";
//     for(i=0;i<m;i++)
//     {
//         for(j=0;j<n;j++)
//         {
//             cin>>a[i][j];
//         }
//     }
//     cout<<"Enter the elemsnts of the second matrix:\n";
//     for(i=0;i<p;i++)
//     {
//         for(j=0;j<q;j++)
//         {
//             cin>>b[i][j];
//         }
//     }
//     for(i=0;i<m;i++)
//     {
//         for(j=0;j<q;j++)
//         {
//             c[i][j]=0;
//         }
//     }
//     for(i=0;i<m;i++)
//     {
//         for(j=0;j<q;j++)
//         {
//             for(k=0;k<n;k++)
//             {
//                 c[i][j]+=a[i][k]*b[k][j];
//             }
//         }
//     }
//     cout<<"Product of the given matrices is:\n";
//     for(i=0;i<m;i++)
//     {
//         for(j=0;j<q;j++)
//         {
//             cout<<c[i][j]<<"  ";
//         }
//         cout<<endl;
//     }
// }

//Searching an element in sorted matrix
int main()
{
    int m,n,i,j,a[10][10],ele,flag=0;
    cout<<"Enter the order of the matrix:\n";
    cin>>m>>n;
    cout<<"Enter the sorted array elements:\n";
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            cin>>a[i][j];
        }
    }
    cout<<"Enter the searching elements:\n";
    cin>>ele;
    i=0,j=n-1;
    while(i<m && j>=0)
    {
        if(ele==a[i][j])
        {
            flag=1;
            break;
        }
        else if(ele>a[i][j])
        {
            i++;
        }
        else
        {
            j--;
        }
    }
    if(flag)
    {
        cout<<"Element is found\n";
    }
    else 
    {
        cout<<"Element is not found\n";
    }
}