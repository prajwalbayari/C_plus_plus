#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;

// Three sum

// bool Threesum(vector<int> v,int t)
// {
//     int n=v.size();
//     for(int i=0;i<n;i++)
//     {
//         int lo=i+1,hi=n-1;
//         while(lo<hi)
//         {
//             int cur=v[lo]+v[hi]+v[i];
//             if(cur==t)
//             {
//                 cout<<"True\n";
//                 return true;
//             }
//             if(cur<t)
//             {
//                 lo+=1;
//             }
//             if(cur>t)
//             {
//                 hi-=1;
//             }
//         }
//     }
//     cout<<"False\n";
//     return false;
// }

// int main()
// {
//     int m,n,t;
//     vector<int> v;
//     cout<<"Enter the size of the array:\n";
//     cin>>n;
//     cout<<"Enter the array elements:\n";
//     for(int i=0;i<n;i++)
//     {
//         cin>>m;
//         v.push_back(m);
//     }
//     sort(v.begin(),v.end());
//     cout<<"Enter the taregt:\n";
//     cin>>t;
//     cout<<Threesum(v,t);
// }

//Maximum consecutive ones

// int main()
// {
//     int n,k,zerocnt=0,ans=0,i=0;
//     cout<<"Enter the size of the array\n";
//     cin>>n;
//     cout<<"Enter the value of k\n";
//     cin>>k;
//     vector<int> v(n);
//     cout<<"Enter array elemets\n";
//     for(int j=0;j<n;j++)
//     {
//         cin>>v[j];
//     }
//     for(int j=0;j<n;j++)
//     {
//         if(v[j]==0)
//         {
//             zerocnt++;
//         }
//         while(zerocnt>k)
//         {
//             if(v[i]==0)
//             {
//                 zerocnt--;
//             }
//             i++;
//         }
//         ans=max(ans,j-i+1);
//     }
//     cout<<"Maximum number of continous one's is: "<<ans<<endl;
// }

//Longest substring without repeating chararcters

// int main()
// {
//     string s;
//     vector<int> v(256,-1);
//     int maxLen=0,start=-1,n;
//     cout<<"Enter the string\n";
//     cin>>s;
//     n=s.size();
//     for(int i=0;i<n;i++)
//     {
//         if(v[s[i]]>start)
//         {
//             start=v[s[i]];
//         }
//         v[s[i]]=i;
//         maxLen=max(maxLen,i-start);
//     }
//     cout<<maxLen<<endl;
// }