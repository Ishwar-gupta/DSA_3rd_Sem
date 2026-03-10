#include<stdio.h>

void selectionSort(int arr[],int n){
    for(int i=0;i<n-1;i++){
        int smallIdx=i;
        for(int j=i+1;j<n;j++){
            if(arr[j] < arr[smallIdx]){
                smallIdx = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[smallIdx];
        arr[smallIdx]=temp;
    }
}

void printArray(int arr[], int n){
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
}

int main(){
    int arr[] = {1,8,3,10,5}; 
    int n = 5;

    selectionSort(arr,n);
    printArray(arr,n);

    return 0;
}