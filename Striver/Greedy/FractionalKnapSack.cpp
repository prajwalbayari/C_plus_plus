// You're given `N` items with weights `W[i]` and values `V[i]`, and a knapsack with capacity `C`.
// You can take **fractions** of items to **maximize the total value** in the knapsack.
// Return the **maximum value** achievable, rounded to two decimal places.

#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

int main(){
    int n,W;
    cout<<"Enter the number of items:";
    cin>>n;
    vector<vector<int>> items(n,vector<int>(2));
    cout<<"Enter the value and weight of each item: ";
    for(int i=0;i<n;i++)
        cin>>items[i][0]>>items[i][1];

    cout<<"Enter the capacity of the knapsack: ";
    cin>>W;

    double ans=0.0;
    priority_queue<pair<double,int>,vector<pair<double,int>>> pq;
    for(int i=0;i<n;i++)
        pq.push({(double)items[i][0]/(double)items[i][1],items[i][1]});

    while(W>0){
        auto top=pq.top();
        pq.pop();
        if(W>top.second){
            ans=ans+top.first*top.second;
            W=W-top.second;
        }else{
            ans=ans+top.first*W;
            break;
        }
    }

    cout<<"The maximum amount that can be obtained is: "<<ans<<endl;
}

// Time complexity: O(nlog(n))
// Space complexity: O(n)