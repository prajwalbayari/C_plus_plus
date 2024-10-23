#include<stdio.h>
#include<conio.h>
#include<iostream>
using namespace std;


//Linear search
// int main()
// {
//     int n,i,a[100],key;
//     cout<<"Enter the size of the array:\n";
//     cin>>n;
//     cout<<"Enter the array elements:\n";
//     for(i=0;i<n;i++)
//     {
//         cin>>a[i];
//     }
//     cout<<"Enter the key element:\n";
//     cin>>key;
//     for(i=0;i<n;i++)
//     {
//         if(key==a[i])
//         {
//             cout<<"Key element is found at position "<<i+1<<"\n";
//         }
//         else 
//         {
//             continue;
//         }
//     }
// }


//Binary search
// int main()
// {
//     int n,mid,beg=0,end,a[100],i,key,p=1,j;
//     cout<<"Enter the size of the array:\n";
//     cin>>n;
//     cout<<"Enter the array elements in ascending order:\n";
//     for(i=0;i<n;i++)
//     {
//         cin>>a[i];
//     }
//     cout<<"Enter the key element:\n";
//     cin>>key;
//     end=n-1;
//     while(beg<=end)
//     {
//         mid=(beg+end)/2;
//         if(a[mid]==key)
//         {
//             cout<<"Key element is found at position "<<mid+1<<"\n";
//             p=0;
//             break;
//         }
//         else if(a[mid]>key)
//         {
//             end=mid-1;
//         }
//         else
//         {
//             beg=mid+1;
//         }
//     }
//      if(p==1)
//      {
//         cout<<"Key element not found\n";
//      }
// }


//Bubble sort
// int main()
// {
//     int n,i,j,a[100],t;
//     cout<<"Enter the size of array:\n";
//     cin>>n;
//     cout<<"Enter the array elements:\n";
//     for(i=0;i<n;i++)
//     {
//         cin>>a[i];
//     }
//     for(i=0;i<n;i++)
//     {
//         for(j=0;j<n;j++)
//         {
//             if(a[j]>a[j+1])
//             {
//                 t=a[j];
//                 a[j]=a[j+1];
//                 a[j+1]=t;
//             }
//         }
//     }
//     cout<<"Array after sorting\n";
//     for(i=0;i<n;i++)
//     {
//         cout<<a[i]<<" ";
//     }
//     cout<<endl;
// }


//Selection sort
// int main()
// {
//     int n,i,j,a[100],t;
//     cout<<"Enter the size of array:\n";
//     cin>>n;
//     cout<<"Enter the array elements:\n";
//     for(i=0;i<n;i++)
//     {
//         cin>>a[i];
//     }
//     for(i=0;i<n-1;i++)
//     {
//         for(j=i+1;j<n;j++)
//         {
//             if(a[j]<a[i])
//             {
//                  t=a[j];
//                  a[j]=a[i];
//                  a[i]=t;
//             }
//         }
//     }
//        for(i=0;i<n;i++)
//         {
//             cout<<a[i]<<" ";
//         } 
//         cout<<endl;
// }    



// insertion sort
// int main()
// {
//     int n,i,j,a[100],current;
//     cout<<"Enter the size of array:\n";
//     cin>>n;
//     cout<<"Enter the array elements:\n";
//     for(i=0;i<n;i++)
//     {
//         cin>>a[i];
//     }
//     for(i=1;i<n;i++)
//     {
//         current=a[i];
//         j=i-1;
//         while(a[j]>current && j>=0)
//         {
//             a[j+1]=a[j];
//             j--;
//         }
//         a[j+1]=current;
//     }
//     for(i=0;i<n;i++)
//     {
//         cout<<a[i]<<" ";
//     }
//     cout<<endl;
// }

