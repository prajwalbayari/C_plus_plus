#include<iostream>
using namespace std;

// int main()
// {
//     int a=10;
//     int* ptr=&a;
//     cout<<*ptr<<endl;
//     *ptr=20;
//     cout<<a<<endl;
// }

//POINTER ARITHMETIC

// int main()
// {
//     int a=10;
//     int *ptr=&a;
//     cout<<ptr<<endl;
//     ptr++;
//     cout<<ptr<<endl;
//     ptr--;
//     cout<<ptr<<endl;
// }

//POINTERS AND ARRAY

// int main()
// {
//     int arr[]={10,20,30};
//     cout<<*arr<<endl;

//     int *ptr=arr;
//     for(int i=0;i<3;i++)
//     {
//         cout<<*ptr<<" ";
//         ptr++;
//     }
//     cout<<endl;
//     for(int i=0;i<3;i++)
//     {
//         cout<<*(arr+i)<<" ";
//     }
//     cout<<endl;
// }

//POINTER TO POINTER

// int main()
// {
//     int a=10;
//     int *p,**q;
//     p=&a;
//     q=&p;
//     cout<<*p<<" "<<a<<" ";
//     cout<<p<<" "<<&a<<" "<<*q;

// }

//PASS BY VALUE
// void increment(int a)
// {
//     a++;
//     cout<<a<<endl;
// }

// int main()
// {
//     int a=2;
//     increment(a);
//     cout<<a<<endl;
// }

//PASS BY REFERENCE

// int swap(int &a,int &b)
// {
//     int temp=a;
//     a=b;
//     b=temp;
// }
// int Swap(int *a,int *b)
// {
//     int temp=*a;
//     *a=*b;
//     *b=temp;
// }
// int main()
// {
//     int a,b;
//     int *p=&a,*q=&b;
//     cout<<"Enter two numbers:\n";
//     cin>>a>>b;
//     swap(a,b);
//     cout<<"After swapping a="<<a<<" and b="<<b<<endl;
//     Swap(p,q);
//     cout<<"After swapping a="<<a<<" and b="<<b<<endl;
// }