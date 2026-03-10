
/*
#include <iostream>

using namespace std;
int LinearSearch(int arr[],int size,int target){
    for(int i=0;i<size;i++){
        if(arr[i]==target){//FOUND
            return i;
        }
    }
    return -1;  //NOT FOUND
}

int main()
{
   int arr[]={4,2,7,8,1,4,9,10};
   int size=sizeof(arr)/sizeof(int);
   int target=8;

   cout<<LinearSearch(arr,size,target)<<endl;
    return 0;
}
*/



#include <iostream>

using namespace std;
int LinearSearch(int arr[],int size,int target){
    for(int i=0;i<size;i++){
        if(arr[i]==target){//FOUND
            return i;
        }
    }
    return -1;  //NOT FOUND
}

int main()
{
   int arr[]={4,2,7,8,1,4,9,10};
   int size=sizeof(arr)/sizeof(int);
   int target;
   cout<<"Enter target element to find it's index:";
   cin>>target;

   cout<<"Target element found at index: "<<LinearSearch(arr,size,target)<<endl;
    return 0;
}




