#include<iostream>
using namespace std;

// HOLLOW RECTANGLE
int main()
{
    int a,b,i,j;
    cout<<"Enter number of rows\n";
    cin>>a;
    cout<<"Enter the number of columns\n";
    cin>>b;
    for(i=0;i<a;i++)
    {
        for(j=0;j<b;j++)
        {
          if(i==0||i==a-1)
          {
            cout<<"*\t";
          }
          else if(j==0||j==b-1)
          {
            cout<<"*\t";
          }
          else
          {
            cout<<" \t";
          }
        }
        cout<<"\n";
    }
}

// RECTANGLE
// {
//     int a,b,i,j;
//     cout<<"Enter number of rows\n";
//     cin>>a;
//     cout<<"Enter the number of columns\n";
//     cin>>b;
//     for(i=0;i<a;i++)
//     {
//         for(j=0;j<b;j++)
//         {
//           cout<<"*\t";
//         }
//         cout<<"\n";
//     }
// }

// INVERTED HALF PYRAMID
// {   
//     int a,b,i,j;
//     cout<<"Enter number of rows\n";
//     cin>>a;
//     b=a;
//     for(i=0;i<a;i++)
//     {
//         for(j=0;j<b;j++)
//         {
//           cout<<"*\t";
//         }
//         cout<<"\n";
//         b-=1;
//     }
// }

// Half pyramid after 180 degree rotation
// {   
//     int a,b=1,i,j;
//     cout<<"Enter number of rows\n";
//     cin>>a;
//     for(i=0;i<a;i++)
//     {
//         for(j=0;j<b;j++)
//         {
//           cout<<"*\t";
//         }
//         cout<<"\n";
//         if(b==a)
//         {
//             exit(0);
//         }
//         b+=1;
//     }
// }

// Inverted pyramid 2nd type
// { 
//     int a,b,i,j;
//     cout<<"Enter number of rows\n";
//     cin>>a;
//     b=a;
//     for(i=0;i<a;i++)
//     {
//         for(j=0;j<b;j++)
//         {
//          if(j<=i-1)
//          {
//             cout<<" \t";
//          }
//          else
//          {
//              cout<<"*\t";
//          }
//         }
//         cout<<"\n";
//     }
// }

// Number pyramid
// { 
//     int a,b,i,j;
//     cout<<"Enter number of rows\n";
//     cin>>a;
//     for(i=0;i<a;i++)
//     {
//         for(j=0;j<=i;j++)
//         {
//           cout<<i+1<<"\t";
//         }
//         cout<<"\n";
//     }
// }

// Floyd's triangle
// {   
//     int a,b=1,i,j;
//     cout<<"Enter number of rows\n";
//     cin>>a;
//     for(i=0;i<a;i++)
//     {
//         for(j=0;j<=i;j++)
//         {
//           cout<<b<<"\t";
//           b++;
//         }
//         cout<<"\n";
//     }
// }

//Butterfly
// {   
//     int a,b,i,j;
//     cout<<"Enter number of rows\n";
//     cin>>a;
//     a=2*a;
//     b=a;
//     for(i=0;i<a;i++)
//     {
//         for(j=0;j<b;j++)
//         {
//           if(j>i&&j<a-i-1)
//           {
//             cout<<" \t";
//             continue;
//           }
//           else if(j+i>=a&&j<i)
//           {
//             cout<<" \t";
//           }
//           else
//           {
//             cout<<"*\t";
//           }
//         }
//         cout<<"\n";
//     }
// }

//Right pyramid with single iteration
// {
//   int n,i,j=0;
//   cout<<"Enter the number of rows:\n";
//   cin>>n;
//   for(i=0;i<n;i++)
//   {
//     j=0;
//     shift:
//     {
//       if(j<=i)
//       {
//         cout<<"* ";
//         j++;
//         goto shift;
//       }
//       else
//       {
//         cout<<endl;
//       }
//     }
//   }
// }