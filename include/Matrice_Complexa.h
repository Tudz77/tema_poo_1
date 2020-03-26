#ifndef MATRICE_COMPLEXA_H
#define MATRICE_COMPLEXA_H

#include <iostream>
#include <cstring>
#include <stdexcept>
class Matrice_Complexa
{
    int m, n;
    double* matrice;

public:
    Matrice_Complexa(double x, int m, int n);
    Matrice_Complexa();
    Matrice_Complexa(const Matrice_Complexa& other);
    ~Matrice_Complexa();
    void set_mn(int x, int y);
    int get_m();
    int get_n();
    void setpos(double x, int i, int j);
    double getpos(int i, int j) const;
    friend std::istream& operator>>(std::istream& stream, Matrice_Complexa& MatriceIn);
    friend std::ostream& operator<<(std::ostream& stream, Matrice_Complexa MatriceOut);
    friend Matrice_Complexa operator+(Matrice_Complexa m1, Matrice_Complexa m2);
    friend Matrice_Complexa operator*(Matrice_Complexa m1, Matrice_Complexa m2);
};

#endif

