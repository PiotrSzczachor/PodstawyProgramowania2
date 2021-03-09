#include <iostream>
#include <cmath>
#include "fmt-master/include/fmt/core.h"

using namespace std;

class Trojkat{

private:

    float a;
    float b;
    float c;

public:
    ~Trojkat(){
        cout<<"Destruktor Trojkat"<<endl;
    }
    Trojkat(float bok1, float bok2, float bok3){
        a = bok1;
        b = bok2;
        c = bok3;
        cout<<"Konstruktor trojkata o roznych bokach\n";
    }
    explicit Trojkat(float bok){
        a = bok;
        b = bok;
        c = bok;
        cout<<"Konstruktor trojkata rownoboczngo\n";
    }
    void podaj(){
        cout<<"Podaj pierwszy bok\n";
        cin>>a;
        cout<<"Podaj drugi bok\n";
        cin>>b;
        cout<<"Podaj trzeci bok\n";
        cin>>c;
        if(a<=0||b<=0||c<=0)
        {
            cout<<"Boki nie moga przyjac takich wartosci\n";
            exit(0);
        }
        else if((a+b<=c)||(a+c<=b)||(b+c<=a))
        {
            cout<<"Boki nie moga przyjac takich wartosci\n";
            exit(0);
        }
    }
    void perimeter() const{
        cout<<a+b+c<<endl;
    }
    void area() const{
        float p=(a+b+c)/2;
        float area = sqrt(p*(p-a)*(p-b)*(p-c));
        cout<<area<<endl;
    }
};




class Prostokat{

private:
    float a;
    float b;

public:
    ~Prostokat(){
        cout<<"Destruktor Prostokat"<<endl;
    }
    explicit Prostokat(float bok){
        cout<<"Konstruktor kwadratu\n";
        a = bok;
        b = bok;
    }
    Prostokat(float bok1, float bok2){
        a = bok1;
        b = bok2;
        cout<<"Konstruktor prostokata\n";
    }
    void podaj(){
        cin>>a;
        cin>>b;
        if(a<=0||b<=0)
        {
            cout<<"Boki nie moga przyjac takich wartosci\n";
            exit(0);
        }
    }
    void perimeter() const{
        cout<<2*a+2*b<<endl;
    }
    void area() const{
        cout<<a*b<<endl;
    }
};


class Kolo{
private:
    float r;
    float pi = 3.14;
public:
    ~Kolo(){
        cout<<"Destruktor Kolo"<<endl;
    }
    Kolo(){
        r = 5;
        cout<<"Konstruktor ze stalym promieniem"<<endl;
    }
    explicit Kolo(float promien){
        cout<<"Konstruktor ze zmiennym promienien"<<endl;
        r = promien;
    }
    void set_r()
    {
        cout<<"Podaj promien"<<endl;
        cin>>r;
    }
    void get_pi() const
    {
        cout<<pi<<endl;
    }
    void area() const{
        cout<<2*pi*r<<endl;
    }
    void perimeter() const{
        cout<<pi*r*r<<endl;
    }
};


int main()
{
    Trojkat t1(1);
    Trojkat t2(2,4,3);
    t1.perimeter();
    t1.area();
    Prostokat p1(4);
    Prostokat p2(4, 5);
    p1.perimeter();
    p1.area();
    p2.perimeter();
    p2.area();
    Kolo k1;
    Kolo k2(3);
    k1.area();
    k1.perimeter();
    k2.area();
    k2.perimeter();
}
