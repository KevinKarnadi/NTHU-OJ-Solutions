#include<iostream>
#include<stdio.h>
#include<string>
using namespace std;

class big_number
{
public:
    big_number(string num);
    string num;
    bool multiple_of_two();
    bool multiple_of_three();
    bool multiple_of_four();
    bool multiple_of_five();
    bool multiple_of_six();
    bool multiple_of_eight();
    bool multiple_of_nine();
    bool multiple_of_ten();
    bool multiple_of_eleven();
};

big_number::big_number(string num)
{
    this->num = num;
}

bool big_number::multiple_of_two()
{
    int len = num.length();
    if((num[len - 1] - '0') % 2 == 0)
        return true;
    else
        return false;
}

bool big_number::multiple_of_three()
{
    int len = num.length();
    unsigned long long sum = 0;
    for(int i = 0; i <= len - 1; i++)
        sum += (num[i] - '0');
    if(sum % 3 == 0)
        return true;
    else
        return false;
}

bool big_number::multiple_of_four()
{
    int len = num.length();
    unsigned long long sum = 0;
    for(int i = len - 2; i <= len - 1; i++)
    {
        if(i < 0)
            continue;
        sum = (sum * 10) + (num[i] - '0');
    }
    if(sum % 4 == 0)
        return true;
    else
        return false;
}

bool big_number::multiple_of_five()
{
    int len = num.length();
    if(num[len - 1] == '0' || num[len - 1] == '5')
        return true;
    else
        return false;
}

bool big_number::multiple_of_six()
{
    if(multiple_of_two() && multiple_of_three())
        return true;
    else
        return false;
}

bool big_number::multiple_of_eight()
{
    int len = num.length();
    unsigned long long sum = 0;
    for(int i = len - 3; i <= len - 1; i++)
    {
        if(i < 0)
            continue;
        sum = (sum * 10) + (num[i] - '0');
    }
    if(sum % 8 == 0)
        return true;
    else
        return false;
}

bool big_number::multiple_of_nine()
{
    int len = num.length();
    unsigned long long sum = 0;
    for(int i = 0; i <= len - 1; i++)
        sum += (num[i] - '0');
    if(sum % 9 == 0)
        return true;
    else
        return false;
}

bool big_number::multiple_of_ten()
{
    int len = num.length();
    if(num[len - 1] == '0')
        return true;
    else
        return false;
}

bool big_number::multiple_of_eleven()
{
    int len = num.length();
    long long sum = 0;
    int op;
    if(len % 2 == 0)
        op = 1;
    else
        op = 2;
    for(int i = 0; i <= len - 1; i++)
    {
        if(op == 1)
        {
            sum += (num[i] - '0');
            op = 2;
        }
        else
        {
            sum -= (num[i] - '0');
            op = 1;
        }
    }
    if(sum % 11 == 0)
        return true;
    else
        return false;
}
