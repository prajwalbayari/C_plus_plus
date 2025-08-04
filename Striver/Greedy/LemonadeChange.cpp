// Each lemonade at a booth sells for $5. Consumers are lining up to place individual orders, following 
// the billing order. Every consumer will purchase a single lemonade and may pay with a $5, $10, or $20 bill. 
// Each customer must receive the appropriate change so that the net transaction is $5. Initially, there is no 
// change available.
// Determine if it is possible to provide the correct change to every customer. Return true if the correct 
// change can be given to every customer, and false otherwise.
// Given an integer array bills, where bills[i] is the bill the ith customer pays, return true if the correct 
// change can be given to every customer, and false otherwise.

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    int n;
    cout<<"Enter the number of customers: ";
    cin>>n;
    vector<int> vec(n);
    cout<<"Enter the denominations: ";
    for(int i=0;i<n;i++)
        cin>>vec[i];

    int five=0,ten=0,twenty=0;
    for(int i=0;i<n;i++){
        if(vec[i]==5)
            five++;
        else if(vec[i]==10){
            if(five==0){
                cout<<"Not possible!\n";
                return 0;
            }
            five--,ten++;
        }else{
            if(five==0 || (ten==0 && five<3)){
                cout<<"Not possible!\n";
                return 0;
            }else if(ten==0 && five>=3){
                five-=3;
                twenty++;
                continue;
            }
            five--,ten--,twenty++;
        }
    }
    cout<<"Possible\n";
    return 0;
}

// Time complexity : O(n)
// Space complexity: O(1)