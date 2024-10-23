// Print the k most frequent element in an array

#include<iostream>
#include<vector>
#include<map>
using namespace std;

int main()
{
    int n,k;
    cout<<"Enter the size of the array: ";
    cin>>n;
    vector<int> v(n);
    cout<<"Enter the array elements: ";
    for(int i=0;i<n;i++)
    {
        cin>>v[i];
    }
    map<int,int> mp;
    cout<<"Enter the value of k :";
    cin>>k;
    for(int i=0;i<n;i++)
    {
        int s=mp.size();
        if(mp[v[i]]==0 && s==k)
        {
            break;
        }
        mp[v[i]]++;
    }
    cout<<"Element\tFrequency\n";
    for(auto i=mp.begin();i!=mp.end();i++)
    {
        if(i->second!=0)
        {
            cout<<i->first<<"\t"<<i->second<<endl;
        }
    }
    return 0;
}