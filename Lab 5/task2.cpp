void functionA(int n);

void functionB(int n){
    if(n==0) return;
    cout<<n<<" ";
    functionA(n-1);
}

void functionA(int n){
    if(n==0) return;
    cout<<n<<" ";
    functionB(n-1);
}


void printNumbers(int n){
    if(n==0) return;
    cout<<n<<" ";
    printNumbers(n-1);
}
int main() {
   int n;
   cout<<"enter number:";
   cin>>n;
   cout<<"from direct:";
    printNumbers(n);
    cout<<endl;
    cout<<"from indirect:";
    functionB(n);
    
    return 0;
}
