#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool check(vector<string> &matrix,int row,int col){
        int i=row;
        int j=col;
        while(j>=0&&i>=0) {
            if(matrix[i][j]=='Q') return false;
            i--;j--;
        }
        i=row;
        j=col;
        while(i>=0){
            if(matrix[i][j]=='Q') return false;
            i--;
        }
        i=row;
        j=col;
        while(i>=0&&j<matrix.size()){
            if(matrix[i][j]=='Q') return false;
            i--;j++;
        }
        return true;
    }
    void fun(vector<vector<string>> &ans,vector<string> &matrix,int row){
        if(row>=matrix.size()){
            ans.push_back(matrix);
            return;
        }
        for(int i=0;i<matrix.size();i++){
            if(check(matrix,row,i)){
                matrix[row][i]='Q';
                fun(ans,matrix,row+1);
                matrix[row][i]='.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        string s;
        for(int i=0;i<n;i++) s.push_back('.');
        vector<string> matrix(n,s);
        vector<vector<string>> ans;
        fun(ans,matrix,0);
        return ans;  
    }
};