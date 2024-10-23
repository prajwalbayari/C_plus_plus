//EXPIDI - Expidition problem minimum stops between two cities

#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

int main()
{
    int t;
    cout<<"Enter the number of testcases: ";
    cin>> t;
    while(t--)
    {
        int n,l,p;
        cout<<"Enter the total number of stops: ";
        cin>>n;
        vector<pair<int,int>> v(n);
        cout<<"Enter the distance from city and fuel available at each stop: ";
        for(int i=0;i<n;i++)
        {
            cin>>v[i].first>>v[i].second;
        }
        cout<<"Enter distance from destination and fuel available: ";
        cin>>l>>p;
        for(int i=0;i<n;i++)
        {
            v[i].first=l-v[i].first;
        }
        sort(v.begin(),v.end());
        int cur=p,ans=0;
        priority_queue<int,vector<int>> pq;
        bool flag=0;
        for(int i=0;i<n;i++)
        {
            if(cur>=l)
                break;
            while(cur<v[i].first)
            {
                if(pq.empty())
                {
                    flag=1;
                    break;
                }
                ans++;
                cur+=pq.top();
                pq.pop();
            }
            if(flag)
                break;
            pq.push(v[i].second);
        }
        if(flag)
        {
            cout<<"Not possible to finish the expidition\n";
            continue;
        }
        while(!pq.empty() && cur<l)
        {
            cur+=pq.top();
            pq.pop();
            ans++;
        }
        if(cur<l)
        {
            cout<<"Not possible to finish the expidition\n";
            continue;
        }
        cout<<"Number of intermidiate stops is: "<<ans<<endl;
    }
    return 0;
}