#include<bits/stdc++.h>
using namespace std;
// vector<vector<int>> dp;
// int fun(char mat[][100],int n,int m,int i,int j,int s){
//     if(i==n-1&&j==m-1) return mat[i][j]=='1';
//     if(i>=n||j>=m||i<0||j<0||mat[i][j]=='X') return INT_MIN;
//     if(dp[i][j]!=-1) return dp[i][j];
//     int a=mat[i][j]=='1';
//     return dp[i][j]=a+max(fun(mat,n,m,i+1,j,s+a),fun(mat,n,m,i,j+1,s+a));
// }
// void pickCherry(char mat[][100],int n,int m){
//     dp.resize(n,vector<int>(m,-1));
//     int ans=(mat,n,m,0,0,0);
//     if(ans==INT_MIN) ans=-1;
//     cout<<ans<<endl;
// }
// int main(){

// }

int fun(int i,int j,vector<vector<int>> mat,int n,int m){
    if(i==n-1&&j==m-1) return mat[i][j]==1;
    if(i>=n||j>=m) return 1e9;
    return (mat[i][j]==1)+min(fun(i+1,j,mat,n,m),fun(i,j+1,mat,n,m));
}
int main(){
    int n;
    int m;
    cin>>n>>m;
    vector<vector<int>> mat(n,vector<int>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++) cin>>mat[i][j];
    }
    cout<<fun(0,0,mat,n,m)<<endl;
}