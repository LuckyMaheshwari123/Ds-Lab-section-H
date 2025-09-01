#include<iostream>
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

void fillseat(int**ptr,int bench,int seat){
    if(ptr[bench][seat]==1){
        cout<<"bench already filled";
        return;

    }

    ptr[bench][seat]=1;
}
int main(){
    int r,c;
    cout<<"enter rows and cols respectively:";
    cin>>r>>c;

int**s=allocateMemory(r,c);

cout<<"default values:"<<endl;
printMatrix(s,r,c);

int seat,bench;
cout<<"enter bench number then seat number:";
cin>>bench>>seat;
if(bench<0 || seat<0 || bench>=r || seat>=c){
    cout<<"invalid index";
    deallocate(s,r);
    return 1;

}

fillseat(s,bench,seat);


printMatrix(s,r,c);

deallocate(s,r);




}
