#include<stdio.h>
int add(int a,int b) {return a+b;}
int sub(int a,int b) {return a-b;}
int div(int a,int b) {return a/b;}
int mul(int a,int b) {return a*b;}
int mod(int a,int b) {return a%b;}
int main(){

}

// #include<stdio.h>
// #include<limits.h>
// int fun(int arr[],int n){
//     int s=0;
//     int e=n-1;
//     int ans=-1;
//     while(s<=e){
//         int mid=s+(e-s)/2;
//         if(mid==0||arr[mid-1]<arr[mid]){
//             ans=mid;
//             s=mid+1;
//         }
//         else e=mid-1;
//     }
//     return ans;
// }
// int rev(int n){
//     int flag=0;
//     if(n<0){
//         flag=1;
//         n=-n;
//     }
//     int r=0;
//     while(n!=0){
//         if(r>(INT_MAX-n%10)/10) return 0;
//         r=r*10+n%10;
//         n/=10;
//     }
//     // if(r>1e9||r<-1e9) return 0;
//     if(flag) return -r;
//     return r;
// }
// int main(){
//     // int n=3;
//     // int arr[]={3,2,1};
//     // printf("%d",fun(arr,n));
//     int n=-4501;
//     printf("%d",rev(n));
// }