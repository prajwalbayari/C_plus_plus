//Course schedule 1 and 2

#include<iostream>
#include<vector>
#include<queue>
using namespace std;

vector<int> ans;

void printSolution(){
    cout<<"The order of scheduling course is: ";
    for(int node:ans)
        cout<<node<<" ";
    cout<<endl;
}

bool BFS(vector<vector<int>>& edges){
    int n=edges.size(),cnt=0;
    vector<int> indeg(n,0);
    for(int i=1;i<n;i++){
        for(int node:edges[i])
            indeg[node]++;
    }
    queue<int> q;
    for(int i=1;i<n;i++){
        if(indeg[i]==0)
            q.push(i);
    }

    while(!q.empty()){
        int node=q.front();
        q.pop();
        cnt++;
        ans.push_back(node);
        for(int child:edges[node]){
            indeg[child]--;
            if(indeg[child]==0)
                q.push(child);
        }
    }

    return cnt==n-1;
}

int main(){
    int n,m;
    cout<<"Enter the number of courses and the number of conditions: ";
    cin>>n>>m;
    vector<vector<int>> edges(n+1);
    cout<<"Enter the course and it's prerequisite: ";

    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        edges[u].push_back(v);
    }

    if(BFS(edges))
        printSolution();
    else
        cout<<"It is not possible to schedule courses\n";
}