

#include<stdio.h>

void bubbleSort(int arr[],int n){
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(arr[j]>arr[j+1]){
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
}
void printArray(int arr[],int n){
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
}

int main(){
    int n=5;
    int arr[]={5,2,9,6,1};
    bubbleSort(arr,n);
    printArray(arr,n);
    return 0;
}

/*

#include<stdio.h>

void bubbleSort(int arr[], int n){
    int swapped;

    for(int i = 0; i < n-1; i++){
        swapped = 0;   // reset flag

        for(int j = 0; j < n-i-1; j++){
            if(arr[j] > arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                swapped = 1;   // swap happened
            }
        }

        // if no swap occurs, array is already sorted
        if(swapped == 0){
            break;
        }
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

    bubbleSort(arr,n);
    printArray(arr,n);

    return 0;
}

*/