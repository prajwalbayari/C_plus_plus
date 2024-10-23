//Fractional knapsack

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool compare(pair<int,int> p1,pair<int,int> p2)
{
    double ans1=p1.first/p1.second;
    double ans2=p2.first/p2.second;
    return ans1>ans2;
}
int main()
{
    int n,w,ans=0;
    cout<<"Enter the number of items: ";
    cin>>n;
    vector<pair<int,int>> v(n);
    cout<<"Enter the value and weight of the items: ";
    for(int i=0;i<n;i++)
    {
        cin>>v[i].first>>v[i].second;
    }
    cout<<"Enter the size of Knapsack: ";
    cin>>w;
    sort(v.begin(),v.end(),compare);
    for(int i=0;i<n && w!=0;i++)
    {
        if(w>=v[i].second)
        {
            ans+=v[i].first;
            w-=v[i].second;
            cout<<ans<<" "<<w<<endl;
            continue;
        }
        double a=(double)(v[i].first/v[i].second);
        ans+=a*w;
        w=0;
        break;
    }
    cout<<"The total value of items is: "<<ans<<endl;
    return 0;
}