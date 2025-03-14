//Given a binary maze (0-1 grid) find the shortest distanece between source to destination

#include<iostream>
#include<vector>
#include<queue>
#include<limits.h>
using namespace std;

int shortestPath(vector<vector<int>> grid,int rs,int re,int cs,int ce){
    int m=grid.size(),n=grid[0].size();
    queue<vector<int>> q;
    q.push({0,rs,cs});
    vector<vector<int>> dist(m,vector<int>(n,INT_MAX));
    dist[rs][cs]=0;

    int row[]={1,0,-1,0},col[]={0,1,0,-1};

    while(!q.empty()){
        vector<int> cell=q.front();
        q.pop();

        for(int i=0;i<4;i++){
            int nr=cell[1]+row[i],nc=cell[2]+col[i];
            if(nr>=0 && nr<m && nc>=0 && nc<n && grid[nr][nc]==1 && dist[nr][nc]>cell[0]+1){
                if(nr=re && nc==ce)
                    return cell[0]+1;
                dist[nr][nc]=cell[0]+1;
                q.push({cell[0]+1,nr,nc});
            }
        }
    }

    return -1;
}

int main(){
    int m,n;
    cout<<"Enter the order of the matrix: ";
    cin>>m>>n;
    vector<vector<int>> grid(m,vector<int>(n));
    cout<<"Enter the binary matrix: ";
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++)
            cin>>grid[i][j];
    }

    int rs,cs,re,ce;
    cout<<"Enter the source and destination cell coordinates: ";
    cin>>rs>>cs>>re>>ce;

    cout<<"The shortest distance between the two given points is: "<<shortestPath(grid,rs,re,cs,ce)<<endl;
}

//Time complexity: O(m*n)