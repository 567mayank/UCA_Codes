// 73. Set Matrix Zeroes
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        int firstRow=0;
        int firstCol=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]==0){
                    if(i==0) firstRow=1;
                    if(j==0) firstCol=1;
                    matrix[i][0]=0;
                    matrix[0][j]=0;
                }
            }
        }
        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                if(matrix[0][j]==0||matrix[i][0]==0) matrix[i][j]=0;
            }
        }
        if(firstRow) for(int i=0;i<m;i++) matrix[0][i]=0;
        if(firstCol) for(int i=0;i<n;i++) matrix[i][0]=0;
    }
};

#include<iostream>
#include<bits/stdc++.h>
using namespace std;


// You are given a deck of cards (52 cards in 4 suits). Code Operations
// Which is the higher value card?
// Are they the same suit?

class card{
    int spade;
    int club;
    int diamond;
    int heart;
public:
    card(){
        spade=club=diamond=heart=(1<<13)-1;
    }
    bool removal(string symbol,int cardNo){
        cardNo--;
        if(symbol=="heart"){
            if(heart&(1<<cardNo)){
                heart=heart^(1<<cardNo);
            }
            else return false;
        }
        if(symbol=="club"){
            if(!(club&(1<<cardNo))) return false;
            club=club^(1<<cardNo);
        }
        if(symbol=="diamond"){
            if(!(diamond&(1<<cardNo))) return false;
            diamond=diamond^(1<<cardNo);
        }
        if(symbol=="spade"){
            if(!(spade&(1<<cardNo))) return false;
            spade=spade^(1<<cardNo);
        }
        return true;
    }
};
int main(){
    card crd;
    cout<<crd.removal("heart",13)<<endl;
    cout<<crd.removal("heart",13)<<endl;
    cout<<crd.removal("club",13)<<endl;
    cout<<crd.removal("club",13)<<endl;
    cout<<crd.removal("club",13)<<endl;
    return 0;
}

// spade 8->101