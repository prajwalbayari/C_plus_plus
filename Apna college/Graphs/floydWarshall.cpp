//Floyd warshall algorithm

#include<iostream>
#include<stdlib.h>
#include<vector>
#include<algorithm>
using namespace std;
const int INF=1e9;
int main()
{
    vector<vector<int>> graph=  {
                                    {0,5,INF,10},
                                    {INF,0,3,INF},
                                    {INF,INF,0,1},
                                    {INF,INF,INF,0}
                                };
    int n=graph.size();
    vector<vector<int>> dis=graph;
    for(int k=0;k<n;k++)
    {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
                dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(dis[i][j]==INF)
                cout<<"-1 ";
            else
                cout<<dis[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}