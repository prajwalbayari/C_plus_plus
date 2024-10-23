//Snake and ladder

#include<iostream>
#include<stdlib.h>
#include<vector>
#include<map>
#include<queue>
using namespace std;

int main()
{
    int snake,ladder;
    cout<<"Enter the number of snake and ladders:\n";
    cin>>ladder>>snake;
    map<int,int> s,l;
    cout<<"Enter the ladders:\n";
    for(int i=0;i<ladder;i++)
    {
        int u,v;
        cin>>u>>v;
        l[u]=v;
    }
    cout<<"Enter the snakes:\n";
    for(int i=0;i<snake;i++)
    {
        int u,v;
        cin>>u>>v;
        s[u]=v;
    }
    int moves=0;
    queue<int> q;
    q.push(1);
    bool found=false;
    vector<int> vis(101,0);
    vis[1]=1;
    while(!q.empty() && !found)
    {
        int sz=q.size();
        while(sz--)
        {
            int t=q.front();
            q.pop();
            for(int d=1;d<=6;d++)
            {
                if(t+d==100)
                    found=true;
                if(t+d<=100 && l[t+d] && !vis[l[t+d]])
                {
                    vis[l[t+d]]=1;
                    if(l[t+d]==100)
                        found=true;
                    q.push(l[t+d]);
                }
                else if(t+d<=100 && s[t+d] && !vis[s[t+d]])
                {
                    vis[s[t+d]]=1;
                    if(s[t+d]==100)
                        found=true;
                    q.push(s[t+d]);
                }
                else if(t+d<=100 && !vis[t+d] && !l[t+d] && !s[t+d])
                {
                    vis[t+d]=1;
                    q.push(t+d);
                }
            }
        }
        moves++;
    }
    found? cout<<"Minimum moves required is: "<<moves<<endl:cout<<"Not able to reach 100\n";
    return 0;
}