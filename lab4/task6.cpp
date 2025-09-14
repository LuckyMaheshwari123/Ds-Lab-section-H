
#include<iostream>
using namespace std;
void combsort(int arr[],int n){
float shrink=1.3;
int gap=n;
bool swap=true;
int count=0;
while(gap>1 ||swap){
    gap=int(gap/shrink);
    if(gap<1){
        gap=1;
    }
swap=false;
    for(int i=0;i+gap<n;i++){
        
            if(arr[i]>arr[i+gap]){
                int temp=arr[i];
                arr[i]=arr[i+gap];
                arr[i+gap]=temp;
                swap=true;
                count++;
            }

        }
    }

    cout<<"\nThe number of swap happen "<<count<<endl;
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
    combsort(arr,n);
    cout<<"after sorting:";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;




delete []arr;
}
