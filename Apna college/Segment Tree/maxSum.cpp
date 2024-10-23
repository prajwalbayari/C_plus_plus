//Given an array of n elements that include both positive and negative integers find the maximum possible sum obtained
//by subarray sum. Note that if the array containes all negative numbers the answer is 0

#include<iostream>
#include<algorithm>
#include<limits.h>
#include<vector>
using namespace std;

class group
{
    public:
    int sum,ans,pref,suff;
    group(int s,int a,int pre,int suf)
    {
        sum=s,ans=a,pref=pre,suff=suf;
    }
};

vector<group*> Tree;

void build(int Node,int start,int end,vector<int> vec)
{
    if(start==end)
    {
        if(vec[start]<=0)
            Tree[Node]=new group(vec[start],0,0,0);
        else
            Tree[Node]=new group(vec[start],vec[start],vec[start],vec[start]);
        return;
    }
    int mid=(start+end)/2;
    build(2*Node,start,mid,vec);
    build(2*Node+1,mid+1,end,vec);
    int sum=Tree[2*Node]->sum+Tree[2*Node+1]->sum;
    int pref=max(Tree[2*Node]->pref,Tree[2*Node]->sum+Tree[2*Node+1]->pref);
    int suff=max(Tree[2*Node+1]->suff,Tree[2*Node]->suff+Tree[2*Node+1]->sum);
    int ans=max(max(Tree[2*Node]->ans,Tree[2*Node+1]->ans),Tree[2*Node]->suff+Tree[2*Node+1]->pref);
    Tree[Node]=new group(sum,ans,pref,suff);
}

void update(int Node,int start,int end,int idx,int val,vector<int>& vec)
{
    if(start==end)
    {
        vec[start]=val;
        delete Tree[Node];
        if(vec[start]<=0)
            Tree[Node]=new group(vec[start],0,0,0);
        else
            Tree[Node]=new group(vec[start],vec[start],vec[start],vec[start]);
        return;
    }

    int mid=(start+end)/2;

    if(idx<=mid)
        update(2*Node,start,mid,idx,val,vec);
    else
        update(2*Node+1,mid+1,end,idx,val,vec);

    int sum=Tree[2*Node]->sum+Tree[Node*2+1]->sum;
    int pref=max(Tree[2*Node]->pref,Tree[2*Node]->sum+Tree[Node*2+1]->pref);
    int suff=max(Tree[Node*2+1]->suff,Tree[2*Node]->suff+Tree[Node*2+1]->sum);
    int ans=max(max(Tree[2*Node]->ans,Tree[Node*2+1]->ans),Tree[2*Node]->suff+Tree[Node*2+1]->pref);
    delete Tree[Node];
    Tree[Node]=new group(sum,ans,pref,suff);
}

int main()
{
    int n,ch;
    cout<<"Enter the number of elements: ";
    cin>>n;
    cout<<"Enter the array elements: ";
    vector<int> arr(n);
    for(int i=0;i<n;i++)    
        cin>>arr[i];

    Tree=vector<group*>(4*n);
    build(1,0,n-1,arr);

    while(ch!=5)
    {
        cout<<"\n1.Show Tree answers\n2.Update element\n3.Find maximum sum\n4.Show array\n5.Exit\nEnter your choice: ";
        cin>>ch;
        switch(ch)
        {
            case 1:cout<<"Tree values: ";
                    for(int i=1;i<2*n;i++)
                        cout<<Tree[i]->ans<<" ";
                    cout<<endl;
                    break;
            case 2:int val,idx;
                    cout<<"Enter a valid index and new value: ";
                    cin>>idx>>val;
                    update(1,0,n-1,idx,val,arr);
                    cout<<"Value updated successfully\n";
                    break;
            case 3:cout<<"Maximum sum of segment is: "<<Tree[1]->ans<<endl;
                    break;
            case 4:cout<<"Array elements: ";
                    for(int i=0;i<n;i++)
                        cout<<arr[i]<<" ";
                    cout<<endl;
                    break; 
            case 5:cout<<"Thank you\n\n";
                    break;
            default:cout<<"Invalid input!!!\n";
                    break;
        }
    }
}