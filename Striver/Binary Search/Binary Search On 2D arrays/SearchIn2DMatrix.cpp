// Given a 2-D array mat where the elements of each row are sorted in non-decreasing order, and the first element of a row is greater than the last element of the previous row (if it exists), and an integer target, determine if the target exists in the given mat or not

#include<iostream>
#include<vector>
#include<cmath>
#include<iomanip>
using namespace std;

// Time complexity: O(log(m*n))
// Space complexity: O(1)
void optimized(vector<vector<int>>& mat,int ele){
    int m=mat.size(),n=mat[0].size();
    int low=0,high=m*n-1;
    while(low<=high){
        int mid=low+(high-low)/2;
        if(mat[mid/n][mid%n]==ele){
            cout<<"Element found at row "<<mid/n<<" and column "<<mid%n<<endl;
            return;
        }else if(mat[mid/n][mid%n]<ele){
            low=mid+1;
        }else{
            high=mid-1;
        }
    }
    cout<<"Element not found\n";
}

// Time complexity: O(m+log(n))
// Space complexity: O(1)
void improvedBruteForce(vector<vector<int>>& mat,int ele){
    int m=mat.size(),n=mat[0].size();
    for(int i=0;i<m;i++){
        if(mat[i][0]<=ele && mat[i][n-1]>=ele){
            int low=0,high=n-1;
            while(low<=high){
                int mid=low+(high-low)/2;
                if(mat[i][mid]==ele){
                    cout<<"Element found at row "<<i<<" and column "<<mid<<endl;
                    return;
                }else if(mat[i][mid]<ele){
                    low=mid+1;
                }else{
                    high=mid-1;
                }
            }
            break;
        }
    }
    cout<<"Element not found!\n";
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
    int ele;
    cout<<"Enter the element to be searched: ";
    cin>>ele;
    optimized(mat,ele);
    return 0;
}