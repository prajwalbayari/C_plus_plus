// Given one meeting room and N meetings represented by two arrays, start and end, where start[i] represents
// the start time of the ith meeting and end[i] represents the end time of the ith meeting, determine the
// maximum number of meetings that can be accommodated in the meeting room if only one meeting can be held
// at a time.

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    int n;
    cout<<"Enter the number of meetings: ";
    cin>>n;
    cout<<"Enter the start time and end time of each meeting respectively:\n";
    vector<vector<int>> meetings(n,vector<int>(3));
    for(int i=0;i<n;i++){
        cin>>meetings[i][0]>>meetings[i][1];
        meetings[i][2]=i+1;
    }

    sort(meetings.begin(),meetings.end(),[](auto a,auto b){
        return a[1]<b[1];
    });

    vector<int> order;
    int curTime=-1;
    for(int i=0;i<n;i++){
        if(meetings[i][0]>curTime){
            order.push_back(meetings[i][2]);
            curTime=meetings[i][1];
        }
    }

    cout<<"The total number of meetings that can be held in a single room is: "<<order.size();
    return 0;
}

// Time complexity: O(nlogn+2*n)
// Space complexity: O(3*n+n)