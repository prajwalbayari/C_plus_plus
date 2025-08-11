// Given a positive integer n. Find and return its square root. If n is not a perfect square, then return the 
// floor value of sqrt(n).

#include<iostream>  
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    int n;
    cout<<"Enter the number: ";
    cin>>n;

    int high=n,low=1,ans=0;
    while(low<=high){
        int mid=low+(high-low)/2;
        if(mid*mid<=n){
            ans=mid;
            low=mid+1;
        }else
            high=mid-1;
    }
    cout<<"Square root of "<<n<<" is "<<ans<<endl;
}

// Time complexity: O(log(n))
// Space complexity: O(1)