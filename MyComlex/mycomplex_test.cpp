#include <iostream>
#include <cstdio>
#include <vector>
#include "mycomplex.h"
using namespace std;


int main(){

    //initialization 9 complex numbers
    vector<MyComplex> Complex_numbers;
    int num = 1;
    MyComplex z1(2,7);
    z1.init(Complex_numbers);
    MyComplex z2(42,-9);
    z2.init(Complex_numbers);
    MyComplex z3(-11,19);
    z3.init(Complex_numbers);

    //z4 = z1*z2
    MyComplex z4 = z1 * z2;
    z4.init(Complex_numbers);
    //z5 = (z1+z2)
    MyComplex z5 = z1 + z2;
    z5.init(Complex_numbers);
    //z6 = (z1+z2)*2
    MyComplex z6 = (z1 + z2)*2;
    z6.init(Complex_numbers);
    //z7 = (z2+z3)*z1
    MyComplex z7 = (z2 + z3)*z1;
    z7.init(Complex_numbers);
    //z8 = z1+5;
    MyComplex z8 = z1;

    z1 = z7;
    z8.init(Complex_numbers);
    //z9 = -z1+z2;
    MyComplex z9 = -z1;
    z9.init(Complex_numbers);

//    for(auto i:Complex_numbers){
//        i.print_result(num);
//        num++;
//    }
//    for(auto i:Complex_numbers){
//        cout << i.norm() << endl;
//    }

    int counter = 2000;

    for (int nx = 0; nx <= 750; ++nx) {
        for (int ny = 0; ny <= 500; ++ny) {
            MyComplex z0(1.5, 1);
            MyComplex zi = z0;
            const MyComplex c0(-0.75,0.1);

            bool ifconver = true;
            while (counter && ifconver) {
               MyComplex z_plus = zi*zi;
               MyComplex z_next = z_plus + c0;
               if (z_next.norm() > 100) {
                   cout << z_next.norm() << endl;
                   int inter = 2000 - counter + 1;
                   ifconver = false;
               }
               zi = z_next;
               counter--;
            }
            if (ifconver) {
            }
        }
    }
}
