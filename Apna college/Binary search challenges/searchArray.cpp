//Find an element in the sorted rotated array

#include<iostream>
#include<climits>
#include<vector>
using namespace std;

int searchInRotatedArray(vector<int> v,int key,int left,int right)
{
    if(left>right)
    {
        return -1;
    }
    int mid=(left+right)/2;
    if(v[mid]==key)
    {
        return mid;
    }

    if(v[left]<=v[mid])
    {
        if(key>=v[left] && key<=v[mid])
        {
            return searchInRotatedArray(v,key,left,mid-1);
        }
        return searchInRotatedArray(v,key,mid+1,right);
    }
    if(key>=v[mid] && key<=v[right])
    {
        return searchInRotatedArray(v,key,mid+1,right);
    }
    return searchInRotatedArray(v,key,left,mid-1);
}

int main()
{
    vector<int> v={30,40,50,10,20};
    int i=searchInRotatedArray(v,100,0,4);
    if(i==-1)
    {
        cout<<"Element does not exist in the array\n";
    }
    else
    {
        cout<<"Element present in posistion "<<i<<endl;
    }
    return 0;
}