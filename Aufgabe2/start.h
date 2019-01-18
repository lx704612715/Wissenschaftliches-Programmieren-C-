#ifndef START1_H
#define START1_H
#include <fstream>
#include <iostream>
#include "mycomplex.h"
#include <stdio.h>

using namespace std;


class start
{
public:
    start(const string path);
    start();
    void calculation() const;
    int n_inter(const MyComplex zi, const int nx, const int ny, const MyComplex c0) const;
private:
    int Vorschrift;
    double Xmin, Ymin, Xmax, Ymax;
    int Nxmax, Nymax;
    int Exponent;
    int Nmax;
    int Rc;
    double c0_real;
    double c0_imag;
    string Name;
};

start::start(const string path){
    ifstream dat_input;
    int Vorschrift;
    string outfile;
    double Xmin,Ymin,Xmax,Ymax,c0_real, c0_imag, Rc;
    int Nxmax, Nymax, Exponent, Nmax;
    dat_input.open(path);
    dat_input >> Vorschrift;
    dat_input >> Xmin >> Ymin >> Xmax >> Ymax;
    dat_input >> Nxmax >> Nymax;
    dat_input >> Exponent;
    dat_input >> Nmax;
    dat_input >> Rc;
    dat_input >> outfile;
    dat_input >> c0_real >> c0_imag;
    dat_input.close();
    this->Vorschrift = Vorschrift;
    this->Xmin = Xmin;
    this->Ymin = Ymin;
    this->Xmax = Xmax;
    this->Ymax = Ymax;
    this->Nxmax = Nxmax;
    this->Nymax = Nymax;
    this->Exponent = Exponent;
    this->Nmax = Nmax;
    this->Rc = Rc;
    this->Name = outfile;
    this->c0_real = c0_real;
    this->c0_imag = c0_imag;
}

int start::n_inter(const MyComplex z0, const int nx, const int ny, const MyComplex c0) const{
    int intern;
    MyComplex zi = z0;
    MyComplex z_pass;
    for (intern = 0; intern < this->Nmax; ++intern) {
        if (zi.norm() >= this->Rc) {
            break;
        }
        z_pass.reload(1,0);
        for (int i = 0; i < this->Exponent; ++i){
            z_pass = zi*z_pass;
        }
        zi = z_pass + c0;
    }
    return intern;
}
void start::calculation() const{
    ofstream os;
    MyComplex z0;
    os.open(this->Name);
    cout << this->Name << endl;
    MyComplex c0;
    double delta_nx = (this->Xmax - this->Xmin)/this->Nxmax;
    double delta_ny = (this->Ymax - this->Ymin)/this->Nymax;
    int n_inter = 0;
    for (int x = 0; x < this->Nxmax; ++x) {
        for (int y = 0; y < this->Nymax; ++y) {
            if (this->Vorschrift == 1) {
                double z0_real = this->Xmin + delta_nx*x;
                double z0_imag = this->Ymin + delta_ny*y;
                z0.reload(z0_real, z0_imag);
            }
            if (this->Vorschrift == 2 || this->Vorschrift == 3) {
                double creal = this->Xmin + delta_nx*x;
                double cimag = this->Ymin + delta_ny*y;
                c0.reload(creal, cimag);
            }
            n_inter = this->n_inter(z0, x, y, c0);
            os << x << ' ' << y << ' ' << n_inter << endl;
        }
    }
    os.close();
}

#endif // START1_H
