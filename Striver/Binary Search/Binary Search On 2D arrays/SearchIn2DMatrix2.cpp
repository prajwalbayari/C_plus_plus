// Given a 2D array matrix where each row is sorted in ascending order from left to right and each column is sorted in ascending order from top to bottom, write an efficient algorithm to search for a specific integer target in the matrix.

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
    cout<<"Enter the elements of the matrix: ";
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++)
            cin>>mat[i][j];
    }
    int ele;
    cout<<"Enter the element to be searched: ";
    cin>>ele;

    int row=0,col=n-1;
    while(row<m && col>=0){
        if(mat[row][col]==ele){
            cout<<"Element found at row "<<row<<" col "<<col<<endl;
            return 0;
        }else if(mat[row][col]<ele){
            row++;
        }else{
            col--;
        }
    }
    cout<<"Element not found\n";
    return 0;
}

// Time complexity: O(m+n)
// Space complexity: O(1)