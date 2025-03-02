//Find the order of alphabets in alien language by using the words given ordered in dictionary of alien language

#include<iostream>
#include<vector>
#include<queue>
#include<string>
using namespace std;

void TopSort(vector<vector<int>>& edges,vector<int>& ans){
    int n=edges.size();
    vector<int> indeg(n,0);
    for(int i=0;i<n;i++){
        for(int node:edges[i])
            indeg[node]++;
    }
    
    queue<int> q;
    for(int i=0;i<n;i++){
        if(indeg[i]==0)
            q.push(i);
    }

    while(!q.empty()){
        int node=q.front();
        q.pop();
        ans.push_back(node);
        for(int child:edges[node]){
            indeg[child]--;
            if(indeg[child]==0)
                q.push(child);
        }
    }
}

int main(){
    int n,m;
    cout<<"Enter the number of characters and number of words: ";
    cin>>n>>m;
    cout<<"Enter the words in the dictionary: ";
    vector<string> words(m);
    for(int i=0;i<m;i++)
        cin>>words[i];
    
    vector<vector<int>> edges(n);

    for(int i=0;i<m-1;i++){
        string s1=words[i],s2=words[i+1];
        int len=min(s1.size(),s2.size());
        for(int j=0;j<len;j++){
            if(s1[j]!=s2[j]){
                edges[s1[j]-'a'].push_back(s2[j]-'a');
                break;
            }
        }
    }

    vector<int> ans;
    TopSort(edges,ans);

    cout<<"The order in dictionary is: ";
    for(int i=0;i<ans.size();i++)
        cout<<char(ans[i]+'a')<<" ";
    cout<<endl;
}