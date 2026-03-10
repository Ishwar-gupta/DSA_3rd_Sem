

#include <iostream>
#include<climits>

using namespace std;

int main()
{
    int arr[]={1,5,15,22,-15,24};
    int size=6;
    int smallest=INT_MAX;
    int index=-1;

    for(int i =0 ; i < size ; i++){
    if(arr[i] < smallest){
        smallest=min(arr[i],smallest);
        index=i;
        }
    }

    cout<<"Smallest= "<<smallest<<endl;
    cout<<"Index found at "<<index<<endl;
    return 0;
}

/*

#include <iostream>
#include <climits>
using namespace std;

int main()
{
    int arr[6] = {1, 5, 15, 22, -15, 24};
    int size = 6;

    int smallest = INT_MAX;
    int largest=INT_MIN;
    int small_index = -1;
    int large_index=-1;

    for(int i = 0; i < size; i++)
    {
        if(arr[i] < smallest)
        {
            smallest = arr[i];
            small_index = i;
        }
    }
    for(int i = 0; i < size; i++){
        if(arr[i] > largest){
            largest = arr[i];
            large_index = i;
        }
    }


    cout << "Smallest element = " << smallest << endl;
    cout << "Smallest element's Index = " << small_index << endl;

    cout << "largest element = " << largest << endl;
    cout << "largest element's Index = " << large_index << endl;

    return 0;
}
*/

/*
//pass by reference

#include<iostream>
using namespace std;
void changeArr(int arr[],int size){
    cout<<"In Function.\n";
    for(int i=0;i<size;i++){
        arr[i]=2 * arr[i];
    }
}

int main(){
int arr[]={1,2,3};
changeArr(arr,3);

cout<<"In Main:\n";
for(int i=0;i<3;i++){
    cout<<arr[i]<<" ";
}
cout<<endl;
return 0;
}
*/
/*
Expected Output:
In Function.
In Main:
2 4 6
*/

/*
//Linear search

#include<iostream>
using namespace std;

int main(){
int arr[]={4,2,7,8,1,8,2,5};
int size=sizeof(arr)/sizeof(int);
int target=80;

for(int i=0;i<size;i++){
    if(target==arr[i]){
        cout<<i;
        break;
    }else
    return -1;
}
return 0;
}
*/