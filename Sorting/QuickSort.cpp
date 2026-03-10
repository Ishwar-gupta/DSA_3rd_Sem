#include<iostream>
#include<vector>

using namespace std;

int partition(vector<int> &arr , int st , int end){
    int indx=st-1,pivot=arr[end];

    for(int j=st;j<end;j++){
        if(arr[j] <= pivot){
            indx++;
            swap(arr[j],arr[indx]);
        }
    }

    indx++;
    swap(arr[end],arr[indx]);

    return indx;
}

void quickSort(vector<int> &arr , int st , int end){
    if(st < end){
        int pvtIndx=partition(arr,st,end);

        quickSort(arr,st,pvtIndx-1);
        quickSort(arr,pvtIndx+1,end);
    }
}

int main(){
    vector<int> arr = { 5,2,6,4,1,3};
    quickSort(arr,0,arr.size()-1);

    //displaying the sorted array using forEach loop
    for(int val:arr){
        cout<<val<<" ";
    }
    cout<<endl;
    return 0;


}

















/*
#include <iostream>
using namespace std;

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    
    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    cout << "Original array: ";
    printArray(arr, n);
    
    quickSort(arr, 0, n - 1);
    
    cout << "Sorted array: ";
    printArray(arr, n);
    
    return 0;
}
*/