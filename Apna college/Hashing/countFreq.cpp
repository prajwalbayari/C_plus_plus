// Count frequency of elements in an array

#include<unordered_map>
#include<map>
#include<iostream>
#include<vector>
using namespace std;

int main()
{
    int n;
    cout<<"Enter the size of the array: ";
    cin>>n;
    vector<int> v(n);
    cout<<"Enter the array elements: ";
    for(int i=0;i<n;i++)
    {
        cin>>v[i];
    }
    map<int,int> m;
    map<int,int> ::iterator it;
    for(int i=0;i<n;i++)
    {
        m[v[i]]++;
    }
    while(n!=-1)
    {
        cout<<"Enter the number: ";
        cin>>n;
        cout<<" Frequency of element is: "<<v[n]<<endl;
    }
}