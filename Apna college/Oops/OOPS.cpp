#include<stdio.h>
#include<iostream>
using namespace std;

// class student
// {
//     public:
//     string name;
//     int age;
//     string gender;

//     student(string s,int a,string g)
//     {
//         name=s,age=a,gender=g;
//     }//PARAMETERISED CONSTRUCTOR

//     student()
//     {
//         cout<<"Default constructor called:\n";
//     }//DEFAULT CONSTRUCTOR
//     ~student()
//     {
//         cout<<"Destructor called\n";
//     }//DESTRUCTOR
    
//     student(student &a)
//     {
//         cout<<"Copy constructor called\n";
//         name=a.name;
//         gender=a.gender;
//         age=a.age;
//     }//COPY CONSTRUCTOR
//     void printinfo()
//     {
//         cout<<"Name: "<<name<<endl;
//         cout<<"Age: "<<age<<endl;
//         cout<<"Gender: "<<gender<<endl;
//     }
// };
// int main()
// {
//     int i,n;
//     student arr[2];
//     cout<<"Enter the student information:\n";
//     for(i=0;i<2;i++)
//     {
//         cin>>arr[i].name;
//         cin>>arr[i].age;
//         cin>>arr[i].gender;
//     }
//     for(i=0;i<2;i++)
//     {
//         arr[i].printinfo();
//     }

//     student a("Prajwal",23, "Male");
//     student b=a;

//     a.printinfo();                               //FOR CONSTRUCTOR
// }


//FUNCTION OVERLOADING
// class function
// {
//     public:
//     void fun()
//     {
//         cout<<"Function without arguments\n";
//     }
//     void fun(int a)
//     {
//         cout<<"Function with integer as argument\n";
//     }
//     void fun(double u)
//     {
//         cout<<"Function with double as argument\n";
//     }
// };

// int main()
// {
//     function hello;
//     hello.fun();
//     hello.fun(7);
//     hello.fun(0.8);
// }



//OPERATOR OVERLOADING
// class complex
// {
//     private:
//     int real,imag;
//     public:
//     complex(int r,int i)
//     {
//         real=r,imag=i;
//     }
//     complex operator + (complex const &obj)
//     {
//         complex res;
//         res.imag = imag +obj.imag;
//         res.real =real +obj.real;
//         return res;
//     }
//     void display()
//     {
//         cout<<real<<" +i"<<imag<<endl;
//     }
// };

// int main()
// {
//     complex c1(12,7),c2(6,7);
//     complex c3=c2+c1;
//     c3.display();
//     return 0; 
// }

//Run time polymorphism
class base
{
    public:
    virtual void print()
    {
        cout<<"This is the print function of base class\n";
    }
    void display()
    {
        cout<<"This is the display function of base class\n";
    }
};

class derived:public base
{
    public:
    void print()
    {
        cout<<"This is the print function of derived class\n";
    }
    void display()
    {
        cout<<"This is the display function of derived class\n";
    }
};

int main()
{
    base *baseptr;
    derived d;
    baseptr =&d;
    baseptr -> print();
    baseptr -> display();
    return 0;
}