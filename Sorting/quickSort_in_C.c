#include<stdio.h>
#include<stdlib.h>

int partition(int arr[],int st ,int end){
    int indx=st-1;
    int pivot=arr[end];

    for(int j=st;j<end;j++){
        if(arr[j] < pivot){
            indx++;
            int temp=arr[j];
            arr[j]=arr[indx];
            arr[indx]=temp;
        }
    }
    
    indx++;
    int temp=arr[end];
    arr[end]=arr[indx];
    arr[indx]=temp;

    return indx;
}


void quickSort(int arr[],int st , int end){
    if(st < end){

        int pivtIndx=partition(arr,st,end);

        quickSort(arr,st,pivtIndx-1);
        quickSort(arr,pivtIndx+1,end);
    }
}

//displaying the sorted arry 
void sortedArray(int arr[],int st ,int end){
    for(int i=0;i<end;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
}

int main(){
    int arr[]={5,2,6,4,1,3,9,122,34};
    int size=sizeof(arr)/sizeof(int);
    quickSort(arr,0,size-1);
    sortedArray(arr,0,size-1);
    return 0;
    
}