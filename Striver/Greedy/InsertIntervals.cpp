// Given a 2D array Intervals, where Intervals[i] = [start[i], end[i]] represents the start and end of the ith interval, the array represents non-overlapping intervals sorted in ascending order by start[i]. 
// Given another array newInterval, where newInterval = [start, end] represents the start and end of another interval, insert newInterval into Intervals such that Intervals remain non-overlapping and sorted in ascending order by start[i].
// Return Intervals after the insertion of newInterval.

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    int n,i=0;
    cout<<"Enter the number of intervals: ";
    cin>>n;
    vector<vector<int>> intervals(n,vector<int>(2));
    cout<<"Enter the intervals:\n";
    for(int i=0;i<n;i++)
        cin>>intervals[i][0]>>intervals[i][1];
    
    cout<<"Enter the start and end time: ";
    int start,end;
    cin>>start>>end;

    sort(intervals.begin(),intervals.end(),[](auto a,auto b){
        return a[0]<b[0];
    });

    vector<vector<int>> ans;
    while(i<n && intervals[i][1]<start){
        ans.push_back(intervals[i]);
        i++;
    }
    while(i<n && intervals[i][0]<=end){
        start = min(start, intervals[i][0]);
        end = max(end, intervals[i][1]);
        i++;
    }
    ans.push_back({start,end});
    while(i<n){
        ans.push_back(intervals[i]);
        i++;
    }

    cout<<"The resultant intervals are:\n";
    for(int i=0;i<ans.size();i++)
        cout<<ans[i][0]<<" "<<ans[i][1]<<endl;

    return 0;
}

//Time compelxity: O(nlog(n)+n)
//Space complexity: O(n)