#include<iostream>
using namespace std;
void swap(int *a,int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}

void selectionsort(int arr[],int n){
    int len=n;
    for(int i=0;i<n-1;i++){
      int index=i;
      for(int j=i+1;j<n;j++){
        if(arr[j]<arr[index]){
            index=j;
        }
      }
      swap(arr[i],arr[index]);

      
    }
}

int main(){
    int n;
    cout<<"enter no of elements:";
    cin>>n;
    int *arr=new int[n];
    cout<<"enter the elements:";
    for(int i=0;i<n;i++){
        cin>>arr[i];

    }
    cout<<endl;

    cout<<"before sorted array:";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    selectionsort(arr,n);
    cout<<"after sorting:";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;




delete []arr;
}

