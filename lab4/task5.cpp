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

    int interSearch(int arr[], int n, int key) {
    int left = 0, right = n - 1;

    while (left <= right && key >= arr[left] && key <= arr[right]) {
        // e-stimate position
        int pos = left + ((key - arr[left]) * (right - left)) / (arr[right] - arr[left]);

        if (arr[pos] == key) {
            return pos;  
        }
        else if (arr[pos] < key) {
            left = pos + 1;  
        }
        else {
            right = pos - 1; 
        }
    }

    return -1; 
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
    
    insertion(arr,n);
    int key;
    cout<<"enter element you want to search:";
    cin>>key;
  int ind=interSearch(arr,n,key);
  if(key==-1){
    cout<<"elements not found";
  }
  else{
    cout<<"element found at index "<<ind<<endl;
  }


    



}
