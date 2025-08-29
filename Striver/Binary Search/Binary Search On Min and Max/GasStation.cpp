// Given a sorted array arr of size n, containing integer positions of n gas stations on the X-axis, and an integer k, place k new gas stations on the X-axis.
// The new gas stations can be placed anywhere on the non-negative side of the X-axis, including non-integer positions.
// Let dist be the maximum distance between adjacent gas stations after adding the k new gas stations.
// Find the minimum value of dist.

#include<iostream>
#include<vector>
#include<algorithm>
#include<iomanip>
#include<queue>
#include<cmath>
using namespace std;

// Time complexity: O(k*n)
// Space complexity: O(n)
void bruteForce(vector<long double>& vec,int k){
    int n=vec.size();
    vector<int> betn(n-1,0);
    for(int i=0;i<k;i++){
        int maxVal=-1,maxIdx=-1;
        for(int i=0;i<n-1;i++){
            long double diff=vec[i+1]-vec[i];
            long double len=diff/(betn[i]+1);
            if(maxVal<len){
                maxVal=len;
                maxIdx=i;
            }
        }
        betn[maxIdx]++;
    }

    long double maxAns=-1;
    for(int i=0;i<n-1;i++){
        long double cur=(vec[i+1]-vec[i])/(betn[i]+1);
        if(maxAns<cur)
            maxAns=cur;
    }
    cout<<"The minimized distance between gas stations is: "<<fixed << setprecision(6) << maxAns<<endl;
}

// Time complexity: O((n+k)log(n))
// Space complexity: O(n)
void imptovedBruteForce(vector<long double>& vec,int k){
    int n=vec.size();
    vector<int> betn(n-1,0);
    priority_queue<pair<long double,int>,vector<pair<long double,int>>> pq;
    for(int i=0;i<n-1;i++)
        pq.push({vec[i+1]-vec[i],i});
    for(int i=0;i<k;i++){
        auto top=pq.top();
        pq.pop();
        betn[top.second]++;
        pq.push({(vec[top.second+1]-vec[top.second])/(betn[top.second]+1),top.second});
    }
    cout<<"The minimized distance between gas stations is: "<<fixed << setprecision(6) << pq.top().first<<endl;
}

// Time complexity: O(nlog(n))
// Space complexity: O(1)
void binarySearch(vector<long double>& vec,int k){
    int n=vec.size();
    long double low=0,high=0;
    for(int i=0;i<n-1;i++){
        if(high<vec[i+1]-vec[i])
            high=vec[i+1]-vec[i];
    }
    
    while(high-low>1e-6){
        long double mid=low+(high-low)/2;
        int cnt=0;
        for(int i=0;i<n-1;i++){
            cnt += (int)(ceil((vec[i+1] - vec[i]) / mid)) - 1;
        }
        if(cnt>k)
            low=mid;
        else
            high=mid;
    }
    cout<<"The minimized distance between gas stations is: "<<fixed << setprecision(6) <<high<<endl;
}

int main(){
    int n,k;
    cout<<"Enter the number of gas stations already present and number to be added: ";
    cin>>n>>k;
    cout<<"Enter the positions of the gas stations: ";
    vector<long double> vec(n);
    for(int i=0;i<n;i++)
        cin>>vec[i];

    binarySearch(vec,k);
}