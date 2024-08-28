/*
Find the maximum length substring containing at most 2 distinct characters

Example -

S = “eceba”

Ans = 3

Explanation: - “ece” has at most 2 distinct character 
e and c and is the largest substring with the fulfilled conditions
*/

#include<bits/stdc++.h>
using namespace std;
int MaxFrequency(string&s,int k){
    int ans=INT_MIN;
    int i=0;
    unordered_map<char,int> m;
    for(int j=0;j<s.size();j++){
        m[s[j]]++;
        while(m.size()>k){
            m[s[i]]--;
            if(m[s[i]]==0) m.erase(s[i]);
            i++;
        }
        ans=max(j-i+1,ans);
    }
    return ans;
}
int main(){
    string s;
    cin>>s;
    int k=2;  //as per question
    cout<<MaxFrequency(s,k)<<endl;
}