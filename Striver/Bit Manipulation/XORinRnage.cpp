//Given an ingteger n give XOR of numbers from 1 to n

#include<iostream>
using namespace std;

int XOR(int n){
    if(n%4==0)
        return n;
    else if(n%4==1)
        return 1;
    else if(n%4==2)
        return n+1;
    return 0;
}

int XORinRange(int l,int r){
    return XOR(l-1)^XOR(r);
}

int main(){
    int l,r;
    cout<<"Enter the range: ";
    cin>>l>>r;
    cout<<"The result of XOR operation from "<<1<<" to "<<r<<" is: "<<XORinRange(l,r)<<endl;
    return 0;
}