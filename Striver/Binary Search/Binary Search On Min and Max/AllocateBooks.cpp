// Given an array nums of n integers, where nums[i] represents the number of pages in the i-th book, and an integer m representing the number of students, allocate all the books to the students so that each student gets at least one book, each book is allocated to only one student, and the allocation is contiguous.
// Allocate the books to m students in such a way that the maximum number of pages assigned to a student is minimized. If the allocation of books is not possible, return -1

#include<vector>
#include<iostream>
#include<stdio.h>
#include<algorithm>
using namespace std;

bool isPossible(vector<int>& book,int pages,int st){
    int cnt=1,sum=0;
    for(int b:book){
        if(sum+b>pages){
            cnt++;
            sum=b;
        }else{
            sum+=b;
        }
        if(cnt>st)
            return false;
    }
    return true;
}

int main(){
    int n,s,low=0,high=0;
    cout<<"Enter the number of books and number of students: ";
    cin>>n>>s;
    if(s>n){
        cout<<"Not possible to allocate book to all students\n";
        return 0;
    }
    vector<int> book(n);
    cout<<"Enter the number of pages of each book: ";
    for(int i=0;i<n;i++){
        cin>>book[i];
        low=max(low,book[i]);
        high+=book[i];
    }

    while(low<=high){
        int mid=low+(high-low)/2;
        if(isPossible(book,mid,s)){
            high=mid-1;
        }else{
            low=mid+1;
        }
    }
    cout<<"The maximum number of pages a student gets after minimal allocation is: "<<low<<endl;
    return 0;
}

// Time complexity: O(n*log(k)) where k is difference between highest number of pages in a book and sum of pages
// Space complexity: O(1)