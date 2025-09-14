#include<iostream>
using namespace std;

   int shellsort(int arr[],int n){
    for (int gap = n / 2; gap > 0; gap /= 2) {
        int count=0;
        for (int i = gap; i < n; i++) {
            int temp = arr[i];
            int j = i;

            
            while (j >= gap && arr[j - gap] > temp) {
                arr[j] = arr[j - gap];
                j -= gap;
                count++;
            }

           
            arr[j] = temp;
        }
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
    shellsort(arr,n);
    cout<<"after sorting:";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;




delete []arr;
}
