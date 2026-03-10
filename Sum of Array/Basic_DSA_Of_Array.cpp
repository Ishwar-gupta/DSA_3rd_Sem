// Problem -01
// WAP to calculate sum and product of all numbers in an array.

#include <iostream>

using namespace std;

int main()
{
int arr[]={1,2,3,4,5};
int size=sizeof(arr)/sizeof(int);
int sum=0,product=1;

for(int i=0;i<size;i++){
    sum += arr[i];
    product *= arr[i];
}

cout<<"Sum of given Array = "<<sum<<endl;
cout<<"\nProduct of given Array = "<<product<<endl;
    return 0;
}

//Problem-02
//WAP to swap the max and min number of of an array.
#include<iostream>
#include<climits>
using namespace std;

void swapped_Element(int &small,int &large){
    //swap(small,large);
    int temp=small;
    small=large;
    large=temp;
}

int main(){
int arr[]={10,5,20,4,2};
int size=sizeof(arr)/sizeof(int);
int small=INT_MAX;
int large=INT_MIN;

//for smallest element of an array
for(int i=0;i<size;i++){
    if(arr[i] < small){
        small=arr[i];
    }
}

//for largest element of an array
for(int i=0;i<size;i++){
    if(arr[i]  > large){
        large=arr[i];
    }
}
cout<<"Before Swapping min and max element of an array:\n"<<endl;
cout<<"Smallest element = "<<small<<endl;
cout<<"Largest element = "<<large<<endl;

swapped_Element(small,large);
cout<<"\nAfter Swapping min and max element of an array:\n"<<endl;
cout<<"Value of Smallest element = "<<small<<endl;
cout<<"Value of Largest element = "<<large<<endl;

return 0;
}

//problem-03
//WAP to print all the unique values in an array

#include<iostream>

using namespace std;

int main(){
int arr[]={1,2,3,4,3,5,2,1};
int size=sizeof(arr)/sizeof(int);
cout<<" Unique values of array: ";
for(int i=0;i<size;i++){
  int count=0;
    for(int j=0;j<size;j++){
        if(arr[i] == arr[j]){
            count++;
        }
    }
    if(count==1)
    cout<<arr[i]<<" ";
}
return 0;
}


//Problem-04 WAP to print intersection of 2 arrays.
#include<iostream>
using namespace std;

int main(){
int arr1[]={1,2,3,4,5,1,2,3,5};
int arr2[]={3,4,5,6,7};

int size1=sizeof(arr1)/sizeof(int);
int size2=sizeof(arr2)/sizeof(int);

cout<<"Intersection of two arrays: ";
for(int i=0;i<size1;i++){
    int isDuplicate=0;
    //check if arr1[i] appeared before
    for(int k=0;k<i;k++){
        if(arr1[i]==arr1[k]){
            isDuplicate=1;
            break;
        }
    }

    // if not duplicate check intersection
    if(isDuplicate==0){
        for(int j =0 ; j< size2 ; j++){
            if(arr1[i]==arr2[j]){
                cout<<arr1[i]<<" ";
            }
        }
    }
}
return 0;
}


//Problem-04
//WAP to move all zeroes at the end without using sorting algorithm but you can use 2-pointer approach
/*
Input:  3  2 0 5 0 1 0
Expected Ouput: 3 2 5 1 0 0 0
*/

#include <iostream>
using namespace std;

int main() {
    int arr[] = {3, 2, 0, 5, 0, 1, 0};
    int size = sizeof(arr) / sizeof(int);

    int j = 0;   // pointer for non-zero position

    for (int i = 0; i < size; i++) {
        if (arr[i] != 0) {
            // swap arr[i] and arr[j]
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            j++;
        }
    }

    cout << "Output: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}
