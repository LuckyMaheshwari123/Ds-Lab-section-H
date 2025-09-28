// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;
int sumtail(int n,int total){
    if(n==0) return total;
    return sumtail(n-1,total+n);
}
int sumNotail(int n){
    if(n==0)return 0;
    return n+sumNotail(n-1);
}
int main() {
 int n=sumtail(100,0);
 cout<<n<<endl;
int m=sumNotail(100);
cout<<m<<endl;
    return 0;
}

//tail recursion does not wait in the stack to give the output while no tailed wait stack to exceute until the 
//last condition exceute so memoery wise tail recursion is best
