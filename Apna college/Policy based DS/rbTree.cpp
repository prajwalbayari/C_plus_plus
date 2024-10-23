//Policy based Data structures

#include<iostream>
#include<stdlib.h>
using namespace std;

// #include<ext/pb_ds/assoc_container.hpp>
// #include<ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;

template<class T> using oset=tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;

// int main()
// {
//     int q,c;
//     cout<<"Enter number of queries\n";
//     cin>>q;
//     while(q--)
//     {
//         int t;
//         cout<<"Enter operation:\n";
//         cin>>c;
//         if(c==1)
//         {
//             cin>>t;
//             s.insert(t);
//         }
//         else if(c==2)
//         {
//             cin>>t;
//             cout<<*s.find_by_order(t)<<endl;
//         }
//         else
//         {
//             cin>>t;
//             cout<<*s.order_of_key(t)<<endl;
//         }
//     }
// }