// Given a non-empty grid mat consisting of only 0s and 1s, where all the rows are sorted in ascending order, find the index of the row with the maximum number of ones.
// If two rows have the same number of ones, consider the one with a smaller index. If no 1 exists in the matrix, return -1.

#include<iostream>
#include<vector>
#include<cmath>
#include<iomanip>
using namespace std;

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
    
    int idx=-1,maxCnt=0;
    for(int i=0;i<m;i++){
        int low=0,high=n-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(mat[i][mid]==1){
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
        if(n-low>maxCnt){
            maxCnt=n-low;
            idx=i;
        }
    }
    if(idx==-1)
        cout<<"No row has 1\n";
    else
        cout<<"Row with maximum number of one's is: "<<idx<<endl;
    return 0;
}

// Time complexity: O(m*log(n))
// Space complexity: O(1)