//Euler Totient function

//It gives number of numbers from 1 to n-1 which are co-prime with n

//fi(n)=n*(1-1/p1)*(1-1/p2)*.....*(1-1/pk) where p1,p2....pk are distinct prime numbers

#include<iostream>
#include<vector>
using namespace std;

int main()
{
    cout<<"Enter the value of n: ";
    int n;
    cin>>n;
    vector<int> vec(n+1);
    for(int i=0;i<=n;i++)
        vec[i]=i;
    for(int i=2;i<n+1;i++)
    {
        if(vec[i]==i)
        {
            for(int j=2*i;j<n+1;j+=i)
            {
                vec[j]*=i-1;
                vec[j]/=i;
            }
            vec[i]=i-1;
        }
    }
    cout<<"Totient values for first "<<n<<" numbers are:\n";
    for(int i=0;i<n+1;i++)
        cout<<vec[i]<<" ";
    cout<<endl;
}