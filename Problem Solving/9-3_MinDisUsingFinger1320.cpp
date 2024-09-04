#include<bits/stdc++.h>
using namespace std;

// 1320. Minimum Distance to Type a Word Using Two Fingers (Leetcode Question)

// Recursive Solution
class Solution {
public:
    unordered_map<int,pair<int,int>> m;
    int value(int p1,int p2){
        int x1=m[p1].first;
        int y1=m[p1].second;
        int x2=m[p2].first;
        int y2=m[p2].second;
        return abs(x1-x2)+abs(y1-y2);
    }
    int fun(string&word,int ind,int pr1=-1,int pr2=-1){
        if(ind>=word.size()) return 0;
        int ans=INT_MAX;
        int val1=0;
        int val2=0;
        if(pr1!=-1) val1=value(pr1,word[ind]-'A');
        if(pr2!=-1) val2=value(pr2,word[ind]-'A');
        ans=min(ans,val1+fun(word,ind+1,word[ind]-'A',pr2));
        ans=min(ans,val2+fun(word,ind+1,pr1,word[ind]-'A'));
        return ans;
    }
    int minimumDistance(string word) {
        int k=0;
        for(int i=0;i<5;i++){
            for(int j=0;j<6&&k<26;j++){
                m[k++]={i,j};
            }
        }
        return fun(word,0);
    }
};



// Recursive + Memoization
class Solution {
public:
    unordered_map<int,pair<int,int>> m;
    vector<vector<vector<int>>> dp;
    int value(int p1,int p2){
        int x1=m[p1].first;
        int y1=m[p1].second;
        int x2=m[p2].first;
        int y2=m[p2].second;
        return abs(x1-x2)+abs(y1-y2);
    }
    int fun(string&word,int ind,int pr1=-1,int pr2=-1){
        if(ind>=word.size()) return 0;
        if(dp[ind][pr1+1][pr2+1]!=-1) return dp[ind][pr1+1][pr2+1];
        int ans=INT_MAX;
        int val1=0;
        int val2=0;
        if(pr1!=-1) val1=value(pr1,word[ind]-'A');
        if(pr2!=-1) val2=value(pr2,word[ind]-'A');
        ans=min(ans,val1+fun(word,ind+1,word[ind]-'A',pr2));
        ans=min(ans,val2+fun(word,ind+1,pr1,word[ind]-'A'));
        return dp[ind][pr1+1][pr2+1]=ans;
    }
    int minimumDistance(string word) {
        int k=0;
        for(int i=0;i<5;i++){
            for(int j=0;j<6&&k<26;j++){
                m[k++]={i,j};
            }
        }
        dp.resize(word.size(),vector<vector<int>>(27,vector<int>(27,-1)));
        return fun(word,0);
    }
};