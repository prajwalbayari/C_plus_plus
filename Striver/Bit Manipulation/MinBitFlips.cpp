//Find the minimum number of bits that need to be flipped in order to change the start number to goal number

#include<iostream>
using namespace std;

int main(){
    int start,goal;
    cout<<"Enter the start and goal numbers: ";
    cin>>start>>goal;

    cout<<"The number of bits that need to be flipped are: "<<__builtin_popcount(start^goal);
}