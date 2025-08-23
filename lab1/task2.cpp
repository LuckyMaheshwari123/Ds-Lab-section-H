#include<iostream>
using namespace std;
class Exam{
    string * name;
    string * date;
    int *score;
    public:
    Exam(){
        name=new string("");
        date= new string("");
        score=new int(0);
    }

    Exam(string n,string d,int sc){
        name=new string(n);
        date= new string(d);
        score=new int(sc);
    }
    //shallow
    void update(string nam){
        *name=name;
    }
    void display(){
        cout<<*name<<endl;
        cout<<*date<<endl;
        cout<<*score<<endl;
    }




~Exam(){
    delete name;
    delete date;
    delete score;
}
};
int main(){
    Exam e1("Lucky","20-3-1975",100);
    Exam e2=e1;
    e2.display();
    e2.update("Kumar");
    e1.display();
    e2.display();


}
}
