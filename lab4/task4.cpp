#include<iostream>
using namespace std;
void insertion(int arr[],int n){
    for(int i=1;i<n;i++){
        int temp=arr[i];
        int j=i-1;
        while(j>=0 && arr[j]>temp){
            arr[j+1]=arr[j];//shift elements
            j--;
        }
        arr[j+1]=temp;

    }
}

void search(int arr[],int n,int key){
    int low=0;
    int high=n-1;
    while(low<=high){
        int mid=(low+high)/2;
        if(arr[mid]==key){
        cout<<"elemnt find at "<<mid<<" index"<<endl;
        return;
        }
        else if(arr[mid]<key){
            low=mid+1;//forward
        }
        else if(arr[mid]>key){
            high=mid-1;//backwards
        }
    }
    cout<<"element not found";
    return;
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
    insertion(arr,n);
    cout<<"after sorting:";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    int k;
    cout<<"enter element you want to search:";
    cin>>k;
    search(arr,n,k);




delete []arr;
}



