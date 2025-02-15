#include<vector>
#include<queue>
#include<iostream>
using namespace std;

void BFS(vector<vector<int>> adj,vector<vector<int>>& vis,int i,int j){
    vis[i][j]=1;
    queue<pair<int,int>> q;
    q.push({i,j});
    int m=adj.size(),n=adj[0].size();

    while(!q.empty()){
        int row=q.front().first,col=q.front().second;
        q.pop();

        for(int r=-1;r<=1;r++){
            for(int c=-1;c<=1;c++){
                int newr=r+row,newc=c+col;

                if(newr>=0 && newr<m && newc>=0 && newc<n && adj[newr][newc] && !vis[newr][newc]){
                    vis[newr][newc]=1;
                    q.push({newr,newc});
                }
            }
        }
    }
}

int main(){
    int m,n;
    cout<<"Enter m and n :";
    cin>>m>>n;
    vector<vector<int>> adj(m,vector<int>(n)),vis(m,vector<int>(n,0));

    cout<<"Enter the island matrix:\n";

    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++)
            cin>>adj[i][j];
    }

    int cnt=0;

    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(adj[i][j] && !vis[i][j]){
                cnt++;
                BFS(adj,vis,i,j);
            }
        }
    }

    cout<<"The number of island is: "<<cnt<<endl;
}