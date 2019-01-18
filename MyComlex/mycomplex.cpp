#include "mycomplex.h"
#include <math.h>
#include <iostream>

using namespace std;

//Constructor
MyComplex::MyComplex(const double &x, const double &y)
{
    this->x = x;
    this->y = y;
}
//Copy-Constructor
MyComplex::MyComplex(const MyComplex &a)
{
    this->x = a.x;
    this->y = a.y;
}
//Destructor
MyComplex::~MyComplex (){}

//Rückgabe von Realtei
double MyComplex::real() const{
    return this->x;
}
//Rückgabe des Imaginärteil
double MyComplex::imag() const{
    return this->y;
}
//Berechnung des Betrags einer komplexen Zahl
double MyComplex::norm() const{
    double temp;
    double temp_x = this->x;
    double temp_y = this->y;
    temp = sqrt(temp_x*temp_x + temp_y*temp_y);

    return temp;

}
//Zuweisungsoperator
MyComplex &MyComplex::operator= (const MyComplex &a){
    this->x = a.x;
    this->y = a.y;

    return *this;
}

//Addition
const MyComplex MyComplex::operator+ (const MyComplex & a2) const{
    double temp_x = this->x + a2.x;
    double temp_y = this->y + a2.y;
    MyComplex temp(temp_x,temp_y);
    return temp;
}
//Addition const value
const MyComplex MyComplex::operator+ (const double & lambda) const{
    double temp_x = this->x + lambda;
    MyComplex temp(temp_x,this->y);
    return temp;
}
//Subtraktion
const MyComplex MyComplex::operator- (const MyComplex & a2) const{
    double temp_x = this->x - a2.x;
    double temp_y = this->y - a2.y;
    MyComplex temp(temp_x,temp_y);
    return temp;
}
//Subtraktion const value
const MyComplex MyComplex::operator- (const double & lambda) const{
    double temp_y = this->y - lambda;
    MyComplex temp(this->x,temp_y);
    return temp;
}
//Operator-
MyComplex MyComplex::operator- (){
    double temp_x = -this->x;
    double temp_y = -this->y;
    MyComplex temp(temp_x,temp_y);
    return temp;
}
//Skalarprodukt
const MyComplex MyComplex::operator* (const MyComplex & a2) const{
    double this_x = this->x;
    double this_y = this->y;
    double a2_x = a2.x;
    double a2_y = a2.y;

    double temp_x = this_x*a2_x - this_y*a2.y;
    double temp_y = this_x*a2_y + this_y*a2_x;

    MyComplex temp(temp_x,temp_y);
    return temp;

}
//Skalarprodukt with const value
const MyComplex MyComplex::operator* (const double & lamda) const{
  double temp_x = this->x * lamda;
  double temp_y = this->y * lamda;
  MyComplex temp(temp_x,temp_y);
  return temp;
}
//print result
void MyComplex::print_result(const int num) const{
    cout<< "z" << num << " " << "=" << " "<< this->x << " "<< "+" << " "<< this->y << "i" << endl;
}
//put complex numbers in vector
void MyComplex::init(vector<MyComplex> & List){
    List.push_back(*this);
}


