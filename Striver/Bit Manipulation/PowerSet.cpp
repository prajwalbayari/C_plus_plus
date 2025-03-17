//Given an array print all its subsets

#include<iostream>
#include<vector>
using namespace std;

int main(){
    int n;
    cout<<"Enter the size of the array: ";
    cin>>n;
    vector<int> vec(n);
    cout<<"Enter the array elements: ";
    for(int i=0;i<n;i++)
        cin>>vec[i];

    cout<<"The subsets are:\n";
    for(int i=0;i<(1<<n);i++){
        int j=i,cnt=0;
        while(j>=(1<<cnt)){
            if(j&(1<<cnt))
                cout<<vec[cnt]<<" ";
            cnt++;
        }
        cout<<endl;
    }

    return 0;
}

//Time complexity :O(2^n*(n))