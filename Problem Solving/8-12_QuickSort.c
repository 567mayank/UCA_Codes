#include<stdio.h>
void exc(int arr[],int i,int j){
    int a=arr[i];
    arr[i]=arr[j];
    arr[j]=a;
}
void quickSortRecursive(int arr[],int start,int end){
    if(start>=end) return;
    int pivot=arr[start];
    int i=start+1;
    for(int j=start+1;j<=end;j++){
        if(arr[j]<pivot){
            exc(arr,i++,j);
        }
    }
    exc(arr,start,--i);
    quickSortRecursive(arr,start,i-1);
    quickSortRecursive(arr,i+1,end);
}
void quickSort(int arr[],int n){
    quickSortRecursive(arr,0,n-1);
}
int main(){
    int n=6;
    int arr[]={11,4,5,6,8,3};
    quickSort(arr,n);
    for(int i=0;i<n;i++) printf("%d ",arr[i]);
    return 0;
}