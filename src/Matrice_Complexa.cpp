#include "Matrice_Complexa.h"

Matrice_Complexa::Matrice_Complexa(double x, int m, int n)
{
    this->n = n;
    this->m = m;

    matrice = new double[m * n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            matrice[m * i + j] = x;
        }
    }
}

Matrice_Complexa::Matrice_Complexa()
{
    m = 100;
    n = 100;
    matrice = new double[m * n];
}

Matrice_Complexa::Matrice_Complexa(const Matrice_Complexa& other)
{
    m = other.m;
    n = other.n;
    matrice = new double[m * n];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            matrice[m * i + j] = other.getpos(i,j);
}
Matrice_Complexa::~Matrice_Complexa()
{
    n = 0;
    m = 0;
    delete[] matrice;
}
void Matrice_Complexa::set_mn(int x, int y)
{
    m = x;
    n = y;
}
int Matrice_Complexa::get_m()                // GET M
{
    return this->m;
}
int Matrice_Complexa::get_n()                //GET N
{
    return this->n;
}
double Matrice_Complexa::getpos(int i, int j) const      //GET M[I][J]
{
    return matrice[m * i + j];
}
void Matrice_Complexa::setpos(double x, int i, int j)    //SET M[I][J]
{
    matrice[m * i + j] = x;
}
std::istream& operator>>(std::istream& stream, Matrice_Complexa& MatriceIn)
{
    int x, y, i, j;
    double p;
    stream >> x;
    stream >> y;
    MatriceIn.set_mn(x, y);
    for (i = 0; i < y; i++)
    {
        for (j = 0; j < x; j++)
        {
            stream >> p;
            MatriceIn.setpos(p, i, j);
        }
    }
    return stream;
}
std::ostream& operator<<(std::ostream& stream, Matrice_Complexa MatriceOut)
{
    for (int i = 0; i < MatriceOut.get_n(); i++)
    {
        for (int j = 0; j < MatriceOut.get_m(); j++)
            stream << MatriceOut.getpos(i, j) << ' ';
        stream << '\n';
    }
    return stream;
}

Matrice_Complexa operator+(Matrice_Complexa m1, Matrice_Complexa m2)
{
    int i, j;
    if (m1.get_m() == m2.get_m() && m1.get_n() == m2.get_n())
    {
        Matrice_Complexa result(0, m1.get_m(), m1.get_n());
        for (i = 0; i < result.get_n(); i++)
            for (j = 0; j < result.get_m(); j++)
                result.setpos(m1.getpos(i, j) + m2.getpos(i, j), i, j);
        return result;
    }
    else
    {
        throw std::invalid_argument("Matricele nu pot fi adunate");
    }
}
Matrice_Complexa operator*(Matrice_Complexa m1, Matrice_Complexa m2)
{
    if (m1.get_m() == m2.get_n())
    {
        Matrice_Complexa result(0, m2.get_m(), m1.get_n());
        for (int i = 0; i < m1.get_n(); ++i)
            for (int j = 0; j < m2.get_m(); ++j)
                for (int k = 0; k < m1.get_m(); ++k)
                {
                    result.setpos(result.getpos(i, j) + m1.getpos(i, k) * m2.getpos(k, j), i, j);
                }
        return result;
    }
    else
    {
        throw std::invalid_argument("Matricele nu pot fi inmultite");
    }
}
