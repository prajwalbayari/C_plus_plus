#include<iostream>
using namespace std;
int main()
// { Inverted pattern
//     int a,b,i,j;
//     cout<<"Enter number of rows\n";
//     cin>>a;
//     b=a;
//     for(i=0;i<=a;i++)
//     {
//         for(j=0;j<b;j++)
//         {
//           cout<<j+1<<"\t";
//         }
//         cout<<"\n";
//         b-=1;
//     }
// }


// {
//     int a,b,i,j;
//     cout<<"Enter number of rows\n";
//     cin>>a;
//     b=a;
//     for(i=0;i<a;i++)
//     {
//         for(j=0;j<a;j++)
//         {
//            if(i>=j)
//            {
//                if((i+j)%2==0)
//                {
//                    cout<<1<<"\t";
//                }
//                else 
//                { 
//                    cout<<0<<"\t";
//                }
//            }
//            else
//            {
//                cout<<" \t";
//            }
//         }
//         cout<<"\n";
//     }
// }

// {   Rhombus pattern
//     int a,b,i,j;
//     cout<<"Enter number of rows\n";
//     cin>>a;
//     b=(2*a)-1;
//     for(i=0;i<a;i++)
//     {
//         for(j=0;j<b;j++)
//         {
//             if(i+j<a-1||i+j>=b)
//             {
//                 cout<<" \t";
//             }
//             else
//             {
//                 cout<<"*\t";
//             }
//         }
//         cout<<"\n";
//     }
// }

// {   star pyramid
//     int a,b,c,d,i,j;
//     cout<<"Enter number of rows\n";
//     cin>>a;
//     c=(2*a)-1;
//     b=c/2;
//     d=b;
//     for(i=0;i<a;i++)
//     {
//         for(j=0;j<c;j++)
//         {
//           if(j>=b&&j<=d)
//           {
//             cout<<"*\t";
//           }
//           else
//           {
//             cout<<" \t";
//           }
//         }
//         b-=1,d+=1;
//         cout<<"\n";
//     }
// }


// {   //Number pyramid
//     int a,b,c,d,j,i,temp=1;
//     cout<<"Enter number of rows\n";
//     cin>>a;
//     b=(2*a)-1;
//     c=b/2;
//     d=c;
//     for(i=0;i<a;i++)
//     {
//         temp=1;
//         for(j=0;j<b;j++)
//         {
//             if(j>=c&&j<=d&&(j-c)%2==0)
//             {
//                 cout<<temp<<"\t";
//                  temp+=1;
//             }
//             else
//             {
//                 cout<<" \t";
//             }
//         }
//           c-=1,d+=1;
//           cout<<"\n";
//     }
// }


//Butterfly with numbers
// {
//     int i,j,m,n,temp=1;
//     cout<<"Enter the number of rows:\n";
//     cin>>m;
//     n=(2*m)-1;
//     for(i=0;i<m;i++)
//     {
//         temp=1;
//         for(j=0;j<n;j++)
//         {
//             if(j<=i || i+j>=n-1)
//             {
//                 cout<<temp<<" ";
//                 if(j<i)
//                 {
//                     temp++;
//                 }
//                 else if(j>i)
//                 {
//                     temp--;
//                 }
//                 else if(j==n/2)
//                 {
//                     temp--;
//                 }
//             }
//             else
//             {
//                 cout<<"  ";
//             }
//         }
//         cout<<endl;
//     }
// }

//  Palindromic pattern
// {
//     int i,j,m,n,temp=1,cend,cst;
//     cout<<"Enter the number of rows:\n";
//     cin>>m;
//     n=(2*m)-1;
//     cend=m-1;
//     cst=cend;
//     for(i=0;i<m;i++)
//     {
//         for(j=0;j<cst;j++)
//         {
//             cout<<"  ";
//         }
//         for(j=cst;j<=cend;j++)
//         {
//             if(j<n/2)
//             {
//                 cout<<temp<<" ";
//                 temp--;
//             }
//             else if(j>n/2)
//             {
//                 cout<<temp<<" ";
//                 temp++;
//             }
//             else if(j==n/2)
//             {
//                 cout<<temp<<" ";
//                 temp++;
//             }
//         }
//         for(j>cend;j<n;j++)
//         {
//             cout<<" ";
//         }
//         cout<<endl;
//         cend++,cst--;
//     }
// }


//Star pattern
// {
//     int i,j,m,n,cend,cst,X,Y;
//     cout<<"Enter the number of rows:\n";
//     cin>>m;
//     n=m-1;
//     cend=n/2;
//     cst=cend;
//     X=m/2-1;
//     Y=m/2;
//     for(i=0;i<m;i++)
//     {
//         if(i<X)
//         {
//             for(j=0;j<cst;j++)
//             {
//                 cout<<"  "; 
//             }
//             for(j=cst;j<=cend;j++)
//             {
//                 cout<<"* ";
//             }
//             for(j>cend;j<=n;j++)
//             {
//                 cout<<"  ";
//             }
//             cst--,cend++;
//         }
//         else if(i==X)
//         {
//             for(j=0;j<n;j++)
//             {
//                 cout<<"* ";
//             }
//         }
//         else if(i==Y)
//         {
//             for(j=0;j<n;j++)
//             {
//                 cout<<"* ";
//             }
//             cst++,cend--;
//         }
//         else if(i>Y)
//         {
//             for(j=0;j<cst;j++)
//             {
//                 cout<<"  ";
//             }
//             for(j=cst;j<=cend;j++)
//             {
//                 cout<<"* ";
//             }
//             for(j>cend;j<n;j++)
//             {
//                 cout<<"  ";
//             }
//             cst++,cend--;
//         }
//         cout<<endl;
//     }
// }


//Zig zag pattern
{
    int m,n,i,j,temp;
    cout<<"Enter the number of stars in the pattern:\n";
    cin>>n;
    temp=n/2;
    for(i=0;i<3;i++)
    {
        for(j=0;j<n;j++)
        {
            if(i==0 && j%4==0)
            {
                cout<<"  ";
            }
            else if((i+j)%2==0 && j%4!=0 && i!=2)
            {
                cout<<"* ";
            }
            else if(i==2 &&j%4==0)
            {
                cout<<"* ";
            }
            else
            {
                cout<<"  ";
            }
        }
        cout<<endl;
    }
}