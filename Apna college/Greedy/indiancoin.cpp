//Indian coin change problem

#include<iostream>
#include<vector>
using namespace std;

int main()
{
    int m,i=0;
    cout<<"Enter the amount: ";
    cin>>m;
    vector<int> v={2000,500,200,100,50,20,10,5,2,1};
    cout<<"The combination is :";
    while(i<10)
    {
        if(v[i]<=m)
        {
            cout<<v[i]<<" ";
            m-=v[i];
        }
        else
            i++;
    }
    cout<<endl;
    return 0;
}