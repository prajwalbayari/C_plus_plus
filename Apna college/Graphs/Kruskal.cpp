//Minimum spanning tree

//Kruskal algorithm

#include<iostream>
#include<stdlib.h>
#include<vector>
#include<algorithm>
using namespace std;

int n=1e5+6;
vector<int> parent(n);
vector<int> s(n);

void make_set(int v)
{
    parent[v]=v;
    s[v]=1;
}

int find_set(int v)
{
    if(v==parent[v])
        return v;
    return find_set(parent[v]);
}

void union_set(int a,int b)
{
    a=find_set(a);
    b=find_set(b);
    if(a!=b)
    {
        if(s[a]<s[b])
            swap(a,b);
        parent[b]=a;
        s[a]+=s[b];
    }
}

int main()
{
    for(int i=0;i<n;i++)
        make_set(i);
    int m,n,cost=0;
    cout<<"Enter the number of nodes and edges respectively\n";
    cin>>n>>m;
    vector<vector<int>> edges;
    cout<<"Enter the edges and their weights\n";
    for(int i=0;i<m;i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        edges.push_back({w,u,v});
    }
    sort(begin(edges),end(edges));
    for(auto i:edges)
    {
        int w=i[0],u=i[1],v=i[2];
        int x=find_set(u),y=find_set(v);
        if(x==y)
        {
            continue;
        }
        else
        {
            cout<<u<<" "<<v<<"\t";
            cost+=w;
            union_set(u,v);
        }
    }
    cout<<"\n Cost is: "<<cost<<endl;
    return 0;
}