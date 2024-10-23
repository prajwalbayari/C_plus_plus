//Find if array has a subarray whose elements can be concatenated to form a palindrome (only contains single digits)

#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

bool isPalindrome(int num)
{
    int temp=num,sum=0;
    while(temp>0)
    {
        sum=sum*10+temp%10;
        temp/=10;
    }
    return sum==num;
}

int findPalindrome(vector<int> v,int k)
{
    int num=0;
    for(int i=0;i<k;i++)
    {
        num=num*10+v[i];
    }
    if(isPalindrome(num))
    {
        return 0;
    }
    for(int i=k;i<v.size();i++)
    {
        num=(num%(int)pow(10,k-1));
        num=num*10+v[i];
        if(isPalindrome(num))
        {
            return i-k+1;
        }
    }
    return -1;
}

int main()
{
    int k=7,n;
    vector<int> v={1,2,3,4,2,3,2,3,2,4};
    n=findPalindrome(v,k);
    if(n==-1)
    {
        cout<<"No such subarray found\n";
    }
    else
    {
        cout<<"Palindromic number is: ";
        for(int i=n;i<k+n;i++)
        {
            cout<<v[i];
        }
        cout<<endl;
    }
    return 0;
}