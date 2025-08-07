// Given the arrival and departure times of all trains reaching a particular railway station, determine the minimum number of platforms required so that no train is kept waiting. Consider all trains arrive and depart on the same day.
// In any particular instance, the same platform cannot be used for both the departure of one train and the arrival of another train, necessitating the use of different platforms in such cases.

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    int n;
    cout<<"Enter the number of trains: ";
    cin>>n;
    cout<<"Enter the arrival and departure time of each train: ";
    vector<vector<int>> intervals(n,vector<int>(2));
    for(int i=0;i<n;i++)
        cin>>intervals[i][0]>>intervals[i][1];

    sort(intervals.begin(),intervals.end(),[](auto a,auto b){
        return a[0]<b[0];
    });

    int i=0,j=0,cnt=0,maxAns=0;
    while(i<n){
        if(intervals[i][0]<=intervals[j][1]){
            cnt++;
            i++;
        }else{
            cnt--;
            j++;
        }
        maxAns=max(maxAns,cnt);
    }

    cout<<"The maximum number of platforms required is: "<<maxAns<<endl;
    return 0;
}

// Time complexity: O(nlog(n)+n)
// Space complexity: O(1)