//Detection of cycle in a graph using sets and unions

#include<iostream>
#include<stdlib.h>
#include<vector>
using namespace std;

int N=1e5;
vector<int> parent(N);
vector<int> s(N);

int find_set(int v)
{
    if(parent[v]==v)
        return v;
    return find_set(parent[v]);
}

void make_set(int v)
{
    parent[v]=v;
    s[v]=1;
}

void union_sets(int a,int b)
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
    for(int i=0;i<N;i++)
        make_set(i);
    int m,n;
    cout<<"Enter the number of nodes and edges respectively\n";
    cin>>n>>m;
    vector<vector<int>> edges;
    cout<<"Enter the edges\n";
    for(int i=0;i<m;i++)
    {
        int u,v;
        cin>>u>>v;
        edges.push_back({u,v});
    }
    bool cycle=false;
    for(auto i:edges)
    {
        int u=i[0],v=i[1];
        int x=find_set(u),y=find_set(v);
        if(x==y)
            cycle=true;
        else
            union_sets(u,v);
    }
    cycle==true? cout<<"Cycle is present\n":cout<<"Cycle is not present\n";
    return 0;
}