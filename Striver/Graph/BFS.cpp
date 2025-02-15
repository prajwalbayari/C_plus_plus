#include<iostream>
#include<vector>
#include<queue>
using namespace std;

vector<int> BFS(int n,vector<vector<int>> adj,int src){
    vector<int> vis(n,0),ans;
    vis[src]=1;
    queue<int> q;
    q.push(src);
    
    while(!q.empty()){
        int node=q.front();
        q.pop();
        ans.push_back(node);

        for(auto it: adj[node]){
            if(!vis[it]){
                vis[it]=1;
                q.push(it);
            }
        }
    }
    return ans;
}

int main(){
    int n,m,src;
    cout<<"Enter the number of nodes and edges: ";
    cin>>n>>m;
    vector<vector<int>> adj(n+1);
    cout<<"Enter the edges:\n";
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    cout<<"Enter the source for the traversal: ";
    cin>>src;

    cout<<"The order of BFS traversal is: ";
    vector<int> ans=BFS(n,adj,src);

    for(int i=0;i<ans.size();i++)
        cout<<ans[i]<<" ";

    cout<<endl;
    return 0;
}

//Time complexity : O(m)+O(2*m)