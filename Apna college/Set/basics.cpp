#include<iostream>
#include<set>
#include<unordered_set>
using namespace std;

// int main()
// {
//     set<int> s;
//     s.insert(1);
//     s.insert(2);
//     s.insert(2);
//     s.insert(3);
//     for(auto i:s)
//     {
//         cout<<i<<" ";
//     }
//     cout<<endl;
//     cout<<s.size()<<endl;
//     s.erase(2);
//     for(auto i:s)
//     {
//         cout<<i<<" ";
//     }
//     cout<<endl;
//     return 0;
// }

// int main()
// {
//     multiset<int> s;
//     s.insert(1);
//     s.insert(2);
//     s.insert(2);
//     s.insert(3);
//     s.insert(3);
//     s.insert(3);
//     s.insert(3);
//     for(auto i:s)
//     {
//         cout<<i<<" ";
//     }
//     cout<<endl;
//     cout<<s.size()<<endl;
//     // s.erase(3);
//     s.erase(s.find(3));
//     for(auto i:s)
//     {
//         cout<<i<<" ";
//     }
//     cout<<endl;
//     return 0;
// }

int main()
{
    unordered_set<int> s;
    s.insert(10);
    s.insert(22);
    s.insert(2);
    s.insert(3);
    s.insert(3);
    s.insert(3);
    s.insert(3);
    for(auto i:s)
    {
        cout<<i<<" ";
    }
    cout<<endl;
    cout<<s.size()<<endl;
    // s.erase(3);
    s.erase(s.find(3));
    for(auto i:s)
    {
        cout<<i<<" ";
    }
    cout<<endl;
    return 0;
}

