#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int rot(vector<vector<int>>& grid,queue<pair<int,int>> q){
    int d=0,m=grid.size(),n=grid[0].size();

    while(!q.empty()){
        int size=q.size();
        for(int i=0;i<size;i++){
            int row=q.front().first,col=q.front().second;
            q.pop();
            if(row-1>=0 && grid[row-1][col]==1){
                q.push({row-1,col});
                grid[row-1][col]=2;
            }
            if(row+1<m && grid[row+1][col]==1){
                q.push({row+1,col});
                grid[row+1][col]=2;
            }
            if(col-1>=0 && grid[row][col-1]==1){
                q.push({row,col-1});
                grid[row][col-1]=2;
            }
            if(col+1<n && grid[row][col+1]==1){
                q.push({row,col+1});
                grid[row][col+1]=2;
            }
        }
        if(q.size()>0)
            d=d+1;
    }
    return d;
}

int main(){
    int m,n;
    cout<<"Enter the size of the grid: ";
    cin>>m>>n;
    cout<<"Enter the matrix for oranges:\n";
    vector<vector<int>> grid(m,vector<int>(n));
    for(int i=0;i<m;i++)
        for(int j=0;j<n;j++)
            cin>>grid[i][j];

    queue<pair<int,int>> q;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(grid[i][j]==2)
                q.push({i,j});
        }
    }

    int ans=rot(grid,q);

    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(grid[i][j]==1){
                cout<<"Not possible\n";
                return 1;
            }
        }
    }

    cout<<"Time taken for all oranges to rot is: "<<ans<<endl;
    return 0;
}