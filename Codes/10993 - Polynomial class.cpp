#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;

class Polynomial
{
public:
    Polynomial();
    Polynomial(const int , const int [51]);
    Polynomial add( const Polynomial) const; // add function
    Polynomial subtract( const Polynomial ) const; // subtract function
    Polynomial multiplication( const Polynomial ) const; // multiplication function
    void output() const;
private:
    int coefficients[101]; // integer coefficients
    int greatestPower; // integer greatestPower
}; // end class Polynomial

Polynomial::Polynomial()
{
}

Polynomial::Polynomial(const int gp, const int c[51])
{
    greatestPower = gp;
    for(int i = gp; i >= 0; i--)
        coefficients[i] = c[i];
}

Polynomial Polynomial::add(const Polynomial b) const
{
    Polynomial a = *this;
    int gp;
    if(a.greatestPower > b.greatestPower)
        gp = a.greatestPower;
    else
        gp = b.greatestPower;
    for(int i = gp; i >= 0; i--)
    {
        if(i > a.greatestPower)
            a.coefficients[i] = 0;
        if(i <= b.greatestPower)
            a.coefficients[i] += b.coefficients[i];
    }
    a.greatestPower = gp;
    return a;
}

Polynomial Polynomial::subtract(const Polynomial b) const
{
    Polynomial a = *this;
    int gp;
    if(a.greatestPower > b.greatestPower)
        gp = a.greatestPower;
    else
        gp = b.greatestPower;
    for(int i = gp; i >= 0; i--)
    {
        if(i > a.greatestPower)
            a.coefficients[i] = 0;
        if(i <= b.greatestPower)
            a.coefficients[i] -= b.coefficients[i];
    }
    a.greatestPower = gp;
    return a;
}

Polynomial Polynomial::multiplication(const Polynomial b) const
{
    Polynomial a = *this;
    int gp = a.greatestPower + b.greatestPower;
    int c[gp + 1] = {0};
    for(int i = a.greatestPower; i >= 0; i--)
        for(int j = b.greatestPower; j >= 0; j--)
            c[i + j] += a.coefficients[i] * b.coefficients[j];
    for(int i = gp; i >= 0; i--)
        a.coefficients[i] = c[i];
    a.greatestPower = gp;
    return a;
}

void Polynomial::output() const
{
    for(int i = greatestPower; i >= 1; i--)
        cout << coefficients[i] << ' ';
    cout << coefficients[0];
}
