#include<iostream>
using namespace std;
class Currency{
    int value;
    public:
        Currency(int a):value(a){}
        Currency operator +(const Currency &obj){
            return Currency(value+obj.value);
        }
        Currency operator -(const Currency &obj){
            return Currency(value-obj.value);
        }
        Currency operator -(){
            return Currency(-value);
        }
        Currency& operator +=(const Currency &obj){
            value+=obj.value;
            return *this;
        }
        void operator -=(const Currency &obj){
            value-=obj.value;
        }
        friend ostream& operator <<(ostream &os,const Currency &curr);
};
ostream& operator <<(ostream &os,const Currency &curr){
    os<<curr.value;
    return os;
}
int main(){
    int num;
    cout<<"Enter the value of currency 1: ";
    cin>>num;
    Currency c1(num);
    cout<<"Enter the value of currency 2: ";
    cin>>num;
    Currency c2(num);
    Currency c3=c1+c2,c4=c1+20,c5=c1-c2,c6=c1-10,c7=-c1;
    cout<<endl<<"Currency 1: "<<c1;
    cout<<endl<<"Currency 2: "<<c2;
    cout<<endl<<"Currency 3 (c1+c2): "<<c3;
    cout<<endl<<"Currency 4 (c1+20): "<<c4;
    cout<<endl<<"Currency 5 (c1-c2): "<<c5;
    cout<<endl<<"Currency 6 (c1-10): "<<c6;
    cout<<endl<<"Currency 7 (-c1): "<<c7;
    c1+=c2;
    c2-=10;
    cout<<endl<<"Currency 1 (after adding the c2 in c1): "<<c1;
    cout<<endl<<"Currency 2 (after after applying discount of Rs.10): "<<c2;
    return 0;
}