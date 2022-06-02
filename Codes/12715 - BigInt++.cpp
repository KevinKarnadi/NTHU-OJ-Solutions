#include <cstdio>
#include <cstring>
#include "function.h"
using namespace oj;

BigInt::BigInt(char *s)
{
    _val = new char[10000];
    strcpy(_val, s);
}

BigInt::~BigInt()
{
    delete _val;
}

BigInt& BigInt::operator++()  // prefix
{
    int len = strlen(_val);
    int idx = len - 1;
    for(int i = 0; i < len / 2; i++)
    {
        char temp = _val[i];
        _val[i] = _val[idx];
        _val[idx] = temp;
        idx--;
    }
    _val[0] += 1;
    for(int i = 0; i < len; i++)
    {
        if(_val[i] > '9')
        {
            _val[i] = '0';
            if(i == len - 1)
            {
                _val[i + 1] = '1';
                len++;
            }
            else
                _val[i + 1] += 1;
        }
        else
            break;
    }
    idx = len - 1;
    for(int i = 0; i < len / 2; i++)
    {
        char temp = _val[i];
        _val[i] = _val[idx];
        _val[idx] = temp;
        idx--;
    }
    _val[len] = '\0';
    return *this;
}

BigInt BigInt::operator++(int)  // postfix
{
    BigInt temp(_val);
    int len = strlen(_val);
    int idx = len - 1;
    for(int i = 0; i < len / 2; i++)
    {
        char temp = _val[i];
        _val[i] = _val[idx];
        _val[idx] = temp;
        idx--;
    }
    _val[0] += 1;
    for(int i = 0; i < len; i++)
    {
        if(_val[i] > '9')
        {
            _val[i] = '0';
            if(i == len - 1)
            {
                _val[i + 1] = '1';
                len++;
            }
            else
                _val[i + 1] += 1;
        }
        else
            break;
    }
    idx = len - 1;
    for(int i = 0; i < len / 2; i++)
    {
        char temp = _val[i];
        _val[i] = _val[idx];
        _val[idx] = temp;
        idx--;
    }
    _val[len] = '\0';
    return temp;
}

BigInt& BigInt::operator--()  // prefix
{
    int len = strlen(_val);
    if(len == 1 && _val[0] == '0')
        return *this;
    int idx = len - 1;
    for(int i = 0; i < len / 2; i++)
    {
        char temp = _val[i];
        _val[i] = _val[idx];
        _val[idx] = temp;
        idx--;
    }
    _val[0] -= 1;
    for(int i = 0; i < len; i++)
    {
        if(_val[i] < '0')
        {
            _val[i] = '9';
            if(i < len - 1)
                _val[i + 1] -= 1;
        }
        else
            break;
    }
    idx = len - 1;
    for(int i = 0; i < len / 2; i++)
    {
        char temp = _val[i];
        _val[i] = _val[idx];
        _val[idx] = temp;
        idx--;
    }
    while(_val[0] == '0')
    {
        for(int i = 0; i < len - 1; i++)
        {
            _val[i] = _val[i + 1];
        }
        len--;
    }
    _val[len] = '\0';
    return *this;
}

BigInt BigInt::operator--(int)  // postfix
{
    BigInt temp(_val);
    int len = strlen(_val);
    if(len == 1 && _val[0] == '0')
        return temp;
    int idx = len - 1;
    for(int i = 0; i < len / 2; i++)
    {
        char temp = _val[i];
        _val[i] = _val[idx];
        _val[idx] = temp;
        idx--;
    }
    _val[0] -= 1;
    for(int i = 0; i < len; i++)
    {
        if(_val[i] < '0')
        {
            _val[i] = '9';
            if(i < len - 1)
                _val[i + 1] -= 1;
        }
        else
            break;
    }
    idx = len - 1;
    for(int i = 0; i < len / 2; i++)
    {
        char temp = _val[i];
        _val[i] = _val[idx];
        _val[idx] = temp;
        idx--;
    }
    while(_val[0] == '0')
    {
        for(int i = 0; i < len - 1; i++)
        {
            _val[i] = _val[i + 1];
        }
        len--;
    }
    _val[len] = '\0';
    return temp;
}

char* BigInt::to_s()
{
    return _val;
}
