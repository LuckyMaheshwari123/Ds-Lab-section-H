#include<iostream>
using namespace std;
void bubblesort(int arr[],int n){
    int count=0;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(arr[i]>arr[j]){
                int temp=arr[i];
                arr[i]=arr[j];
                arr[j]=temp;
                count++;
            }

        }
    }
    cout<<"THE swap cout is "<<count<<endl;
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
    bubblesort(arr,n);
    cout<<"after sorting:";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;




delete []arr;
}
