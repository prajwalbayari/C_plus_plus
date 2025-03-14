//Word ladder problem

//Given a dictionary of words a start word and an end word the first word may or may not
//be present in the dictionary starting from start word navigate to the final word and give the
//transformations taken by the start word to reach goal node(All the words in the dictionary have the same length)

#include<iostream>
#include<queue>
#include<string>
#include<limits.h>
#include<unordered_map>

using namespace std;

vector<vector<string>> BFS(unordered_map<string,int> dict,string start,string goal){
    queue<vector<string>> q;
    q.push({start});
    vector<vector<string>> ans;
    vector<string> usedOnLevel;
    usedOnLevel.push_back(start);
    int level=0;
    
    while(!q.empty()){
        vector<string> vec=q.front();
        string str=vec.back();
        q.pop();

        if(vec.size()>level){
            level++;
            for(auto it:usedOnLevel)
                dict.erase(it);
        }

        if(str==goal && (ans.size()==0 || vec.size()==ans[0].size())){
                ans.push_back(vec);
        }
        for(int i=0;i<str.size();i++){
            string temp=str;
            for(int j=0;j<26;j++){
                temp[i]=('a'+j);

                if(dict.find(temp)!=dict.end() && temp!=str){
                    vec.push_back(temp);
                    q.push(vec);
                    usedOnLevel.push_back(temp);
                    vec.pop_back();
                }
            }
        }
    }

    return ans;
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

    vector<vector<string>> ans=BFS(dict,start,end);
    cout<<"\nThe tarnformation from start node to goal node is:\n";
    for(int i=0;i<ans.size();i++){
        for(int j=0;j<ans[i].size();j++)
            cout<<ans[i][j]<<" "; 
        cout<<endl;
    }
    
    return 0;
}