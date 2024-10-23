//Mo's Algorithm: It is an offline fashion of solving all queries by taking all queries at once through input
//Sort them and give output after processing them this saves processor time

#include<iostream>
#include<vector>
#include<math.h>
#include<algorithm>
#include<limits.h>
using namespace std;

#define N 10000

int n,rootN;

struct Q
{
    int idx,l,r;
};

bool compare(Q q1,Q q2)
{
    if(q1.l/rootN==q2.l/rootN)
        return q1.r>q2.r;
    return q1.l/rootN<q2.l/rootN;
}

Q querry[N];

int main()
{
    cout<<"Enter the size of the array: ";
    cin>>n;
    cout<<"Enter the array elements: ";
    vector<int> vec(n);
    for(int i=0;i<n;i++)    
        cin>>vec[i];
    rootN=sqrt(n);
    int q;
    cout<<"Enter the number of queries: ";
    cin>>q;
    cout<<"Enter the queries (Consider 0-based indexing): ";
    for(int i=0;i<q;i++)
    {
        int l,r;
        cin>>l>>r;
        querry[i].l=l;
        querry[i].r=r;
        querry[i].idx=i;
    }
    sort(querry,querry+q,compare);

    vector<int> answers(q);
    int curr_l=0,curr_r=-1,l,r,curr_ans=0;
    for(int i=0;i<q;i++)
    {
        l=querry[i].l,r=querry[i].r;

        while(curr_r<r)
        {
            curr_r++;
            curr_ans+=vec[curr_r];
        }

        while(curr_l>l)
        {
            curr_l--;
            curr_ans+=vec[curr_l];
        }

        while(curr_l<l)
        {
            curr_ans-=vec[curr_l];
            curr_l++;
        }

        while(curr_r>r)
        {
            curr_ans-=vec[curr_r];
            curr_r--;
        }
        answers[querry[i].idx]=curr_ans;
    }

    cout<<"Answers for the queries are:\n\n";
    for(int i=0;i<q;i++)
        cout<<answers[i]<<endl;
    
    return 0;
}