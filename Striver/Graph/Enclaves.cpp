//Number of enclaves

#include<iostream>
#include<vector>
#include<queue>
using namespace std;

void BFS(vector<vector<int>> graph,vector<vector<int>>& vis,int row,int col){
    int m=graph.size(),n=graph[0].size();
    queue<pair<int,int>> q;
    q.push({row,col});

    while(!q.empty()){
        int r=q.front().first,c=q.front().second;
        vis[r][c]=1;
        q.pop();
        if(r-1>=0 && graph[r-1][c]==1 && !vis[r-1][c])
            q.push({r-1,c});
        if(r+1<m && graph[r+1][c]==1 && !vis[r+1][c])
            q.push({r+1,c});
        if(c-1>=0 && graph[r][c-1]==1 && !vis[r][c-1])
            q.push({r,c-1});
        if(c+1<n && graph[r][c+1]==1 && !vis[r][c+1])
            q.push({r,c+1});
    }
}

int main(){
    int m,n,ans=0;
    cout<<"Enter the order of the matrix: ";
    cin>>m>>n;
    vector<vector<int>> map(m,vector<int>(n)),vis(m,vector<int>(n,0));
    cout<<"Enter the map matrix:\n";
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin>>map[i][j];
        }
    }

    for(int i=0;i<m;i++){
        if(map[i][0] && !vis[i][0])
            BFS(map,vis,i,0);
        if(map[i][n-1] && !vis[i][n-1])
            BFS(map,vis,i,n-1);
    }

    for(int i=0;i<n;i++){
        if(map[0][i] && !vis[0][i])
            BFS(map,vis,0,i);
        if(map[m-1][i] && !vis[m-1][i])
            BFS(map,vis,m-1,i);
    }

    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(!vis[i][j] && map[i][j])
                ans++;
        }
    }
    cout<<"The number of unreachable islands is: "<<ans<<endl;
}