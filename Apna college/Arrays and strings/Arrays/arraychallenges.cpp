#include<stdio.h>
#include<conio.h>
#include<iostream>
using namespace std;


//MAXIMUM AMONG THE INDEX
// int main()
// {
//     int n,a[100],i,j,maxind=0,temp=0;
//     cout<<"Enter the size of the array:\n";
//     cin>>n;
//     cout<<"Enter array elements:\n";
//     for(i=0;i<n;i++)
//     {
//         cin>>a[i];
//     }
//     for(i=0;i<n;i++)
//     {
//         for(j=0;j<=i;j++)
//         {
//             if(a[j]>temp)
//             {
//                 temp=a[j];
//             }
//         }
//         cout<<"Maximum value upto position "<<i+1<<" is "<<temp<<endl;
//     }
// }


//Sum of subarray
// int main()
// {
//     int n,a[100],i,j,sum;
//     cout<<"Enter the number of elements:\n";
//     cin>>n;
//     cout<<"Enter the array elements:\n";
//     for(i=0;i<n;i++)
//     {
//         cin>>a[i];
//     }
//     cout<<"Sum of respective subarrays is:\n";
//     for(i=0;i<n;i++)
//     {
//         sum=0;
//         for(j=i;j<n;j++)
//         {
//             sum+=a[j];
//             cout<<sum<<"\t";
//         }
//         cout<<endl;
//     }
// }


//Longest arithmetic subarray
// int main()
// {
//     int m,a[100],i,j=2,length=2,temp=0,prevlen=2;
//     cout<<"Enter the size of the array:\n";
//     cin>>m;
//     cout<<"Enter the array elements:\n";
//     for(i=0;i<m;i++)
//     {
//         cin>>a[i];
//     }
//     temp=a[1]-a[0];
//     while(j<m)
//     {
//         if(temp==a[j]-a[j-1])
//         {
//             length++;
//         }
//         else
//         {
//             temp=a[j]-a[j-1];
//             length=2;
//         }
//         if(prevlen<length)
//         {
//             prevlen=length;
//         }
//         j++;
//     }
//     cout<<"Length of the longest subarray is: "<<prevlen<<endl;
// }


//Record breaking day
// int main()
// {
//     int i,j,ans=0,a[100],n,mx=-1;
//     cout<<"Enter number of days:\n";
//     cin>>n;
//     cout<<"Enter the capacity per each day:\n";
//     for(i=0;i<n;i++)
//     {
//         cin>>a[i];
//     }
//     a[n]=-1;
//     if(n==1)
//     {
//         cout<<"1"<<endl;
//         return 0;
//     }   
//     for(i=0;i<n;i++)
//     {
//         if(a[i]>mx && a[i]>a[i+1])
//         {
//            ans++;   
//         }
//         if(mx>a[i])
//         {
//             mx=a[i];
//         }
//     }
//     cout<<"Number of record breaking days is: "<<ans<<endl;
// }