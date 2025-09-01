#include<iostream>
#include<stdlib.h>
using namespace std;
int **allocateMemory(int rows,int columns){
    //allocate
    int **arr=new int*[rows];
    for(int i=0;i<rows;i++){
        arr[i]=new int[columns];

    }
    //assign
    for(int i=0;i<rows;i++){
        for(int j=0;j<columns;j++){
            arr[i][j]=0;
        }
    }
    
      return arr;
  
    

    
}

void inputMatrix(int **p,int r,int c){
    cout<<"enter days readings respectively:";
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cin>>p[i][j];
        }
    }

}

void deallocate(int**ptr,int rows){
      // deallocate
    for(int i=0;i<rows;i++){
        delete[] ptr[i];
    }
   
    delete[]ptr;
   }

   void printMatrix(int**ptr,int rows,int cols){
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            cout<<ptr[i][j]<<" ";
        }
        cout<<endl;
    }
}

int getAverage(int* ptr, int n) {
    int total = 0;
    for (int i = 0; i < n; i++) {
        total += ptr[i];
    }
    if(n==0){
        return 1;
    }
    return total/n;
}

int* getDaily(int **ptr,int n,int m){
    int*av=new int[n];
    for(int i=0;i<n;i++){
        av[i]=getAverage(ptr[i],m);
    }
    return av;
}

int findMIN(int ** ptr,int n,int m){
    int min=INT32_MAX;
    int index=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(ptr[i][j]<min){
                min=ptr[i][j];
                index=i+1;
            }
        }
    }
    return index;
}

int findMAX(int ** ptr,int n,int m){
    int index=0;
    int max=INT32_MIN;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(ptr[i][j]>max){
                max=ptr[i][j];
                index=i+1;
            }
        }
    }
    return index;
}

int main(){

    int n;
    int m;
    cout<<"enter no of days:";
    cin>>n;
    cout<<"enter no of readings:";
    cin>>m;
    int**mat1 =allocateMemory(n,m);
    inputMatrix(mat1,n,m);

    int *average=getDaily(mat1,n,m);
    for(int i=0;i<n;i++){
        cout<<average[i]<<" ";
    }

   int ma=findMAX(mat1,n,m);
   int mi=findMIN(mat1,n,m);

   cout<<"Hottest Day is :"<<ma<<endl;
   cout<<"Coldest Day is :"<<mi<<endl;

   deallocate(mat1,n);
    
}
