//Disjoint set

#include<bits/stdc++.h>
using namespace std;

class DisjointSet{
    vector<int> rank,parent,size;
    public:
    DisjointSet(int n){
        rank.resize(n+1,0);
        size.resize(n+1,1);
        for(int i=0;i<n;i++)
            parent.push_back(i);
    }

    int findUltiPar(int node){
        if(node==parent[node])
            return node;
        return parent[node]=findUltiPar(parent[node]);
    }

    void unionByRank(int u,int v){
        int pu=findUltiPar(u),pv=findUltiPar(v);
        if(pu==pv)  //Both nodes already have the same parent so no need to union
            return;

        if(rank[pu]<rank[pv])
            parent[pu]=pv;
        else if(rank[pu]>rank[pv])
            parent[pv]=pu;
        else{
            parent[pv]=pu;
            rank[pu]++;
        }
    }

    void unionBySize(int u,int v){
        int pu=findUltiPar(u),pv=findUltiPar(v);
        if(pu==pv)
            return;
        if(size[pu]<size[pv]){
            parent[pu]=pv;
            size[pv]=size[pv]+size[pu];
        }else{
            parent[pv]=pu;
            size[pu]=size[pv]+size[pu];
        }
    }
};

int main(){
    //Hard code
    DisjointSet ds(7);
    ds.unionBySize(1,2);
    ds.unionBySize(2,3);
    ds.unionBySize(4,5);
    ds.unionBySize(6,7);
    ds.unionBySize(5,6);
    if(ds.findUltiPar(3)==ds.findUltiPar(7))
        cout<<"Same\n";
    else    
        cout<<"Not same\n";
    
    ds.unionBySize(3,7);

    if(ds.findUltiPar(3)==ds.findUltiPar(7))
        cout<<"Same\n";
    else    
        cout<<"Not same\n";
    return 0;
}