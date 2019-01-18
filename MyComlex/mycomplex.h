#ifndef MYCOMPLEX_H
#define MYCOMPLEX_H
#include <vector>
using namespace std;


class MyComplex
{
public:
    //constructor
    MyComplex();
    
    //initialization
    MyComplex(const double &x, const double &y);
    
    //copy constructor
    MyComplex(const MyComplex & a);
    
    //deconstructor
    ~MyComplex();
    
    //operator overloading
    
    //Addition
    const MyComplex operator+ (const MyComplex & a2) const;
    //Addition const value
    const MyComplex operator+ (const double & lambda) const;
    //Subtraktion
    const MyComplex operator- (const MyComplex & a2) const;
    //Operator-
    MyComplex operator- ();
    //Subtraktion const value
    const MyComplex operator- (const double & lambda) const;
    //Skalarprodukt
    const MyComplex operator* (const MyComplex & a2) const;
    //Produktion mit Skalar
    const MyComplex operator* (const double & lambda) const;
    
    //Zuweisungsoperator
    MyComplex & operator= (const MyComplex & a);

    //Berechnung des Betrags einer komplexen Zahl
    double norm() const;
    //Rückgabe von Realtei
    double real() const;
    //Rückgabe des Imaginärteil
    double imag() const;

    //Print the current result
    void print_result(const int num) const;

    //initialization complex numbers in a vector
    void init(vector<MyComplex> & List);

private:
    double x;
    double y;
};

#endif // MYCOMPLEX_H
