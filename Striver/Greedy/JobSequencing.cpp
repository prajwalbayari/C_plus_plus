// Given an 2D array Jobs of size Nx3, where Jobs[i][0] represents JobID , Jobs[i][1] represents Deadline , 
// Jobs[i][2] represents Profit associated with that job. Each Job takes 1 unit of time to complete and only 
// one job can be scheduled at a time.
// The profit associated with a job is earned only if it is completed by its deadline. Find the number of jobs 
// and maximum profit.

#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
using namespace std;

int main(){
    int n;
    cout<<"Enter the number of jobs: ";
    cin>>n;
    vector<vector<int>> vec(n,vector<int>(3));
    cout<<"Enter the Job ID, deadline and profit of "<<n<<" jobs;\n";
    for(int i=0;i<n;i++)
        cin>>vec[i][0]>>vec[i][1]>>vec[i][2];

    sort(vec.begin(),vec.end(),[](auto a,auto b){
        return a[2]>b[2];
    });

    int totalProfit=0,cnt=0,maxDeadline=-1;
    // for(int i=0;i<n;i++)
    //     maxDeadline=max(maxDeadline,vec[i][1]);
    unordered_map<int,int> mp;
    mp[maxDeadline+1]=-1;
    for(int i=0;i<n;i++){
        for(int j=vec[i][1];j>=0;j--){
            if(mp.find(j)==mp.end()){
                cnt++;
                mp[j]=vec[i][0];
                totalProfit+=vec[i][2];
                break;
            }
        }
    }

    cout<<"The maximum number of works that can be completed is: "<<cnt<<" and a profit of "<<totalProfit<<" can be gained.\n";
    return 0;
}

// Time complexity: O(nlogn+n*maxDeadline)
// Space complexity: O(maxDeadline)