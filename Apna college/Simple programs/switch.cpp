#include <iostream>
#include<conio.h>
using namespace std;
int main()
{
    char ch;
    cout<<"Enter a vowel of your choice:\n";
    cin>>ch;
    switch(ch)
    {
        case 'a':cout<<"Hello\n";
                 break;
        case 'e':cout<<"Namaste\n";
                 break;
        case 'i':cout<<"Hola\n";
                 break;
        case 'o':cout<<"Gracias\n";
                 break;
        case 'u':cout<<"Namaskara\n";
                 break;
        default :cout<<"Invalid input\n";                                           
    }
}