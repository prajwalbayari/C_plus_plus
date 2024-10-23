#include<iostream>
#include<conio.h>
#include<climits>
using namespace std;


// Used to find the maximum sum of subarray in an array
int main()
{
    int n,sum=0,m=INT_MIN;
    cout<<"Enter the size of the array\n";
    cin>>n;
    int arr[100];
    cout<<"Enter the array elements\n";
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    for(int i=0;i<n;i++)
    {
        sum+=arr[i];
        m=max(sum,m);
        if(sum<0)
        {
            sum=0;
        }
    }
    cout<<"Maximum sum of the sub arrays is: "<<m<<endl;
    return 0;
}