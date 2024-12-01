#include<iostream>
using namespace std;

void reverseArray(int arr[], int size){

    int i=0;
    int j=size-1;
    while(i<j){
        swap(arr[i],arr[j]);
        i++;
        j--;
    }
}

int main(){

    int arr[]={4,2,7,8,1,2,5};

    cout<<"before reverse "<<endl;
    for(int i=0;i<7;i++){
        cout<<arr[i]<<" ";
    }

    cout<<endl;


    reverseArray(arr,7);

    cout<<"after reverse "<<endl;


    for(int i=0;i<7;i++){
        cout<<arr[i]<<" ";
    }




    return 0;
}