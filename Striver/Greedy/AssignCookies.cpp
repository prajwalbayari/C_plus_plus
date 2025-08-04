// Consider a scenario where a teacher wants to distribute cookies to students, with each student receiving at most one cookie.
// Given two arrays, Student and Cookie, the ith value in the Student array describes the minimum size of cookie
// that the ith student can be assigned. The jth value in the Cookie array represents the size of the jth cookie.
// If Cookie[j] >= Student[i], the jth cookie can be assigned to the ith student. Maximize the number of 
// students assigned with cookies and output the maximum number.

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    int n,m;
    cout<<"Enter the number of children and cookies respectively: ";
    cin>>n>>m;
    vector<int> child(n),cookie(m);
    cout<<"Enter the greediness of each child: ";
    for(int i=0;i<n;i++)
        cin>>child[i];
    cout<<"Enter the value of cookie: ";
    for(int i=0;i<n;i++)
        cin>>cookie[i];

    sort(child.begin(),child.end());
    sort(cookie.begin(),cookie.end());

    int i=0,j=0,ans=0;

    while(i<n && j<m){
        if(child[i]<=cookie[j])
            i++,j++,ans++;
        else
            j++;
    }
    cout<<"The maximum number of children that can be satisfied is: "<<ans<<endl;

    return 0;
}

// Time complexity: O(nlog(n)+mog(m)+m)
// Space complexity: O(1)