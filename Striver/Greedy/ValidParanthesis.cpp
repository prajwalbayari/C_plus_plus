// Find the validity of an input string s that only contains the letters '(', ')' and '*'.
// A string entered is legitimate if
// Any left parenthesis '(' must have a corresponding right parenthesis ')'.
// Any right parenthesis ')' must have a corresponding left parenthesis '('.
// Left parenthesis '(' must go before the corresponding right parenthesis ')'.
// '*' could be treated as a single right parenthesis ')' or a single left parenthesis '(' or an empty string "".

#include<iostream>
#include<string>
using namespace std;

// Time complexity: O(3^k) k=number of stars
// Space complexity: O(n)
bool isValid(string str,int cnt,int idx){
    if(cnt<0)
        return false;
    if(idx==str.size())
        return cnt==0;
    if(str[idx]=='(')
        return isValid(str,cnt+1,idx+1);
    else if(str[idx]==')')
        return isValid(str,cnt-1,idx+1);
    bool empty=isValid(str,cnt,idx+1);
    bool open=isValid(str,cnt+1,idx+1);
    bool closed=isValid(str,cnt-1,idx+1);
    return (empty||open||closed);
}

//Time complexity: O(n)
//Space complexity: O(1)
void iterative(string s){
    int mini=0,maxi=0;
    for(int i=0;i<s.size();i++){
        if(s[i]=='(')
            mini++,maxi++;
        else if(s[i]==')')
            mini--,maxi--;
        else
            mini--,maxi++;
        mini=max(mini,0);
        if(maxi<0){
            cout<<"It is not a valid paranthesis string\n";
            return;
        }
    }
    if(mini==0)  
        cout<<"It is a valid paranthesis string\n";
    else
        cout<<"It is not a valid paranthesis string\n";
}

int main(){
    string str;
    cout<<"Enter the paranthesis sequence: ";
    cin>>str;
    iterative(str);
    // if(isValid(str,0,0))
    //     cout<<"It is a valid paranthesis\n";
    // else
    //     cout<<"It is not a valid paranthesis\n";
}