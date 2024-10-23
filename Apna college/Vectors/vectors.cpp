#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//VECTOR DYNAMICALLY ALLOCATES MEMORY IN ARRAYS
// MAIN FUNCTIONS OF VECTOR
// int main()
// {
//     vector<int> v;
//     v.push_back(1);
//     v.push_back(2);
//     v.push_back(3);

//     for(int i=0;i<v.size();i++)         //USING SIZE
//     {
//         cout<<v[i]<<" ";
//     }
//     cout<<endl;

//     vector<int>::iterator it;            //USING ITERATOR
//     for(it=v.begin();it!=v.end();it++)
//     {
//         cout<<*it<<" ";
//     }
//     cout<<endl;
//     for(auto element:v)                 //USING AUTO 
//     {
//         cout<<element<<" ";            //AUTO ITSELF IDENTIFIES THE TYPE OF DATA AND GIVES OUTPUT
//     }
//     cout<<endl;

//     v.pop_back();
//     vector<int> v2 (3,50);   //v(a,b) --> a is number of elements b is element
//     swap(v,v2);       //swapping the values in two vectors
//     for(auto element:v)
//     {
//         cout<<element<<" ";
//     }
//     cout<<endl;
//     for(auto element:v2)
//     {
//         cout<<element<<" ";
//     }
//     cout<<endl;
//     return 0;
// }

// int main()
// {
//     vector<int> v={1,2,3,4,5};
//     cout<<v.size()<<endl;
//     cout<<v.size()%2<<endl;
// }

// std::pair

// int main()
// {
//     pair<int,char> p;
//     p.first =33;
//     p.second ='v';
//     cout<<p.first<<endl;
//     cout<<p.second<<endl;
// }

// bool myCompare(pair<int,int> p1,pair<int,int> p2)
// {
//     return p1.first<p2.first;
// }
// int main()
// {
//     int arr[8]={10,16,7,14,5,3,12,9};
//     vector<pair<int,int>> v;
//     for(int i=0;i<(sizeof(arr)/sizeof(arr[0]));i++)
//     {
//         v.push_back(make_pair(arr[i],i));
//     }

//     sort(v.begin(),v.end(),myCompare);
//     for(int i=0;i<v.size();i++)
//     {
//         arr[v[i].second]=i;
//     }
//     for(int i=0;i<v.size();i++)
//     {
//         cout<<arr[i]<<" ";
//     }
//     cout<<endl;
// }

// int main()
// {
//     char *num1="123",*num2="456";
//     int first=0,second=0,i=0;
//         while(num1[i]!='\0')
//         {
//             first=first*10+num1[i];
//             i++;
//         }
//         i=0;
//         while(num2[i]!='\0')
//         {
//             second=second*10+num2[i];
//             i++;
//         }
//         first=atoi(num1);
//         cout<<first<<" "<<second<<endl;
// }

// vector pairs 

int main()
{
    vector<pair<int,int>> v;
    int n,m,r;
    cout<<"Enter the numbe of student\n";
    cin>>n;
    cout<<"Enter the student roll number and marks\n";
    for(int i=0;i<n;i++)
    {
        cin>>r>>m;
        v.push_back(make_pair(r,m));
    }
    sort(v.begin(),v.end());
}