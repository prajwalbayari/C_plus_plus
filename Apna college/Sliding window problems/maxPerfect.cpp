//Find the subarray that has maximum perfect numbers(numbers which can be obtained by adding the sum of their perfect divisors)

#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

bool isPerfect(int num)
{
    int sum=1;
    for(int i=2;i<sqrt(num);i++)
    {
        if(num%i==0)
        {
            if(num/i==i)
            {
                sum+=i;
            }
            else
            {
                sum+=i+num/i;
            }
        }
    }
    return (sum==num && num!=1);
}

int PerfectNumber(vector<int> v,int k,int n)
{
    int res=0;
    for(int i=0;i<k;i++)
    {
        res+=v[i];
    }
    int sum=res;
    for(int i=k;i<v.size();i++)
    {
        sum+=v[i]-v[i-k];
        res=sum>res? sum:res;
    }
    return res;
}

int perfectNum(vector<int> v,int k)
{
    int n=v.size();
    if(n<k)
    {
        return -1;
    }
    for(int i=0;i<n;i++)
    {
        v[i]=isPerfect(v[i])? 1:0;
    }
    cout<<endl;
    return PerfectNumber(v,k,v.size());
}

int main()
{
    vector<int> v={12,24,48,6};
    int n=perfectNum(v,3);
    if(n==-1)
    {
        cout<<"Invalid size of subarray"<<endl;
    }
    else
    {
        cout<<"Maximum number of perfect numbers is: "<<n<<endl;
    }
    return 0;
}