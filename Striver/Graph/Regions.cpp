//Surrounded regions

#include<iostream>
#include<vector>
using namespace std;

void surround(vector<vector<char>> regions,vector<vector<int>>& vis,int i,int j){
    int m=regions.size(),n=regions[0].size();
    if(i<0 || i>=m || j<0 || j>=n || regions[i][j]=='X' || vis[i][j])
        return;
    vis[i][j]=1;
    surround(regions,vis,i-1,j);
    surround(regions,vis,i+1,j);
    surround(regions,vis,i,j-1);
    surround(regions,vis,i,j+1);
}

int main(){
    int m,n;
    cout<<"Enter the order of the matrix:\n";
    cin>>m>>n;
    vector<vector<char>> regions(m,vector<char>(n));
    vector<vector<int>> vis(m,vector<int>(n,0));

    cout<<"Enter the region matrix: ";
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin>>regions[i][j];
        }
    }

    for(int i=0;i<m;i++){
        if(regions[i][0]=='O' && !vis[i][0])
            surround(regions,vis,i,0);

        if(regions[i][n-1]=='O' && !vis[i][n-1])
            surround(regions,vis,i,n-1);
    }

    for(int i=0;i<n;i++){
        if(regions[0][i]=='O' && !vis[0][i])
            surround(regions,vis,0,i);
            
        if(regions[m-1][i]=='O' && !vis[m-1][i])
            surround(regions,vis,m-1,i);    
    }

    cout<<"The final matrix is:"<<endl;

    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(regions[i][j]=='X' || !vis[i][j])
                cout<<"X ";
            else
                cout<<"O ";
        }
        cout<<endl;
    }
    return 0;
}

//Time complexity and space complexity : O(m*n)