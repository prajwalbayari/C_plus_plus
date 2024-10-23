//Given an array of n elements give the number of distinct elements in the range i to j 0<=i<=j<=n

#include<iostream>
#include<algorithm>
#include<vector>
#include<math.h>
using namespace std;

#define N 100000

int n,rootN;

struct Q
{
    int idx,l,r;
};

bool compare(Q q1,Q q2)
{
    if(q1.l/rootN==q2.l/rootN)
        return q1.r>q2.r;
    return q1.l<q2.l;
}

int main()
{
    int queries;
    cout<<"Enter the number of elements in the array: ";
    cin>>n;
    rootN=sqrt(n);
    Q querries[N];
    cout<<"Enter the array elements: ";
    vector<int> vec(n);
    for(int i=0;i<n;i++)
        cin>>vec[i];
    cout<<"Enter the number of queries: ";
    cin>>queries;
    cout<<"Enter the queries (Consider 1-based indexing):\n";
    for(int i=0;i<queries;i++)
    {
        int l,r;
        cin>>l>>r;
        querries[i].l=l;
        querries[i].r=r;
        querries[i].idx=i;
    }

    sort(querries,querries+queries,compare);

    vector<int> answers(queries),freq(1000001,0);

    int cur_l=0,cur_r=-1,l,r,cur_ans=0;

    for(int i=0;i<queries;i++)
    {
        l=querries[i].l-1,r=querries[i].r-1;

        while(cur_r<r)
        {
            cur_r++;
            freq[vec[cur_r]]++; 
            if(freq[vec[cur_r]]==1)
                cur_ans++;
        }

        while(cur_l>l)
        {
            cur_l--;
            freq[vec[cur_l]]++; 
            if(freq[vec[cur_l]]==1)
                cur_ans++;
        }

        while(cur_l<l)
        {
            freq[vec[cur_l]]--; 
            if(freq[vec[cur_l]]==0)
                cur_ans--;
            cur_l++;
        }

        while(cur_r>r)
        {
            freq[vec[cur_r]]--; 
            if(freq[vec[cur_r]]==0)
                cur_ans--;
            cur_r--;
        }
        answers[querries[i].idx]=cur_ans;
    }

    cout<<"\nAnswers for the queries are:\n\n";
    for(int i=0;i<queries;i++)
        cout<<answers[i]<<endl;
    return 0;
}