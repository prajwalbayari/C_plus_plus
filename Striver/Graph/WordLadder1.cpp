//Word ladder problem

//Given a dictionary of words a start word and an end word the first word may or may not
//be present in the dictionary starting from start word navigate to the final word and give the
//the number of transformations needed to reach goal(All the words in the dictionary have the same length)

#include<vector>
#include<iostream>
#include<queue>
#include<string>
#include<unordered_map>

using namespace std;

int BFS(unordered_map<string,int> dict,string start,string goal){
    queue<pair<string,int>> q;
    q.push({start,0});
    if(dict.find(start)!=dict.end())
        dict.erase(start);
    
    while(!q.empty()){
        string str=q.front().first;
        int val=q.front().second;
        q.pop();

        for(int i=0;i<str.size();i++){
            string temp=str;
            for(int j=0;j<26;j++){
                temp[i]=('a'+j);

                if(temp==goal)
                    return val+1;

                if(dict.find(temp)!=dict.end()){
                    dict.erase(temp);
                    q.push({temp,val+1});
                }
            }
        }
    }

    return 0;
}

int main(){
    int n;
    cout<<"Enter the number of words in the dictionary: ";
    cin>>n;
    unordered_map<string,int> dict;

    cout<<"Enter the words in the dictionary:\n\n";
    for(int i=0;i<n;i++){
        string s;
        cin>>s;
        dict[s]=1;
    }
    
    string start,end;
    cout<<"Enter the starting word and the ending word: ";
    cin>>start>>end;

    if(dict.find(end)==dict.end() || start.size()!=end.size()){
        cout<<"Invalid inputs\n";
        return 1;
    }

    cout<<"The minimum number of transformations required to reach goal from start is: "<<BFS(dict,start,end);
    return 0;
}

//Time comlexity: O(n*(size of word)*26)