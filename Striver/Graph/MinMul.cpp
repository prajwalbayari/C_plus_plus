//Given two numbers start and end an array of elements Perform set of operations to reach 
//end from the start in each operation you can multiply any number in the array with start
//and perform mod operation with 100000 the result will be new start return minimum number
//of operations needed to reach goal if it is possible

#include<bits/stdc++.h>
using namespace std;

int MinimumMultiplication(vector<int>& arr,int start,int goal){
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    set<int> st;
    pq.push({0,start});
    st.insert(start);
    int n=arr.size();

    while(!pq.empty()){
        int node=pq.top().second,cnt=pq.top().first;
        pq.pop();

        for(int i=0;i<n;i++){
            int x=(node*arr[i])%100000;
            if(x==goal)
                return cnt+1;
            if(st.find(x)==st.end()){
                st.insert(x);
                pq.push({cnt+1,x});
            }
        }
    }

    return -1;
}

int main(){
    int n,start,goal;
    cout<<"Enter the size of the array: ";
    cin>>n;
    cout<<"Enter the array elements: ";
    vector<int> arr(n);
    for(int i=0;i<n;i++)
        cin>>arr[i];
    
    cout<<"Enter the start and goal numbers: ";
    cin>>start>>goal;

    cout<<"The minimum number of operations needed to reach destination is: "<<MinimumMultiplication(arr,start,goal)<<endl;

    return 0;
}