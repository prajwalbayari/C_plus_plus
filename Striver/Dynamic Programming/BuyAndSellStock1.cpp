// We are given an array Arr[] of length n. It represents the price of a stock on ‘n’ days. The following guidelines need to be followed:

// We can buy and sell a stock only once.
// We can buy and sell the stock on any day but to sell the stock, we need to first buy it on the same or any previous day.
// We need to tell the maximum profit one can get by buying and selling this stock.

#include<iostream>
#include<vector>
using namespace std;

int main(){
    int n;
    cout<<"Enter the number of days: ";
    cin>>n;
    cout<<"Enter the stock values: ";
    vector<int> stock(n);
    for(int i=0;i<n;i++)
        cin>>stock[i];
    int mini=stock[0],cost=0,profit=-1;
    for(int i=1;i<n;i++){
        cost=stock[i]-mini;
        profit=max(cost,profit);
        mini=min(stock[i],mini);
    }
    cout<<"The maximum profit is: "<<profit<<endl;
}