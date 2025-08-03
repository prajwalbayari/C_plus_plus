// Given a string s , consisting only of characters 'a' , 'b' , 'c'.Find the number of substrings that contain at least one occurrence of all these characters 'a' , 'b' , 'c'.

#include<iostream>
#include<vector>
#include<string>
using namespace std;

int optimized(string& str){
    int ans=0;
    vector<int> vec(3,-1);
    for(int i=0;i<str.size();i++){
        vec[str[i]-'a']=i;
        if(vec[0]!=-1 && vec[1]!=-1 && vec[2]!=-1)
            ans=ans+min(vec[0],min(vec[1],vec[2]))+1;
    }
    return ans;
}

int main(){
    string str;
    cout<<"Enter the string: ";
    cin>>str;
    int left=0,right=0,ans=0;
    vector<int> vec(3,0);
    while(right<str.size()){
        vec[str[right]-'a']++;
        while(vec[0] && vec[1] && vec[2]){
            ans=ans+str.size()-right;
            vec[str[left]-'a']--;
            left++;
        }
        right++;
    }
    cout<<"The number of substrings is: "<<ans<<endl;
    cout<<"Optimal approach answer: "<<optimized(str)<<endl;
}

// Time complexity: O(2*n)
// Space complexity: O(3)

//Optimized
// Time complexity: O(n)
// Space complexity: O(3)