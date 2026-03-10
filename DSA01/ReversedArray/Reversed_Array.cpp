#include <iostream>

using namespace std;
void reversedArray(int arr[],int sz){
    int start=0,end=sz-1;
    while(start<end){
        swap(arr[start],arr[end]);
        start++;
        end--;
    }
}

int main()
{
   int arr[]={4,2,7,8,1,2,5};
   int size=7;

   reversedArray(arr,size);
   cout<<"Reversed Array: ";
   for(int i=0;i<size;i++){
    cout<< arr[i]<<" ";
   }
   cout<<endl;
    return 0;
}
