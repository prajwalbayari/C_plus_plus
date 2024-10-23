//Trie is also called prefix tree every node has 26 children representing letters

#include<string>
#include<iostream>
#include<stdlib.h>
#include<vector>
using namespace std;

class Trie
{
    public:
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
    Node* trie;
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

    bool search(string s)
    {
        Node* it=trie;
        int i=0;
        while(i<s.size())
        {
            if(it->next[s[i]-'a']==NULL)
                return false;
            it=it->next[s[i]-'a'];
            i++;
        }
        return it->end;
    }
};

int main()
{
    Trie* T=new Trie();
    int c,a=1;
    string s;
    while(a)
    {
        cout<<"\nMenu\n 1.Insert into trie\n 2.Search in trie\n 3.Exit\nEnter your choice: ";
        cin>>c;
        switch(c)
        {
            case 1:cout<<"Enter a string: ";
                    cin>>s;
                    T->insert(s);
                    cout<<"String inserted successfully\n";
                    break;
            case 2:cout<<"Enter a string to search: ";
                    cin>>s;
                    if(T->search(s)==true)
                        cout<<"String is present\n";
                    else    
                        cout<<"String is not present\n";
                    break;
            case 3:cout<<"Thank you\n\n";
                    a=0;
                    break;
            default:cout<<"Invalid input please try again\n";
        }
    } 
}