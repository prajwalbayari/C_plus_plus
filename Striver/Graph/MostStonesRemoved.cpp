//Given a matrix with 1 representing stone and 0 represent empty cell a stone can be removed 
//if another stone is present in the same row or column as the current stone return the 
//maximum number of stones that can be removed

#include<iostream>
#include<vector>
#include<set>
using namespace std;

class DisjointSet{
    public:
    vector<int> size,parent;
    DisjointSet(int n){
        size.resize(n,1);
        for(int i=0;i<n;i++)
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
    int m,n,stones;
    cout<<"Enter the order of the grid: ";
    cin>>m>>n;
    cout<<"Enter the number of stones: ";
    cin>>stones;
    vector<vector<int>> edges;
    cout<<"Enter the position of the stones\n";
    for(int i=0;i<stones;i++){
        int u,v;
        cin>>u>>v;
        edges.push_back({u,v});
    }

    DisjointSet ds(m+n);
    for(auto edge: edges){
        int i=edge[0],j=edge[1];
        if(ds.findUltiParent(i)!=ds.findUltiParent(j+m))
            ds.unionBySize(i,j+m);
    }

    set<int> st;

    for(int i=0;i<stones;i++)
        st.insert(ds.findUltiParent(edges[i][0]));

    cout<<"The number of stones that can be removed is: "<<stones-st.size()<<endl;
}