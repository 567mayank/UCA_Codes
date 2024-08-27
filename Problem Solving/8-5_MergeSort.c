#include<stdio.h>
#include<stdlib.h>
void mergeSort(int arr[],int start,int end){
    if(start>=end) return ;
    int mid=(start+end)/2;
    mergeSort(arr,start,mid);
    mergeSort(arr,mid+1,end);
    int newArr[end-start+1];
    int i=0,j=start,k=mid+1;
    while(j<=mid&&k<=end){
        if(arr[j]<arr[k]) newArr[i++]=arr[j++];
        else newArr[i++]=arr[k++];
    }
    while(j<=mid) newArr[i++]=arr[j++];
    while(k<=end) newArr[i++]=arr[k++];
    i=0;
    for(int j=start;j<=end;j++) arr[j]=newArr[i++];
}


void merge(int arr[],int aux[],int start,int mid,int end){
    for(int k=start;k<=end;k++) aux[k]=arr[k];
    int i=start;int j=mid+1;
    for(int k=start;k<=end;k++){
        if(i>mid) arr[k]=aux[j++];
        else if(j>end) arr[k]=aux[i++];
        else if(aux[i]<aux[j]) arr[k] = aux[i++];
        else arr[k] = aux[j++];
    }
}
void merge_sort_recursive(int arr[],int aux[],int start,int end){
    if(start>=end) return;
    int mid=(start+end)/2;
    merge_sort_recursive(arr,aux,start,mid);
    merge_sort_recursive(arr,aux,mid+1,end);
    merge(arr,aux,start,mid,end);
}
void merge_sort(int arr[],int n){
    int *aux = (int *)malloc(n * sizeof(int));
    merge_sort_recursive(arr,aux,0,n-1);
    free(aux);
}
int main(){
    int n=6;
    int arr[]={1,4,5,6,8,3};
    merge_sort(arr,n);
    for(int i=0;i<n;i++) printf("%d ",arr[i]);
}