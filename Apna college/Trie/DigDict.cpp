//A digital dictionary where if you put the prefix of a word it will list out all the words in the
//dictionary that has the string as its prefix

#include<iostream>
#include<stdlib.h>
#include<algorithm>
#include<vector>
using namespace std;

class Node
{
    public:
    bool end;
    Node* next[26];
    Node()
    {
        end=false;
        for(int i=0;i<26;i++)
            next[i]=NULL;
    }
};

class Trie
{
    private:
    Node* trie;
    public:
    Trie()
    {
        trie=new Node();
    }

    void insert(string s)
    {
        Node* it=trie;
        int i=0;
        while(i<s.size())
        {
            if(it->next[s[i]-'a']==NULL)
                it->next[s[i]-'a']=new Node();
            it=it->next[s[i]-'a'];
            i++;
        }
        it->end=true;
    }

    void find(string s)
    {
        Node* it=trie;
        int i=0;
        while(i<s.size())
        {
            if(it->next[s[i]-'a']==NULL)
            {
                cout<<"No match found\n";
                insert(s);
                return;
            }
            it=it->next[s[i]-'a'];
            i++;
        }
        vector<string> res;
        printAll(res,it,s,"");
        cout<<"\nMatching results are:\n";
        for(int i=0;i<res.size();i++)
            cout<<res[i]<<endl;
        cout<<endl;
    }

    void printAll(vector<string>& res,Node* it,string& s,string cur)
    {
        if(it==NULL)
            return;
        if(it->end==true)
            res.push_back(s+cur);
        for(int i=0;i<26;i++)
        {
            if(it->next[i]!=NULL)
                printAll(res,it->next[i],s,cur+char('a'+i));
        }
    }
};

int main()
{
    int n,a=0;
    string str;
    Trie* trie=new Trie();
    cout<<"Enter the number of words in dictionary: ";
    cin>>n;
    cout<<"Enter the strings in the dictionary (words should only have lowercase english alphabets):\n";
    for(int i=0;i<n;i++)
    {
        cin>>str;
        trie->insert(str);
    }
    while(a!=2)
    {
        cout<<"\n1.Search\n2.Exit\nEnter your choice: ";
        cin>>a;
        switch(a)
        {
            case 1:cout<<"Enter the prefix string:\n";
                   cin>>str;
                   trie->find(str);
                   break;
            case 2:cout<<"Thank you\n";
                    break;
            default:cout<<"Invalid choice!!\n";
                    break;
        }
        
    }
    return 0;
}