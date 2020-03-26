#include "Matrice_Complexa.h"



int main()
{
    Matrice_Complexa M1(1,3,3), M2(1,6,6), M4(M1);
    Matrice_Complexa M3 = M1;
    std::cout << M3;
    return 0;
}
