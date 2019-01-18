#include <iostream>
#include <string>
#include "mycomplex.h"

using namespace std;

void output_my_cplx(const MyComplex &c,const std::string txt){
    cout<<txt<<": ("<<c.real()<<", "<<c.imag()<<")"<<endl;
}

int main(){
    MyComplex z1(2.,7.);
    MyComplex z2(42.,-9);
    MyComplex z3(-11.,19.);

    output_my_cplx(z1,"z1 ");
    output_my_cplx(z2,"z2 ");
    output_my_cplx(z3,"z3 ");
    
    MyComplex z4=z1*z2;
    output_my_cplx(z4,"z4=z1*z2 =");
    MyComplex z5=(z1+z2);
    output_my_cplx(z5,"z5=(z1+z2) =");
    MyComplex z6=(z1+z2)*2.;
    output_my_cplx(z6,"z6=(z1+z2)*2. = ");
    MyComplex z7=(z2+z3)*z1;
    output_my_cplx(z7,"z7=(z2+z3)*z1 = ");
    MyComplex z8=z1+5.;
    output_my_cplx(z8,"z8=z1+5. = ");
    MyComplex z9=-z1+z2;
    output_my_cplx(z9,"z9=-z1+z2 = ");
    
    return 0;
}
