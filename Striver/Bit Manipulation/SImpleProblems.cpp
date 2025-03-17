#include<iostream>
#include<vector>
using namespace std;

void swap(int& a,int &b){
    a=a^b,b=b^a,a=a^b; //Swap 2 numbers
}

bool isBitSet(int a,int bit){ 
    //Chicks if the given bit is set
    bool left = (a & (1<<bit));  //Using leftshift
    bool right = ((a>>bit) & 1);  //Using rightshift
    return right==0;
}

int setBit(int a,int bit){
    return a|(1<<bit); //Set the bit in given bit position
}

int clearBit(int a,int bit){
    return a&(~(1<<bit)); //Set the bit 1 to 0 in given position
}

int toggleBit(int a,int bit){
    return a^(1<<bit);    //Change the current bit to opposite bit
}

int removeLastSetBit(int a){
    //Figure out the position of the rightmost set bit and change it to 0
    return a&(a-1);
}

bool isPowerOf2(int a){
    //Find if the given number is a power of 2
    return (a&(a-1))==0;
}

//Time complexity: O(log2(a))
int countBits(int a){
    //Count the number of set bits in a number (__builtin_popcount())
    int cnt=0;

    // while(a){
    //     cnt=cnt+(a&1);
    //     a=a>>1;
    // }

    //or

    while(a){
        a=a&(a-1);
        cnt++;
    }
    
    return cnt;
}

int main(){
    cout<<countBits(31);
}