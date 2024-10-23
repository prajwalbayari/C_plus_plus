#include<iostream>
#include<string.h>
using namespace std;

int findnear(int gen[],int pos,int j)
{
    for(int i=j;i<100;i++)
    {
        if(gen[i]==1 && (j-pos)<(i-j))
        {
            return 1;
        }
        else if(gen[i]==1 && (j-pos)>(i-j))
        {
            return 0;
        }
    }
}

int main()
{
    int arr[100]={0},gen[100]={0},temp=0,pos=0;
    string s;
    cout<<"Enter the string:\n";
    cin>>s;
    for(int i=0;i<s.length();i++)
    {
        if(s[i]=='x')
        {
            gen[i]=1;
        }
    }
    for(int i=0;i<s.length();i++)
    {
        if(gen[i]==0 && temp==0)
        {
            for(int j=0;j<=i;j++)
            {
                arr[j]++;
            }
        }
        if(gen[i]==1)
        {
            temp=1;
            pos=i;
        }
        if(gen[i]==0 && temp==1)
        {
            if(findnear(gen,pos,i))
            {
                for(int j=i;j>=pos;j--)
                {
                    arr[j]++;
                }
            }
        }
        //cout<<temp<<" "<<pos<<" "<<i<<" "<<endl;
    }    
    for(int i=0;i<s.length();i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}