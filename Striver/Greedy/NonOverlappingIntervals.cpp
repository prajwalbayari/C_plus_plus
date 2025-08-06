// Given an array of N intervals in the form of (start[i], end[i]), where start[i] is the starting point of the interval and end[i] is the ending point of the interval, return the minimum number of intervals that need to be removed to make the remaining intervals non-overlapping.

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    int n;
    cout<<"Enter the number of intervals: ";
    cin>>n;
    cout<<"Enter the start and end times:\n";
    vector<vector<int>> intervals(n,vector<int>(2));
    for(int i=0;i<n;i++)
        cin>>intervals[i][0]>>intervals[i][1];
    
    sort(intervals.begin(),intervals.end(),[](auto a,auto b){
        return a[1]<b[1];
    });

    int cnt=1,endTime=intervals[0][1];
    for(int i=1;i<n;i++){
        if(intervals[i][0]>=endTime){
            cnt++;
            endTime=intervals[i][1];
        }
    }
    cout<<"The minimum number of intervals that need to be removed to make the remaining intervals non overlapping is: "<<n-cnt<<endl;
}

// Time comolexity: O(nlog(n)+n)
// Space complexity: O(1)