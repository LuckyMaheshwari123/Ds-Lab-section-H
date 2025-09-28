#include<iostream>
using namespace std;

int ackerman(int m,int n){
    if(m==0)return n+1;
    if(m>0 &&n==0) return ackerman(m-1,n);
    if(m>0 &&n>0) return ackerman(m-1,ackerman(m-1,n));
}


int main() {
   int l= ackerman(5,3);
   cout<<l<<endl;
    return 0;
}
