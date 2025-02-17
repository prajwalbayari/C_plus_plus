//Number of distinct islands in a grid

#include<iostream>
#include<vector>
#include<queue>
#include<set>
using namespace std;

void DFS(int i,int j,vector<vector<int>> grid,vector<vector<int>>& vis,vector<pair<int,int>>& vec,int row,int col){
    vis[i][j]=1;
    vec.push_back({i-row,j-col});
    int delrow[]={-1,0,1,0},delcol[]={0,-1,0,1};
    for(int k=0;k<4;k++){
        int r=i+delrow[k],c=j+delcol[k];
        if(r>=0 && r<grid.size() && c>=0 && c<grid[0].size() && !vis[r][c] && grid[r][c]==1)
            DFS(r,c,grid,vis,vec,row,col);
    }
}

int main(){
    int m,n;
    cout<<"Enter the order of the matrix: ";
    cin>>m>>n;
    vector<vector<int>> grid(m,vector<int>(n)),vis(m,vector<int>(n,0));
    set<vector<pair<int,int>>> s;
    cout<<"Enter the island matrix:\n";
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++)
            cin>>grid[i][j];
    }

    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(!vis[i][j] && grid[i][j]==1){
                vector<pair<int,int>> vec;
                DFS(i,j,grid,vis,vec,i,j);
                s.insert(vec);
            }
        }
    }
    cout<<"The number of distinct islands is: "<<s.size()<<endl;
    return 0;
}

//Space complexity: O(m*n) 
//Time complexity : O(m*n*4)