//Divide two integers without using division operator return the quotient

#include<iostream>
#include<limits.h>
using namespace std;

int divide(int dividend,int divisor){
    if(dividend==divisor)   
        return 1;
    
    bool sign=(true && !(dividend>=0 && divisor<0) && !(dividend<0 && divisor>=0));
    int n=abs(dividend),d=abs(divisor),ans=0;

    while(n>=d){
        int cnt=0;
        while(n>=(d<<(cnt+1)))
            cnt++;

        ans=ans+(1<<cnt);
        n=n-(d<<cnt);
    }

    if(ans>INT_MAX)
        return (sign)? INT_MAX:INT_MIN;
    return (sign)? ans:(ans*-1);
}

int main(){
    int dividend,divisor;
    cout<<"Enter the dividend and divisor: ";
    cin>>dividend>>divisor;
    cout<<"The quotient is: "<<divide(dividend,divisor)<<endl;
}

//Time complexity : O(log(n)^2)