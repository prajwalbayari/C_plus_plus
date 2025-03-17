//Given an array with size n where all elements except one numnber are repeated thrice
//print the number that is unique

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//Solution-2
void singleNumber(vector<int> vec){
    //This solution takes O(nlog(n)) which is better than bit manipualtion in most cases
    int n=vec.size();
    sort(vec.begin(),vec.end());
    for(int i=1;i<n;i+=3){
        if(vec[i]!=vec[i-1]){
            cout<<"The single number is: "<<vec[i-1]<<endl;
            return;
        }
    }
    cout<<"The single number is: "<<vec[vec.size()-1]<<endl;
    return;
}

//Solution-3
//Maintain 2 buckets ones and twos and follow the following rules
//i)If the current number is not in bucket twos it goes to bucket ones
//ii)If the current number is in bucket ones then it goes to bucket twos (remove from bucket ones)
//iii)If the current number is in bucket twos then discard it (remove from bucket twos)

//Time complexity: O(n)
void bucketsMethod(vector<int> arr){
    int ones=0,twos=0;
    for(int i=0;i<arr.size();i++){
        ones=(ones^arr[i])&(~twos);
        twos=(twos^arr[i])&(~ones);
    }

    cout<<"The single number is: "<<ones<<endl;
}

int main(){
    int n,ans=0;
    cout<<"Enter the size of the array: ";
    cin>>n;
    vector<int> bits(32,0);
    cout<<"Enter the array elements\n";
    for(int i=0;i<n;i++){       //Solution 1
        int num,cnt=0;
        cin>>num;
        while(num>(1<<cnt)){
            if(num&(1<<cnt))    //Calclulate the frequency of bits
                bits[cnt]++;
            cnt++;
        }
    }

    //Set the bits which are not a multiple of 3
    for(int i=0;i<32;i++)
        ans=ans|((bits[i]%3)<<i);
    
    cout<<"The unique number in the array is: "<<ans<<endl;
    bucketsMethod({1,1,1,2,2,2,3,4,4,4,5,5,5,6,6,6});
}

//Time complexity: O(n*32)