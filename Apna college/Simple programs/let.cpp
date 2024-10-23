#include<stdio.h>
#include<iostream>
#include<vector>
using namespace std;

// int main()
// {
//     int divisor,dividend,temp=0;
//     cout<<"Enter dividend and divisor:\n";
//     cin>>dividend>>divisor;
//     while(dividend>divisor)
//     {
//         if(dividend>0)
//         {
//             if(divisor>0)
//             {
//                 dividend-=divisor;
//                 temp++;
//             }
//             if(divisor<0)
//             {
//                 dividend+=divisor;
//                 temp--;
//             }
//         }
//     }
//     cout<<"Quotient is: "<<temp<<endl;
// }

// int main()
// {
//     int x=1534236469;
//     long int s=0;
//         if(x>0)
//         {
//             while(x>10)
//             {
//                 s=s*10+(x%10);
//                 x=x/10;
//                 cout<<x<<" "<<s<<" "<<endl;
//             }
//             s=s*10;
//             cout<<s;
//         }
//         if(x<0)
//         {
//             x=(-1)*x;
//             while(x>0)
//             {
//                 s=s*10+(x%10);
//                 x=x/10;
//             }
//             x=(-1)*s;
//         }
//         // if(x<-2147483648 || x>2147483657)
//         // {
//         //     return 0;
//         // }
//         // return x;
//         // cout<<x<<endl;
// }

int main()
{

    cout << "Size of long int: "<< sizeof(long long int) << endl;
    int x=-2;
    unsigned int y = reinterpret_cast<unsigned int> (&x);
    short int a = 0b0000000000000011;
short int b = 0b1111111111111101;
unsigned short int c = 0b1111111111111101;

    cout<<a<<endl;
    cout<<b<<endl;
    cout<<c<<endl;
    
}