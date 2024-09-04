#include<stdio.h>
#include<stdlib.h>
void* callocImp(size_t sz,int n){
    int* arr= malloc(sz*n);
    for(int i=0;i<n;i++) {
        arr[i] = arr[i]&1;
    }
    return arr;
}
int main(){
    int* arr=callocImp(sizeof(int),6);
    for(int i=0;i<8;i++) printf("%d ",arr[i]);
}