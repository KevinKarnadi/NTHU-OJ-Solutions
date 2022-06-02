#include<iostream>
#include<string>

using namespace std;
class special_power
{
public:
    int n;
    special_power(int n);
    int fpow(int x);
    int fpow(int x, int m);
    int fpow();
    string fpow(string s);
    string fpow(string s, int m);
};


special_power::special_power(int n)
{
    this->n=n;
}
int special_power::fpow(int x)
{
    long long a=1;
    for(int i=0; i<this->n; i++)
    {
        a*=x;
        a%=880301;
    }
    return a;
}
int special_power::fpow(int x, int m)
{
    long long a=1;
    for(int i=0; i<this->n; i++)
    {
        a*=x;
        a%=m;
    }
    return a;
}
int special_power::fpow()
{
    long long a=1;
    for(int i=0; i<this->n; i++)
    {
        a*=2;
        a%=880301;
    }
    return a;
}
string special_power::fpow(string s)
{
    string a;
    int len=s.length();
    for(int i=0; i<len; i++)
    {
        for(int j=0; j<this->n; j++)
        {
            a+=s[i];
        }
    }
    return a;
}
string special_power::fpow(string s, int m)
{
    string a;
    int len=s.length();
    int idx = 0;
    for(int i=0; i<len; i++)
    {
        for(int j=0; j<this->n; j++)
        {
            a+=s[i];
            idx++;
            if(idx == m)
                return a;
        }
    }
    return a;
}
