//BIT MANIPULATION
#include<iostream>
#include<conio.h>
#include<string.h>
#include<algorithm>
using namespace std;


// //GET BIT
// int getbit(int n,int pos)
// {
//     cout<<"Bit present in the given position is:\n";
//     cout<<((n&(1<<pos))!=0)<<endl;
// }
// //SET BIT
// int setbit(int n,int pos)
// {
//     cout<<"After setting the bit the number becomes:\n";
//     cout<<(n|(1<<pos))<<endl;
// }
// //CLEAR BIT
// int clearbit(int n,int pos)
// {
//     cout<<"After clearing the bit the number becomes:\n";
//     cout<<(n&~(1<<pos))<<endl;
// }
// //UPDATE BIT
// int updatebit(int n,int pos)
// {
//     cout<<"After inserting the bit the number becomes:\n";
//     cout<<(n&~(1<<pos)|(1<<pos))<<endl;
// }
// int main()
// {
//     int n,pos;
//     cout<<"Enter a number:\n";
//     cin>>n;
//     cout<<"Enter the position:\n";
//     cin>>pos;
//     updatebit(n,pos);
// }


//CHALLENGES

//POWER OF 2

// int main()
// {
//     int n,m;
//     cout<<"Enter the number:\n";
//     cin>>n;
//     m=n-1;
//     if(n&&!(n&m)==1)
//     {
//         cout<<"Given number is a power of 2\n";
//     }
//     else 
//     {
//         cout<<"Given number is not a power of 2\n";
//     }
// }

//NUMBER OF 1s

// int main()
// {
//     int n,count=0;
//     cout<<"Enter the number:\n";
//     cin>>n;
//     while(n)
//     {
//         n=n&(n-1);
//         count++;
//     }
//     cout<<"Number of 1's is: ";
//     cout<<count<<endl;
// }

//LIST THE SUBSETS

// int subsets(int b[10],int a)
// {
//     int i,j;
//     cout<<"Subsets are:\n";
//     for(i=0;i<(1<<a);i++)
//     {
//         for(j=0;j<a;j++)
//         {
//             if(i&(1<<j))
//             {
//                 cout<<b[j]<<" ";
//             }
//         }
//         cout<<endl;
//     }
// }
// int main()
// {
//     int a[10],n,i;
//     cout<<"Enter the size of the array:\n";
//     cin>>n;
//     cout<<"Enter the array elements:\n";
//     for(i=0;i<n;i++)
//     {
//         cin>>a[i];
//     }
//     subsets(a,n);
//     cout<<(1<<n)<<endl;
// }

//UNIQUE NUMBER IN A SET
// int unique(int a[200],int n)
// {
//     int xorsum=0,i;
//     for(i=0;i<n;i++)
//     {
//         xorsum=xorsum^a[i];
//     }
//     cout<<"Unique number is:\n";                       
//     return xorsum;
// }
// int main()
// {
//     int n,i,arr[200];
//     cout<<"Enter the size of the array\n";
//     cin>>n;
//     cout<<"Enter the array elements:\n";
//     for(i=0;i<n;i++)
//     {
//         cin>>arr[i];
//     }
//     cout<<unique(arr,n)<<endl;
// }


//FIND TWO UNIQUE NUMBERS IN THE SET

// int setBit(int n, int pos)
// {
//     return((n & (1<<pos))!=0);
// }
// void unique(int arr[],int n)
// {
//     int xorsum=0;
//     for(int i=0;i<n;i++)
//     {
//         xorsum=xorsum^arr[i];
//     }
//     int tempxor=xorsum;
//     int setbit=0;
//     int pos=0;
//     while(setbit!=1)
//     {
//         setbit=xorsum&1;
//         pos++;
//         xorsum=xorsum>>1;
//     }
//     int newxor;
//     for(int i=0;i<n;i++)
//     {
//         if(setBit(arr[i],(pos-1)))
//         {
//             newxor=newxor^arr[i];
//         }
//     }

//     cout<<"The two unique numbers are:\n"<<newxor<<" ";
//     cout<<(tempxor^newxor)<<endl;
// }

// int main()
// {
//     int arr[10],n;
//     cout<<"Enter the number of elements in array:\n";
//     cin>>n;
//     cout<<"Enter the array elements:\n";
//     for(int i=0;i<n;i++)
//     {
//         cin>>arr[i];
//     }
//     unique(arr,n);
// }


//FIND THE UNIQUE NUMBER IN A SET OF ELEMENTS HAVING TRIPLETS
// int getbit(int n,int pos)
// {
//     return ((n&(1<<pos))!=0);
// }
// int setbit(int n,int pos)
// {                                                                 
//     return (n | (1<<pos));
// }
// int unique(int a[10],int n)
// {
//     int i,j,sum=0,result=0;
//     for(i=0;i<64;i++)
//     {
//         sum=0;
//         for(j=0;j<n;j++)
//         {
//             if(getbit(a[j],i))
//             {
//                 sum++;
//             }
//         }
//         if(sum%3!=0)
//         {
//             result=setbit(result,i);             
//         }
//     }
//     return result;
// }
// int main()
// {
//     int a[200],m,i;
//     cout<<"Enter the size of the array:\n";
//     cin>>m;
//     cout<<"Enter the elements of the set\n";
//     for(i=0;i<m;i++)
//     {
//         cin>>a[i];
//     }
//     cout<<"The unique number is:\n";
//     cout<<unique(a,m);
// }