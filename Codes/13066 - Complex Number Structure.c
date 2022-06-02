typedef struct
{
    long long real;
    long long imag;
} Complex;

Complex CreateComplex(long long a, long long b)
{
    return(Complex)
    {
        .real=a,
        .imag=b
    };
}

Complex Add(Complex a, Complex b)
{
    a.real+=b.real;
    a.imag+=b.imag;
    return a;
}

Complex Sub(Complex a, Complex b)
{
    a.real-=b.real;
    a.imag-=b.imag;
    return a;
}

Complex Mul(Complex a, Complex b)
{
    Complex c;
    c.real=(a.real*b.real)-(a.imag*b.imag);
    c.imag=(a.real*b.imag)+(a.imag*b.real);
    return c;
}

void Compare(Complex* a, Complex* b)
{
    long long xa=(a->imag*a->imag)+(a->real*a->real);
    long long xb=(b->imag*b->imag)+(b->real*b->real);
    if(xa<xb)
    {
        Complex temp=*a;
        *a=*b;
        *b=temp;
    }
}
