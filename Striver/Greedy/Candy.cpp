// A line of N kids is standing there. The rating values listed in the integer array ratings are assigned to each kid.
// These kids are receiving candy, according to the following criteria:
// There must be at least one candy for every child.
// Kids whose scores are higher than their neighbours receive more candies than their neighbours.
// Return the minimum number of candies needed to distribute among children.

#include<iostream>
#include<vector>
using namespace std;

//Time complexity: O(3*n)
//Space complexity: O(2*n)
void traverseTwice(vector<int>& vec){
    int n=vec.size();
    vector<int> right(n,1),left(n,1);
    for(int i=1;i<n;i++){
        if(vec[i-1]<vec[i])
            left[i]=left[i-1]+1;
    }
    for(int i=n-2;i>=0;i--){
        if(vec[i]>vec[i+1])
            right[i]=right[i+1]+1;
    }

    int ans=0;
    for(int i=0;i<n;i++)
        ans=ans+max(left[i],right[i]);
    
    cout<<"The minimum number of candies required to satisfy all children is: "<<ans<<endl;
}

//Time complexity: O(2*n)
//Space complexity: O(n)
void traverseTwiceOpt(vector<int>& vec){
    int n=vec.size();
    vector<int> left(n,1);
    for(int i=1;i<n;i++){
        if(vec[i-1]<vec[i])
            left[i]=left[i-1]+1;
    }
    int cur=1,ans=1;
    for(int i=n-2;i>=0;i--){
        if(vec[i]>vec[i+1]){
            cur++;
        }else
            cur=1;
        ans=ans+max(left[i],cur);   
    }
    
    cout<<"The minimum number of candies required to satisfy all children is: "<<ans<<endl;
}

//Slope method
//Time complexity: O(n)
//Space complexity: O(1)
void traverseOnce(vector<int>& vec){
    int n=vec.size(),sum=1,i=1;
    while(i<n){
        if(vec[i]==vec[i-1]){
            sum++;
            i++;
            continue;
        }
        int peak=1;
        while(i<n && vec[i]>vec[i-1]){
            peak++;
            sum=sum+peak;
            i++;
        }
        int down=1;
        while(i<n && vec[i]<vec[i-1]){
            sum=sum+down;   
            down++;
            i++;
        }
        if(down>peak)
            sum=sum+(down-peak);
    }

    cout<<"The total number of candies required to satisfy all children is: "<<sum<<endl;
}

int main(){
    int n;
    cout<<"Enter the number of students: ";
    cin>>n;
    cout<<"Enter the scores of each child: ";
    vector<int> score(n);
    for(int i=0;i<n;i++)
        cin>>score[i];
    traverseOnce(score);
    traverseTwice(score);
    traverseTwiceOpt(score);
}