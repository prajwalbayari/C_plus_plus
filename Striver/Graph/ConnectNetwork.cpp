//Given a forest you can connect 2 graphs using any edge that is not necessary to keep a 
//component connected and add that edges between 2 graphs find the number of such edges 
//needed to connect the whole forest

#include<iostream>
#include<vector>
using namespace std;

class DisjointSet{
    vector<int> size,parent;
    public:
    DisjointSet(int n){
        //Considering 0-based graph
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
    int n,m,ans=-1,extra=0;
    cout<<"Enter the number of nodes and edges: ";
    cin>>n>>m;
    DisjointSet ds(n);
    cout<<"Enter the edges:\n";
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        if(ds.findUltiParent(u)==ds.findUltiParent(v))
            extra++;
        else
            ds.unionBySize(u,v);
    }

    for(int i=0;i<n;i++){
        if(i==ds.findUltiParent(i))
            ans++;
    }
    
    if(extra<ans)
        cout<<"Not possible to connect all components\n";
    else
        cout<<"The minimum number of operations needed to connect all components: "<<ans<<endl;
    return 0;
}