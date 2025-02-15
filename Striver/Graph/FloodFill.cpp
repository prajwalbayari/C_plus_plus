#include<iostream>
#include<vector>

using namespace std;

void floodFill(vector<vector<int>>& ans,int rs,int cs,int newColor,int oldColor){
    if(rs<0 || rs>=ans.size() || cs<0 || cs>=ans[0].size() || ans[rs][cs]!=oldColor)
        return; 
    
    ans[rs][cs]=newColor;
    floodFill(ans,rs-1,cs,newColor,oldColor);
    floodFill(ans,rs+1,cs,newColor,oldColor);
    floodFill(ans,rs,cs-1,newColor,oldColor);
    floodFill(ans,rs,cs+1,newColor,oldColor);
}

int main(){
    int m,n,rs,cs,newColor;
    cout<<"Enter the size of the matrix: ";
    cin>>m>>n;
    vector<vector<int>> image(m,vector<int>(n));

    cout<<"Enter the image matrix:\n";
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin>>image[i][j];
        }
    }

    cout<<"Enter the starting index: ";
    cin>>rs>>cs;
    cout<<"Enter the new color: ";
    cin>>newColor;

    vector<vector<int>> ans=image;

    floodFill(ans,rs,cs,newColor,ans[rs][cs]);

    cout<<"The image after replacing the color is:\n";
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;

    return 0;
}

//Time complexity O(x*4) where x is the number of nodes (x=n*m)