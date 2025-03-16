//Number of provinces using Disjoint set

#include<iostream>
#include<vector>
using namespace std;

class DisjointSet{
    vector<int> size,parent;
    public:
    DisjointSet(int n){
        size.resize(n+1,1);
        for(int i=0;i<=n;i++)
            parent.push_back(i);
    }

    int findUltiParent(int node){
        if(node==parent[node])
            return node;
        return parent[node]=findUltiParent(parent[node]);
    }

    void unionBySize(int u,int v){
        int pu=findUltiParent(u),pv=findUltiParent(v);
        if(pu==pv)
            return;
        if(size[pu]<size[pv]){
            parent[pu]=pv;
            size[pv]+=size[pu];
        }else{
            parent[pv]=pu;
            size[pu]+=size[pv];
        }
    }
};

int main(){
    int n,m,ans=0;
    cout<<"Enter the number of nodes and edges in the graph: ";
    cin>>n>>m;
    DisjointSet ds(n);
    cout<<"Enter the edges:\n";
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        if(ds.findUltiParent(u)!=ds.findUltiParent(v))
            ds.unionBySize(u,v);
    }

    for(int i=1;i<=n;i++){
        if(i==ds.findUltiParent(i))
            ans++;
    }

    cout<<"The number of provinces is: "<<ans<<endl;
    return 0;
}

//Time complexity: O(max(n,m))