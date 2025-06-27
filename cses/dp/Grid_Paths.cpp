#include<bits/stdc++.h>
using namespace std;

const int mod = 1e9+7;

int gridPaths(vector<vector<char>> &arr,int row,int col,vector<vector<int>> &dp){
    int n = arr.size();
    if(row==0 && col==0){
        return 1;
    }
    if(dp[row][col]!=-1){
        return dp[row][col];
    }

    int moveUp=0,moveLeft=0;
    if(row-1>=0 && arr[row-1][col]!='*'){
        moveUp = gridPaths(arr,row-1,col,dp);
    }
    if(col-1>=0 && arr[row][col-1]!='*'){
        moveLeft = gridPaths(arr,row,col-1,dp);
    }
    return dp[row][col] = (moveLeft+moveUp)%mod;
} 


int main(){
    int n;
    cin>>n;
    vector<vector<char>> grid(n,vector<char>(n));
    vector<vector<int>> dp(n,vector<int>(n,-1));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>grid[i][j];
        }
    }
    if(grid[0][0] =='*' || grid[n-1][n-1]=='*'){
        cout<<0<<endl;
        return 0;
    }
    cout<<gridPaths(grid,n-1,n-1,dp)<<endl;
    return 0;


}
