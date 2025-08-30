#include<iostream>
#include<vector>
#include<climits> // for INT_MAX
using namespace std;

int func(vector<vector<int>>& mat,int ele){
    int m=mat.size(), n=mat[0].size(), cnt=0;
    for(int i=0;i<m;i++){
        if(mat[i][0] > ele) continue;
        int low=0, high=n-1;
        while(low <= high){
            int mid = low + (high-low)/2;
            if(mat[i][mid] <= ele){
                low = mid + 1;
            }else{
                high = mid - 1;
            }
        }
        cnt += low;
    }
    return cnt;
}

int main(){
    int m,n;
    cout<<"Enter the order of the matrix: ";
    cin>>m>>n;
    vector<vector<int>> mat(m,vector<int>(n));
    cout<<"Enter the matrix:\n";
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++)
            cin>>mat[i][j];
    }

    int low=INT_MAX, high=-1, req=(m*n)/2;
    for(int i=0;i<m;i++)
        low=min(low, mat[i][0]);
    for(int i=0;i<m;i++)  
        high=max(high, mat[i][n-1]);

    while(low <= high){
        int mid=low+(high-low)/2;
        int lte = func(mat, mid);
        if(lte <= req){
            low = mid + 1;
        }else{
            high = mid - 1;
        }
    }
    cout<<"The median of the matrix is: "<<low<<endl;
    return 0;
}

// Time complexity: O(m log n * log(max-min))
// Space complexity: O(1)
