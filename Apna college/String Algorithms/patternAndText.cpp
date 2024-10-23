//Find all the occurences of a pattern in a text

#include<iostream>
#include<string>
#include<stdio.h>
#include<algorithm>
using namespace std;

//Time complexity = O(text.size()*pattern.size())

int main()
{
    string text,pattern;
    cout<<"Enter the text\n";
    getline(cin,text);
    cout<<"Enter the pattern\n";
    getline(cin,pattern);
    int k=1;
    for(int i=0;i<text.size();i++)
        if(text.substr(i,pattern.size())==pattern)
            cout<<"Occurence "<<(k++)<<" at index "<<i<<endl;
}