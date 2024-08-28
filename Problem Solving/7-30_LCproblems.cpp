#include<bits/stdc++.h>
using namespace std;

// Fruit Into Baskets (904)
class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int,int> m;
        int i=0;
        int ans=INT_MIN;
        for(int j=0;j<fruits.size();j++){
            m[fruits[j]]++;
            while(m.size()>2){
                m[fruits[i]]--;
                if(m[fruits[i]]==0) m.erase(fruits[i]);
                i++;
            }
            ans=max(ans,j-i+1);
        }   
        return ans;
    }
};

// Find Valid Matrix Given Row and Column Sums (1605)
class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
        int n=rowSum.size();
        int m=colSum.size();
        vector<vector<int>> ans(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                ans[i][j]=min(rowSum[i],colSum[j]);
                rowSum[i]-=ans[i][j];
                colSum[j]-=ans[i][j];   
            }
        }
        return ans;
    }
};