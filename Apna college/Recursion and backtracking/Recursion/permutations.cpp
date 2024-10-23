#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<stdlib.h>
using namespace std;

vector<vector<int>> ans;


//Permutations 1


// void permute(vector<int> &a,int id)
// {
//     if(id==a.size())
//     {
//         ans.push_back(a);
//         return;
//     }
//     for(int i=id;i<a.size();i++)
//     {
//         swap(a[i],a[id]);
//         permute(a,id+1);
//         swap(a[i],a[id]);
//     }
//     return;
// }

// int main()
// {
//     int i;
//     cout<<"Enter the size of the vector\n";
//     cin>>i;
//     cout<<"Enter the array elements:\n";
//     vector<int> arr(i);
//     for(auto &i:arr)
//     {
//         cin>>i;
//     }
//     permute(arr,0);
//     for(auto v:ans)
//     {
//         for(auto i:v)
//         {
//             cout<<i<<" ";
//         }
//         cout<<endl;
//     }
// }

// int main()
// {
//     int i;
//     cout<<"Enter the size of the vector\n";
//     cin>>i;
//     cout<<"Enter the array elements:\n";
//     vector<int> arr(i);
//     for(auto &i:arr)
//     {
//         cin>>i;
//     }
//     std::sort(arr.begin(),arr.end());
//     do
//     {
//         ans.push_back(arr);
//     }while(next_permutation(arr.begin(),arr.end()));
//     for(auto v:ans)
//     {
//         for(auto i:v)
//         {
//             cout<<i<<" ";
//         }
//         cout<<endl;
//     }
// }

//Permutations 2

void helper(vector<int> a,int id)
{
    if(id=a.size())
    {
        ans.push_back(a);
        return;
    }
    for(int i=id;i<a.size();i++)
    {
        if(i!=id || a[i]==a[id])
        {
            continue;
        }
        swap(a[i],a[id]);
        helper(a,id+1);
        swap(a[i],a[id]);
    }
    return;
}

void permute(vector<int> a)
{
    sort(a.begin(),a.end());
    helper(a,0);
}

int main()
{
    int i;
    cout<<"Enter the size of the vector\n";
    cin>>i;
    cout<<"Enter the array elements:\n";
    vector<int> arr(i);
    for(auto &i:arr)
    {
        cin>>i;
    }
    permute(arr);
    for(auto v:ans)
    {
        for(auto i:v)
        {
            cout<<i<<" ";
        }
        cout<<endl;
    }
}