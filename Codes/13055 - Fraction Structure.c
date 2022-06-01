typedef struct {
	long long numerator;
	long long denominator;
} Fraction;

Fraction CreateFrac(long long a, long long b)
{
    return(Fraction)
    {
        .numerator=a,
        .denominator=b
    };
}

long long GCD(long long a,long long b)
{
    if(b==0)
        return a;
    return GCD(b, a%b);
}

void Reduction(Fraction* a)
{
    long long gcd=GCD(a->numerator,a->denominator);
    a->numerator/=gcd;
    a->denominator/=gcd;
}

int Compare(Fraction a, Fraction b)
{
    a.numerator*=b.denominator;
    b.numerator*=a.denominator;
    return a.numerator > b.numerator;
}

Fraction Add(Fraction a, Fraction b)
{
    a.numerator*=b.denominator;
    b.numerator*=a.denominator;
    a.numerator+=b.numerator;
    a.denominator*=b.denominator;
    Reduction(&a);
    return a;
}

Fraction Sub(Fraction a, Fraction b)
{
    a.numerator*=b.denominator;
    b.numerator*=a.denominator;
    a.numerator-=b.numerator;
    a.denominator*=b.denominator;
    Reduction(&a);
    return a;
}

Fraction Mul(Fraction a, Fraction b)
{
    a.numerator*=b.numerator;
    a.denominator*=b.denominator;
    Reduction(&a);
    return a;
}

Fraction Div(Fraction a, Fraction b)
{
    a.numerator*=b.denominator;
    a.denominator*=b.numerator;
    Reduction(&a);
    return a;
}
