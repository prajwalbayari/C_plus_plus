//Find sum of array elements in a given range

//Time complexity: O(sqrt(n))

#include<iostream>
#include<math.h>
#include<stdlib.h>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
    int n,len,q;
    cout<<"Enter the number of elements in array: ";
    cin>>n;
    len=sqrt(n)+1;
    vector<int> vec(n),temp(len,0);
    cout<<"Enter the array elements: ";
    for(int i=0;i<n;i++)
        cin>>vec[i];
    for(int i=0;i<n;i++)
    {
        temp[i/len]+=vec[i];
    }
    cout<<"Enter the number of queries: ";
    cin>>q; 
    while(q--)
    {
        int l,r;
        cout<<"\nEnter range lying between 0 to "<<n-1<<" :";
        cin>>l>>r;
        int sum=0;
        for(int i=l;i<=r;)
        {
            if(i%len==0 && i+len-1<=r)
            {
                sum+=temp[i/len];
                i+=len;
            }
            else   
            {
                sum+=vec[i];
                i++;
            } 
        }
        cout<<"Sum is "<<sum<<endl;
    }
}