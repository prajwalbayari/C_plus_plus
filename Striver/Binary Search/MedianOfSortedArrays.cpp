// Given two sorted arrays arr1 and arr2 of size m and n respectively, return the median of the two sorted arrays.
// The median is defined as the middle value of a sorted list of numbers. In case the length of the list is even, the median is the average of the two middle elements.

#include<iostream>
#include<vector>
#include<cmath>
#include<iomanip>
using namespace std;

// Time complexity: O(m+n)
// Space complexity: O(1)
void bruteForce(vector<int>& vec1,vector<int>& vec2){
    int m=vec1.size(),n=vec2.size();
    int i=0,j=0,cnt=0;
    int idx1=(m+n)/2,ele1=-1,ele2=-1,idx2=idx1-1;
    while(i<m && j<n){
        if(vec1[i]<vec2[j]){
            if(idx1==cnt) ele1=vec1[i];
            if(idx2==cnt) ele2=vec1[i];
            i++;
        }
        else{
            if(idx1==cnt) ele1=vec2[j];
            if(idx2==cnt) ele2=vec2[j];
            j++;
        }
        cnt++;
    }
    while(i<m){
        if(idx1==cnt) ele1=vec1[i];
        if(idx2==cnt) ele2=vec1[i];
        i++,cnt++;
    }
    while(j<n){
        if(idx1==cnt) ele1=vec2[j];
        if(idx2==cnt) ele2=vec2[j];
        j++,cnt++;
    }
    float ans=0;
    if((m+n)%2)
        ans=ele1;
    else
        ans=(float)(ele1+ele2)/2.0;
    cout<<"The median of the 2 sorted arrays is: "<<fixed<<setprecision(3)<<ans<<endl;
}

// Time complexity: O(log(min(m,n)))
// Space complexity: O(1)
void binarySearch(vector<int>& vec1,vector<int>& vec2){
    int m=vec1.size(),n=vec2.size();
    if(m>n){
        binarySearch(vec2,vec1);
        return;
    }
    int low=0,high=m;
    int left=(m+n+1)/2;
    while(low<=high){
        int mid1=(low+high)>>1;
        int mid2=left-mid1;
        int l1=INT_MIN,l2=INT_MIN,r1=INT_MAX,r2=INT_MAX;
        if(mid1<m) r1=vec1[mid1];
        if(mid2<n) r2=vec2[mid2];
        if(mid1>0) l1=vec1[mid1-1];
        if(mid2>0) l2=vec2[mid2-1];
        if(l1<=r2 && l2<=r1){
            double ans=0;
            if((m+n)%2){
                ans=max(l1,l2);
            }else{
                ans=(double)(max(l1,l2)+min(r1,r2))/2.0;
            }
            cout<<"The median of the two sorted arrays is: "<< fixed << setprecision(3) << ans << endl;
            return;
        }else if(l1>r2)
            high=mid1-1;
        else
            low=mid1+1;
    }
    return;
}

int main(){
    int m,n;
    cout<<"Enter the size of 2 arrays: ";
    cin>>m>>n;
    vector<int> vec1(m),vec2(n);
    cout<<"Enter numbers of the first array: ";
    for(int i=0;i<m;i++)
        cin>>vec1[i];
    cout<<"Enter numbers of the second array: ";
    for(int i=0;i<n;i++)
        cin>>vec2[i];
    
    bruteForce(vec1,vec2);
}