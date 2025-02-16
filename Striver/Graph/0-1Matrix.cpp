#include<iostream>
#include<vector>
#include<queue>

using namespace std;

void distance(vector<vector<int>> adj,queue<vector<int>> q,vector<vector<int>>& ans){
    int m=adj.size();
    int n=adj[0].size();

    while(!q.empty()){
        int row=q.front()[0],col=q.front()[1],dist=q.front()[2];
        q.pop();

        if(row-1>=0 && ans[row-1][col]==-1 && adj[row-1][col]==0){
            ans[row-1][col]=dist+1;
            q.push({row-1,col,dist+1});
        }
        if(row+1<m && ans[row+1][col]==-1 && adj[row+1][col]==0){
            ans[row+1][col]=dist+1;
            q.push({row+1,col,dist+1});
        }
        if(col-1>=0 && ans[row][col-1]==-1 && adj[row][col-1]==0){
            ans[row][col-1]=dist+1;
            q.push({row,col-1,dist+1});
        }
        if(col+1<n && ans[row][col+1]==-1 && adj[row][col+1]==0){
            ans[row][col+1]=dist+1;
            q.push({row,col+1,dist+1});
        }
    }
}

int main(){
    int m,n;
    cout<<"Enter the size of the matrix:";
    cin>>m>>n;
    vector<vector<int>> mat(m,vector<int>(n)),ans(m,vector<int>(n,-1));
    queue<vector<int>> q;
    cout<<"Enter the 0-1 matrix:\n";
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin>>mat[i][j];
            if(mat[i][j]==1){
                ans[i][j]=0;
                q.push({i,j,0});
            }
        }
    }

    distance(mat,q,ans);

    cout<<"The final distance matrix is:\n\n";
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++)
            cout<<ans[i][j]<<" ";
        cout<<endl;
    }

    return 0;
}