//Representation of graphs

#include<iostream>
#include<vector>
using namespace std;

void matrix()
{
    //Adjacency matrix
    int node,edge;
    cout<<"Enter the number of nodes and edges: ";
    cin>>node>>edge;
    vector<vector<int>> vec(node+1,vector<int>(node+1,0));
    cout<<"Enter the edges: ";
    for(int i=0;i<edge;i++)
    {
        int x,y;
        cin>>x>>y;
        vec[x][y]=vec[y][x]=1;
    }
    cout<<"Adjacency matrix is: \n";
    for(int i=1;i<node+1;i++)
    {
        for(int j=1;j<node+1;j++)
        {
            cout<<vec[i][j]<<"  ";
        }
        cout<<endl;
    }
}

void list()
{
    //Adjacency list
    int m,n;
    cout<<"Enter the number of nodes and edges: ";
    cin>>m>>n;
    vector<vector<int>> vec(m+1);
    cout<<"Enter the edges: ";
    for(int i=0;i<n;i++)
    {
        int x,y;
        cin>>x>>y;
        vec[x].push_back(y);
        vec[y].push_back(x);
    }
    cout<<"The adjacency list is:\n";
    for(int i=1;i<n+1;i++)
    {
        cout<<i<<"->";
        for(int j=0;j<vec[i].size();j++)
        {
            cout<<vec[i][j];
        }
        cout<<endl;
    }
}

int main()
{
    list();
    return 0;
}