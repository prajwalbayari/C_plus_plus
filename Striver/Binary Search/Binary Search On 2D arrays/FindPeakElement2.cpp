// Given an array arr of integers. A peak element is defined as an element greater than both of its neighbors.
// Formally, if arr[i] is the peak element, arr[i - 1] < arr[i] and arr[i + 1] < arr[i].
// Find the index(0-based) of a peak element in the array. If there are multiple peak numbers, return the index of any peak number.
// Note:As there can be many peak values, 1 is given as output if the returned index is a peak number, otherwise 0.

#include<iostream>
#include<vector>
#include<cmath>
#include<iomanip>
using namespace std;

int findMax(vector<vector<int>>& mat,int col){
    int matEle=mat[0][col],idx=0;
    for(int i=1;i<mat.size();i++){
        if(mat[i][col]>matEle){
            matEle=mat[i][col];
            idx=i;
        }
    }
    return idx;
}

int main(){
    int m,n;
    cout<<"Enter the order of the matrix: ";
    cin>>m>>n;
    vector<vector<int>> mat(m,vector<int>(n));
    cout<<"Enter the elements of the matrix: ";
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++)
            cin>>mat[i][j];
    }
    int low=0,high=n-1;
    while(low<=high){
        int mid=low+(high-low)/2;
        int row=findMax(mat,mid);
        int left=(mid-1>=0)? mat[row][mid-1]:-1;
        int right=(mid+1<n)? mat[row][mid+1]:-1;
        if(mat[row][mid]>left && mat[row][mid]>right){
            cout<<"Peak element found at "<<row<<" "<<mid<<endl;
            break;
        }else if(mat[row][mid]<left){
            high=mid-1;
        }else{
            low=mid+1;
        }
    }
    return 0;
}

// Time complexity: O(m*log(n))
// Space complexity: O(1)