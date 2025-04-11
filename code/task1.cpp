#include<iostream>
using namespace std;
class Humidity;
class Temperature{
    int temp;
    public:
        Temperature(int t){
            temp=t;
        }
        friend float calculateHeatIndex(Temperature t,Humidity h);
};
class Humidity{
    int hum;
    public:
        Humidity(int h){
            hum=h;
        }
        friend float calculateHeatIndex(Temperature t,Humidity h);
};
float calculateHeatIndex(Temperature t,Humidity h){
    float heat_index;
    heat_index=t.temp+(0.33*h.hum)-(0.7*t.temp)-4;
    return heat_index;
}
int main(){
    Temperature t1(32);
    Humidity h1(78);
    cout<<"Temperature: 32C"<<endl<<"Humidity: 78%"<<endl<<"Heat Index: "<<calculateHeatIndex(t1,h1)<<"C";
    return 0;
}