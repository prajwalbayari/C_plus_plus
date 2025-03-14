//optimized solution for Word ladder

#include<iostream>
#include<queue>
#include<string>
#include<limits.h>
#include<algorithm>
#include<unordered_map>

using namespace std;

unordered_map<string,int> mp;
vector<vector<string>> ans;

void dfs(string goal,vector<string>& seq,string start){
    if(goal==start){
        reverse(seq.begin(),seq.end());
        ans.push_back(seq);
        reverse(seq.begin(),seq.end());
        return;
    }

    for(int i=0;i<goal.size();i++){
        string temp=goal;
        for(char ch='a';ch<='z';ch++){
            temp[i]=ch;

            if(mp.find(temp)!=mp.end() && mp[temp]+1==mp[goal]){
                seq.push_back(temp);
                dfs(temp,seq,start);
                seq.pop_back();
            }
        }
    }
}

void assign(unordered_map<string,int> dict,string start,string goal){
    queue<string> q;
    q.push(start);
    mp[start]=1;
    dict.erase(start);

    while(!q.empty()){
        string str=q.front();
        q.pop();

        if(str==goal)
            break;

        for(int i=0;i<start.size();i++){
            string temp=str;
            for(char j='a';j<='z';j++){
                temp[i]=j;

                if(dict.find(temp)!=dict.end()){
                    dict.erase(temp);
                    q.push(temp);
                    mp[temp]=mp[str]+1;
                }
            }
        }
    }

    if(mp.find(goal)!=mp.end()){
        vector<string> seq;
        seq.push_back(goal);
        dfs(goal,seq,start);
    }
}

int main(){
    int n;
    cout<<"Enter the number of words in the dictionary: ";
    cin>>n;
    unordered_map<string,int> dict;

    cout<<"Enter the words in the dictionary:\n";
    for(int i=0;i<n;i++){
        string s;
        cin>>s;
        dict[s]=1;
    }
    string start,end;
    cout<<"Enter the starting word and the ending word: ";
    cin>>start>>end;

    if(dict.find(end)==dict.end() || start.size()!=end.size()){
        cout<<"\nInvalid inputs\n";
        return 1;
    }

    assign(dict,start,end);

    cout<<"\nThe tarnformation from start node to goal node is:\n";
    for(int i=0;i<ans.size();i++){
        for(int j=0;j<ans[i].size();j++)
            cout<<ans[i][j]<<" "; 
        cout<<endl;
    }
    
    return 0;
}