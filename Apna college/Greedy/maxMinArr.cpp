#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
    int n,odd=0,even=0,fir=0,sec=0;
    cout<<"Enter the size of the array: ";
    cin>>n;
    vector<int> v(n);
    cout<<"Enter the array elements: ";
    for(int i=0;i<n;i++)
    {
        cin>>v[i];
    }
    sort(v.begin(),v.end());
    for(int i=0;i<n;i++)
    {
        (i%2==0)? even+=v[i]:odd+=v[i];
        (i<n/2)? fir+=v[i]:sec+=v[i];
    }
    cout<<"Maximum difference is: "<<abs(sec-fir)<<"\nMinimum difference is: "<<abs(even-odd)<<endl;
    return 0;
}