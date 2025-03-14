//Dijkstras (Undirected graph) does not work for negative edges

#include<iostream>
#include<vector>
#include<queue>
#include<limits.h>
#include<set>
using namespace std;


//using priority queue 

void dijkstrasQueue(vector<vector<pair<int,int>>>& edges,vector<int>& dist,int src){
    dist[src]=0;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    pq.push({0,src});

    while(!pq.empty()){
        pair<int,int> node=pq.top();
        pq.pop();

        for(auto child:edges[node.second]){
            if(dist[child.first]>dist[node.second]+child.second){
                dist[child.first]=dist[node.second]+child.second;
                pq.push({dist[child.first],child.first});
            }
        }
    }
}

//Using set (if a better path to a node is found we can immedialtely delete costlier paths to that node that are already in the set)

void dijkstrasSet(vector<vector<pair<int,int>>>& edges,vector<int>& dist,int src){
    set<pair<int,int>> st;
    dist[src]=0;
    st.insert({0,src});

    while(!st.empty()){
        auto it=*(st.begin());
        int node=it.second,dis=it.first;
        st.erase(it);

        for(auto child:edges[node]){
            int adj=child.first,cost=child.second;

            if(dis+cost<dist[adj]){
                if(dist[adj]!=INT_MAX)
                    st.erase({dist[adj],adj}); //Remove previous minimum value if it exists in set
                dist[adj]=dis+cost;
                st.insert({dist[adj],adj});
            }
        }
    }
}

int main(){
    int n,m,src;
    cout<<"Enter the number of nodes and edges respectively: ";
    cin>>n>>m;
    vector<vector<pair<int,int>>> edges(n); //Zero based indexing
    cout<<"Enter the edges and their weights:\n";
    for(int i=0;i<m;i++){
        int u,v,cost;
        cin>>u>>v>>cost;
        edges[u].push_back({v,cost});
        edges[v].push_back({u,cost});
    }
    cout<<"Enter the source node: ";
    cin>>src;

    vector<int> dist(n,INT_MAX);

    dijkstrasSet(edges,dist,src);

    cout<<"The shortest distance from source to all the nodes:\n";
    for(int i=0;i<n;i++)
        cout<<src<<" -> "<<i<<" = "<<((dist[i]==INT_MAX)? -1:dist[i])<<endl;

    return 0;
}

//Time complexity: O(m*log(n))