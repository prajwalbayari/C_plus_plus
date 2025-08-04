// A software engineer is tasked with using the shortest job first (SJF) policy to calculate the average 
// waiting time for each process. The shortest job first also known as shortest job next (SJN) scheduling 
// policy selects the waiting process with the least execution time to run next.
// Given an array of n integers representing the burst times of processes, determine the average waiting time 
// for all processes and return the closest whole number that is less than or equal to the result.

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    int n;
    cout<<"Enter the number of jobs: ";
    cin>>n;
    cout<<"Enter the execution period of jobs: ";
    vector<int> vec(n);
    for(int i=0;i<n;i++)
        cin>>vec[i];
    
    sort(vec.begin(),vec.end());
    int wait=0,cur=0;
    for(int i=0;i<n;i++){
        wait+=cur;
        cur+=vec[i];
    }
    cout<<"The average waiting time is: "<<wait/n<<endl;
}

// Time complexity: O(n+nlog(n))
// Space complexity: O(1)