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

void inputMatrix(int **p,int r,int c){
    cout<<"enter matrix elements:";
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


int** addmatrix(int **m1,int**m2,int r1,int r2,int c1,int c2){
    if(r1==r2 && c1==c2){
        int** newmatrix=allocateMemory(r1,c1);
        for(int i=0;i<r1;i++){
            for(int j=0;j<c1;j++){
                newmatrix[i][j]=m1[i][j]+m2[i][j];
            }
        }
    return newmatrix;

    }

    else{
       
        return nullptr;
    }
}

int** subtractmatrix(int **m1,int**m2,int r1,int r2,int c1,int c2){
    if(r1==r2 && c1==c2){
        int** newmatrix=allocateMemory(r1,c1);
        for(int i=0;i<r1;i++){
            for(int j=0;j<c1;j++){
                newmatrix[i][j]=m1[i][j]-m2[i][j];
            }
        }
        return newmatrix;
    

    }

    else{
        
        return nullptr;
    }
}
int main()
{

int r1,r2,c1,c2;
cout<<"enter the rows and cols of first matrix:";
cin>>r1>>c1;
int **mat1=allocateMemory(r1,c1);
inputMatrix(mat1,r1,c1);
cout<<"enter the rows and cols of 2nd matrix:";
cin>>r2>>c2;
int **mat2=allocateMemory(r2,c2);
inputMatrix(mat2,r2,c2);

int **sum = addmatrix(mat1, mat2, r1, r2, c1, c2);
    if (sum != nullptr) {
        cout << "Sum of matrices:" << endl;
        printMatrix(sum, r1, c1);
        deallocate(sum, r1);  // Deallocate the memory after use
    }
int **diff = subtractmatrix(mat1, mat2, r1, r2, c1, c2);
    if (diff != nullptr) {
        cout << "Difference of matrices:" << endl;
        printMatrix(diff, r1, c1);
        deallocate(diff, r1);  // Deallocate the memory after use
    }

 deallocate(mat1, r1);
    deallocate(mat2, r2);

    return 0;

    
} 
