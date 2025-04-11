#include<iostream>
using namespace std;
class Fraction{
    int numerator,denominator;
    public:
        Fraction(int num,int den){
            numerator=num;
            if(den!=0){
                denominator=den;
            }
            else{
                do{
                    cout<<"Invalid input! Denominator should be non-zero\nEnter denominator: ";
                    cin>>denominator;
                }while(denominator==0);
            }
            if(denominator<0){
                numerator=-numerator;
                denominator=-denominator;
            }
        }
        Fraction operator +(const Fraction &obj){
            int num=(numerator*obj.denominator)+(obj.numerator*denominator);
            int den=denominator*obj.denominator;
            return Fraction(num,den);
        }
        Fraction operator -(const Fraction &obj){
            int num=(numerator*obj.denominator)-(obj.numerator*denominator);
            int den=denominator*obj.denominator;
            return Fraction(num,den);
        }
        Fraction operator *(const Fraction &obj){
            int num=numerator*obj.numerator;
            int den=denominator*obj.denominator;
            return Fraction(num,den);
        }
        Fraction operator /(const Fraction &obj){
            int num=numerator*obj.denominator;
            int den=denominator*obj.numerator;
            return Fraction(num,den);
        }
        friend ostream& operator <<(ostream &os,const Fraction &f);
};
ostream& operator <<(ostream &os,const Fraction &f){
    os<<f.numerator<<"/"<<f.denominator;
    return os;
}
int main(){
    int num,den;
    cout<<"For fraction 1"<<endl;
    cout<<"Enter numerator: ";
    cin>>num;
    cout<<"Enter denominator: ";
    cin>>den;
    Fraction f1(num,den);
    cout<<"For fraction 2"<<endl;
    cout<<"Enter numerator: ";
    cin>>num;
    cout<<"Enter denominator: ";
    cin>>den;
    Fraction f2(num,den);
    Fraction add=f1+f2,sub=f1-f2,mul=f1*f2,div=f1/f2;
    cout<<"Fraction 1 (f1): "<<f1<<endl;
    cout<<"Fraction 2 (f2): "<<f2<<endl;
    cout<<"Addition (add=f1+f2): "<<add<<endl;
    cout<<"Subtraction (sub=f1-f2): "<<sub<<endl;
    cout<<"Multiplication (mul=f1*f2): "<<mul<<endl;
    cout<<"Division (div=f1/f2): "<<div<<endl;
    return 0;
}