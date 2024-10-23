#include<iostream>
#include<conio.h>
using namespace std;
int main()
{
    int a,b,c;
    cout<<"Enter two numbers:\n";
    cin>>a>>b;
    cout<<"Enter your choice:\n 1.Addition\n 2.Subtraction\n 3.Multiplication\n 4.Division\n 5.Modulus\n";
    cin>>c;
    switch(c)
    {
        case 1:cout<<"Sum is: "<<a+b<<"\n";
               break;
        case 2:cout<<"Difference is: "<<a-b<<"\n";
               break;
        case 3:cout<<"Product is: "<<a*b<<"\n";
               break;
        case 4:if(b==0)
               {
                cout<<"Division operation is not possiblle\n";
                exit(0);
               }
               else
               {
                cout<<"Remainder is: "<<a/b<<"\n";
               }
        case 5:if(b==0)
               {
                cout<<"Modulus operation is not possiblle\n";
                exit(0);
               }
               else
               {
                cout<<"Quotient is: "<<a%b<<"\n";
               }       
               break;
        default :cout<<"Invalid input\n";                                           
    }
}