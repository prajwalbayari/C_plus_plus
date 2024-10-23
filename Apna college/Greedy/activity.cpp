#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main()
{
    int m;
    cout<<"Enter the number of activities: ";
    cin>>m;
    vector<vector<int>> v;
    cout<<"Enter the start and end time of "<<m<<" activities: ";
    for(int i=0;i<m;i++)
    {
        int a,b;
        cin>>a>>b;
        v.push_back({a,b});
    }
    sort(v.begin(),v.end(),[&](vector<int> &a,vector<int> &b){
        return a[1]<b[1];
    });
    int take=1,end=v[0][1];
    for(int i=0;i<m;i++)
    {
        if(v[i][0]>=end)
        {
            take++,end=v[i][1];
        }
    }
    cout<<"Number of activities performed is: "<<take<<endl;
    return 0;
}