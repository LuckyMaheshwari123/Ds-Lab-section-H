#include<iostream>
using namespace std;
int * allocateMemory(int n){
    int * arr=new int[n];
    for(int i=0;i<n;i++){
        arr[i]=0;
    }

    return arr;


}

void updateValue(int *ptr,int position,int value){
    
    ptr[position]=value;
}

void printArr(int *ptr,int s){
     for(int i=0;i<s;i++){
        cout<<ptr[i]<<" ";
    }
    cout<<endl;

}

int main(){

    int s;
    cout<<"Enter size:";
    cin>>s;
    int * p=allocateMemory(s);

    int index,choice;
   
    
    cout<<"default elements:";
    printArr(p,s);
     cout<<"enter postion and update value respectively:";
     cin>>index>>choice;
    if(index<0||index>=s){
        cout<<"invalid index;";
        delete[] p;
        return 0;
    }
    updateValue(p,index,choice);
    printArr(p,s);

    delete[]p;

}
