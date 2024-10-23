//Given an array of size N give the maximum sum of 2 subarrays of which first subarray starts at a and ends at b
//and the second subarray starts at c and ends at d 1<=a<=b<c<=d<=N (minimum size of array is 4)

#include<iostream>
#include<stdlib.h>
#include<algorithm>
#include<vector>
using namespace std;

int int_size=32;

class TrieNode
{
    public:
    TrieNode* next[2];
    TrieNode()
    {
        next[0]=NULL;
        next[1]=NULL;
    }
};

TrieNode* trie;

void insert(int num)
{
    TrieNode* it=trie;
    for(int i=0;i<int_size-1;i++)
    {
        int cur_bit=(num>>i)&1;
        if(!it->next[cur_bit])
            it->next[cur_bit]=new TrieNode();
        it=it->next[cur_bit];
    }
}

int query(int num)
{
    TrieNode* it=trie;
    int ans=0;
    for(int i=0;i<int_size-1;i++)
    {
        int cur_bit=(num>>i)&1;
        int opp=cur_bit^1;
        if(it->next[opp])
        {
            it=it->next[opp];
            ans|=1<<i;
        }
        else
        {
            it=it->next[cur_bit];
        }
    }
    return ans;
}

int main()
{
    int n;
    cout<<"Enter the number of elements in array(greater than 3 only):";
    cin>>n;
    cout<<"Enter array elements:\n";
    vector<int> vec(n);
    for(int i=0;i<n;i++)
        cin>>vec[i];
    trie=new TrieNode();
    insert(0);
    vector<int> rMax(n+1,0);
    int R=0;
    for(int i=n-1;i>=0;i--)
    {
        R^=vec[i];
        if(i!=n-1)
        {
            rMax[i]=max(rMax[i],query(R));
            insert(R);
        }
        else
        {
            rMax[i]=query(R);
            insert(R);
        }
    }
    free(trie);
    trie=new TrieNode();
    insert(0);
    int ans=0,L=0;
    for(int i=0;i<n;i++)
    {
        L^=vec[i];
        ans=max(ans,rMax[i+1]+query(L));
        insert(L);
    }
    cout<<"Maximum xor sum of 2 subarrays is: "<<ans<<endl;
}