//Given a grid consisting of a 0 and 1 there are a number of islands you are allowed to change 
//any single 0 to 1 by doing so return the largest islnd that can be formed

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

bool check(int row,int col,int m,int n){
    return (row>=0 && row<m && col>=0 && col<n);
}

int main(){
    int m,n;
    cout<<"Enter the order of the grid: ";
    cin>>m>>n;
    cout<<"Enter the grid:\n";
    vector<vector<int>> grid(m,vector<int>(n));
    DisjointSet ds(m*n);

    for(int i=0;i<m;i++)
        for(int j=0;j<n;j++)
            cin>>grid[i][j];

    int rdir[]={0,1,0,-1},cdir[]={1,0,-1,0};
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(grid[i][j]==0)
                continue;
            for(int k=0;k<4;k++){
                int nr=i+rdir[k],nc=j+cdir[k];
                if(check(nr,nc,m,n) && grid[nr][nc]==1)
                    ds.unionBySize((i*n+j),(nr*n+nc));
            }
        }
    }

    int ans=0;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(grid[i][j]==1)
                continue;
            set<int> st;
            for(int k=0;k<4;k++){
                int nr=i+rdir[k],nc=j+cdir[k];
                if(check(nr,nc,m,n) && grid[nr][nc]==1)
                    st.insert(ds.findUltiParent(nr*n+nc));
            }
            int sum=0;
            for(auto it:st)
                sum=sum+ds.size[it];
            ans=max(ans,sum+1);
        }
    }

    for(int i=0;i<m*n;i++)
        ans=max(ans,ds.size[i]);

    cout<<"The number of cells present in largest island is: "<<ans<<endl;
    return 0;
}

//Time complexity : O(m*n)