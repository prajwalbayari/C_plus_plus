//Given a list of users and their accounts merge the accounts of the users and give the final
//output

#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;

class DisjointSet{
    vector<int> parent,size;
    public:
    DisjointSet(int n){
        size.resize(n,1);
        for(int i=0;i<n;i++)
            parent.push_back(i);
    }

    int findUltiParent(int node){
        if(node==parent[node])
            return node;
        return parent[node]=findUltiParent(parent[node]);
    }

    void unionBySize(int u,int v){
        int pu=findUltiParent(u),pv=findUltiParent(v);
        if(pu==pv)
            return;
        if(size[pu]<size[pv]){
            parent[pu]=pv;
            size[pv]+=size[pu];
        }else{
            parent[pv]=pu;
            size[pu]+=size[pv];
        }
    }
};

int main(){
    int n;
    cout<<"Enter the number of users: ";
    cin>>n;
    DisjointSet ds(n);
    vector<vector<string>> user(n);
    unordered_map<string,int> mailMap;
    for(int i=0;i<n;i++){
        int x;
        cout<<"\nEnter the number of accounts of the user "<<i+1<<" : ";
        cin>>x;
        user[i].resize(x+1);
        cout<<"Enter the name of user "<<i+1<<" :";
        cin>>user[i][0];
        cout<<"Enter the name of the accounts: ";
        for(int j=1;j<x+1;j++)
            cin>>user[i][j];
    }

    for(int i=0;i<n;i++){
        for(int j=1;j<user[i].size();j++){
            if(mailMap.find(user[i][j])==mailMap.end())
                mailMap[user[i][j]]=i;
            else{
                ds.unionBySize(i,mailMap[user[i][j]]);
            }
        }
    }

    vector<vector<string>> mergedMails(n);
    for(auto it:mailMap)
        mergedMails[ds.findUltiParent(it.second)].push_back(it.first);

    vector<vector<string>> ans;

    for(int i=0;i<n;i++){
        if(mergedMails[i].size()==0)
            continue;
        sort(mergedMails[i].begin(),mergedMails[i].end());
        vector<string> temp;
        temp.push_back(user[i][0]);
        for(auto it:mergedMails[i])
            temp.push_back(it);
        ans.push_back(temp);
    }
    cout<<"\n\nThe account list after merging:\n\n";
    for(int i=0;i<ans.size();i++){
        cout<<ans[i][0]<<" : ";
        for(int j=1;j<ans[i].size();j++)
            cout<<ans[i][j]<<" ";
        cout<<endl;
    }
    return 0;
}