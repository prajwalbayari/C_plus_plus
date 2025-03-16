//You will be given q queries in each query you have to mark a cell as a land cell (this might
//be previously a land or a water cell) after processing each query return the number of 
//islands present at that instant

#include<iostream>
#include<vector>
using namespace std;

class DisjointSet{
    vector<int> parent,size;
    public:
    DisjointSet(int n){
        size.resize(n,1);
        for(int i=0;i<n;i++)
            parent.push_back(i);
    }

    int findUltPar(int node){
        if(node==parent[node])
            return node;
        return parent[node]=findUltPar(parent[node]);
    }

    void unionBySize(int u,int v){
        int pu=findUltPar(u),pv=findUltPar(v);
        if(pv==pu)
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
    int m,n,q,islands=0;
    cout<<"Enter the order of the grid: ";
    cin>>m>>n;
    cout<<"Enter the number of queries: ";
    cin>>q;
    vector<vector<int>> vis(m,vector<int>(n,0)); 
    DisjointSet ds(m*n);
    int rdir[]={0,1,0,-1},cdir[]={1,0,-1,0};

    for(int i=0;i<q;i++){
        int row,col;
        cout<<"Enter the coordinates of the cell: ";
        cin>>row>>col;
        if(vis[row][col]){
            cout<<"The number of islands is: "<<islands<<endl;
            continue;
        }
        vis[row][col]=1;
        int node=row*m+col;
        islands++;
        for(int i=0;i<4;i++){
            int nr=row+rdir[i],nc=col+cdir[i],neighbour=nr*m+nc;
            if(nr<m && nr>=0 && nc<n && nc>=0 && vis[nr][nc] && ds.findUltPar(node)!=ds.findUltPar(neighbour)){
                ds.unionBySize(node,neighbour);
                islands--;
            }
        }
        cout<<"The number of islands is: "<<islands<<endl;
    }

    return 0;
}
