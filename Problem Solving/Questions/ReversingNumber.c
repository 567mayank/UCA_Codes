#include<stdio.h>
#include<limits.h>
int rev(int n){
    int flag=0;
    if(n<0){
        flag=1;
        n=-n;
    }
    int r=0;
    while(n!=0){
        if(r>(INT_MAX-n%10)/10) return 0;
        r=r*10+n%10;
        n/=10;
    }
    if(flag) return -r;
    return r;
}
int main(){
    int n=-4501;
    printf("%d",rev(n));
}