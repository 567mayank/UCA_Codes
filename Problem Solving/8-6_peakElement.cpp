#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int s=0;
        int e=arr.size()-1;
        int ans=-1;
        while(s<=e){
            int mid=s+(e-s)/2;
            if(mid==0||arr[mid-1]<arr[mid]) {
                ans=mid;
                s=mid+1;
            }
            else e=mid-1;
        }
        return ans;
    }
};