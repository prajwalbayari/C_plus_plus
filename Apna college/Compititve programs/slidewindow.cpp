#include<iostream>
#include<deque>
#include<vector>
#include<stack>
#include<set>
#include<string>
using namespace std;

// DOUBLY ENDED QUEUE

// int main()
// {
//     deque<int> d;
//     d.push_back(10);
//     d.push_front(5);
//     d.push_back(15);
//     d.push_back(20);
//     for(auto i:d)
//     {
//         cout<<i<<" ";
//     }
//     cout<<endl;
//     d.pop_back();
//     d.pop_front();
//     for(auto i:d)
//     {
//         cout<<i<<" ";
//     }
//     cout<<endl;
// }

//SLIDING WINDOW MAXIMUM

//UNOPTIMIZED SOLUTION

// int main()
// {
//     int n,k;
//     cout<<"Enter the number of elements of the array\n";
//     cin>>n;
//     vector<int> v(n);
//     cout<<"Enter the array elements\n";
//     for(auto &j: v)
//     {
//         cin>>j;
//     }
//     cout<<"Enter the window size\n";
//     cin>>k;
//     multiset<int,greater<int>> s;
//     vector<int> ans;
//     for(int i=0;i<k;i++)
//     {
//         s.insert(v[i]);
//     }
//     ans.push_back(*s.begin());
//     for(int i=k;i<n;i++)
//     {
//         s.erase(s.lower_bound(v[i-k]));
//         s.insert(v[i]);
//         ans.push_back(*s.begin());
//     }
//     for(auto j: ans)
//     {
//         cout<<j<<" ";
//     }
//     cout<<endl;
//     return 0;
// }

//OPTIMIZED SOLUTION

// int main()
// {
//     int n,k;
//     cout<<"Enter the number of elements of the array\n";
//     cin>>n;
//     vector<int> v(n);
//     cout<<"Enter the array elements\n";
//     for(auto &j: v)
//     {
//         cin>>j;
//     }
//     cout<<"Enter the window size\n";
//     cin>>k;
//     deque<int> q;
//     vector<int> ans;
//     for(int i=0;i<k;i++)
//     {
//         while(!q.empty() && v[q.back()]<v[i])
//         {
//             q.pop_back();
//         }
//         q.push_back(i);
//     }
//     ans.push_back(v[q.front()]);
//     for(int i=k;i<n;i++)
//     {
//         if(q.front()==i-k)
//         {
//             q.pop_front();
//         }
//         while(!q.empty() && v[q.back()]<v[i])
//         {
//             q.pop_back();
//         }
//         q.push_back(i);
//         ans.push_back(v[q.front()]);
//     }
//     for(int i=0;i<ans.size();i++)
//     {
//         cout<<ans[i]<<" ";
//     }
//     cout<<endl;
// }

//LARGEST RECTANGLE IN A HISTOGRAM

// int get_max_area(vector<int> v)
// {
//     int n=v.size(),ans=0,i=0;
//     v.push_back(0);
//     stack<int> st;
//     while(i<n)
//     {
//         while(!st.empty() && v[st.top()]>v[i])
//         {
//             int t=st.top();
//             int h=v[t];
//             st.pop();
//             if(st.empty())
//             {
//                 ans=max(ans,h*i);
//             }
//             else
//             {
//                 int len=i-st.top()-1;
//                 ans=max(ans,h*len);
//             }
//         }
//         st.push(i);
//         i++;
//     }
//     return ans;
// }

// int main()
// {
//     int n,m;
//     vector<int> v;
//     cout<<"Enter the number of bars in the histogram\n";
//     cin>>n;
//     cout<<"Enter the size of the bars of the histogram\n";
//     for(int i=0;i<n;i++)
//     {
//         cin>>m;
//         v.push_back(m);
//     }
//     cout<<"Maximum area is:\n";
//     cout<<get_max_area(v)<<endl;
// }

// Trapping rain water

// int rain_water(vector<int>& v)
// {
//     stack<int> st;
//     int ans=0,n=v.size(),i=0;
//     for(int i=0;i<n;i++)
//     {
//         while(!st.empty() && v[st.top()]<v[i])
//         {
//             int cur=st.top();
//             st.pop();
//             if(st.empty())
//             {
//                 break;
//             }
//             int diff=i-st.top()-1;
//             ans+=(min(v[st.top()],v[i])-v[cur])*diff;
//         }
//         st.push(i);
//     }
//     return ans;
// }

// int main()
// {
//     int n,m;
//     vector<int> v;
//     cout<<"Enter the number of the bars:\n";
//     cin>>n;
//     cout<<"Enter the height of the each bar\n";
//     for(int i=0;i<n;i++)
//     {
//         cin>>m;
//         v.push_back(m);
//     }
//     cout<<"The amount of water stored is : "<<rain_water(v)<<" units\n";
// }

//Reduntant paranthesis

// bool paranthesis(string s)
// {
//     int n=s.size();
//     stack<char> st;
//     bool ans=false;
//     for(int i=0;i<n;i++)
//     {
//         if(s[i]=='(' || s[i]=='+' || s[i]=='-' || s[i]=='*' || s[i]=='/' || s[i]=='%')
//         {
//             st.push(s[i]);
//         }
//         else if(s[i]==')')
//         {
//             if(st.top()=='(')
//             {
//                 ans=true;
//             }
//             while(st.top()!='(')
//             {
//                 st.pop();
//             }
//             st.pop();
//         }
//     }
//     return ans;
// }

// int main()
// {
//     string s;
//     cout<<"Enter the string\n";
//     cin>>s;
//     cout<<paranthesis(s);
// }

//Stock span problem

vector<int> stock_span(vector<int> v)
{
    stack<pair<int,int>> st;
    vector<int> a;
    for(auto prices:v)
    {
        int days=1;
        while(!st.empty() && st.top().first<=prices)
        {
            days+=st.top().second;
            st.pop();
        }
        st.push({prices,days});
        a.push_back(days);
    }
    return a;
}

int main()
{
    int n,m;
    vector<int> v;
    cout<<"Enter the number of days:\n";
    cin>>n;
    cout<<"Enter the stock rate:\n";
    for(int i=0;i<n;i++)
    {
        cin>>m;
        v.push_back(m);
    }
    vector<int> ans=stock_span(v);
    cout<<"The result is:\n";
    for(int i=0;i<ans.size();i++)
    {
        cout<<ans[i]<<" ";
    }
    cout<<endl;
}