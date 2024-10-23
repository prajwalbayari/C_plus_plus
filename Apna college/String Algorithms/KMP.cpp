//KMP string matching algorithm
//Time complexity O(text.size()+pattern.size())

#include<iostream>
#include<string>
#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> prefix(string s)
{
    vector<int> ans(s.size(),0);
    for(int i=1;i<s.size();i++)
    {
        int j=ans[i-1];
        while(j>0 && s[i]!=s[j])
            j=ans[j-1];
        if(s[i]==s[j])
            j++;
        ans[i]=j;
    }
    return ans;
}

int main()
{
    string text,pattern;
    cout<<"Enter the text:\n";
    getline(cin,text);
    cout<<"Enter the pattern:\n";
    getline(cin,pattern);
    vector<int> pre=prefix(text);
    int i(0),j(0),pos(-1);
    while(i<text.size())
    {
        if(text[i]==pattern[j])
            i++,j++;
        else{
            if(j!=0)
                j=pre[j-1];
            else
                i++;
        }
        if(j==pattern.size())
        {
            pos=i-pattern.size();
            break;
        }
    }
    if((pos+1)!=0)
        cout<<"Pattern found in the position "<<pos<<endl;
    else    
        cout<<"Pattern not found\n";
}