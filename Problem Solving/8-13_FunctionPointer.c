#include<stdio.h>
// using funtion pointers for generalising code
void sort(int arr[],int n,int (*compare)(int a,int b)){   
    for(int i=0;i<n;i++){
        for(int j=0;j<n-i-1;j++){
            if(compare(arr[j],arr[j+1])){
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
}
int compareAsc(int a,int b){
    return a>b;
}
int compareDesc(int a,int b){
    return a<b;
}
void printArr(int arr[],int n){
    for(int i=0;i<n;i++) printf("%d ",arr[i]);
    printf("\n");
}
int main(){
    int arr[]={1,4,5,3,6,7};
    int n=6;
    sort(arr,n,compareAsc);
    printArr(arr,n);

    sort(arr,n,compareDesc);
    printArr(arr,n);
}