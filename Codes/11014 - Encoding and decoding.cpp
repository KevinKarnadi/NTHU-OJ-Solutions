#include <iostream>
#include <string>
#include "function.h"
using namespace std;

void RleCodec::encode()
{
    int len = code_str.length();
    char temp[len];
    int i = 0;
    int idx = 0;
    while(i < len)
    {
        char c = code_str[i];
        int cnt = 0;
        while(code_str[i] == c)
        {
            cnt++;
            i++;
        }
        if(cnt <= 2)
        {
            for(int j = 0; j < cnt; j++)
                temp[idx++] = c;
        }
        else
        {
            temp[idx++] = cnt + '0';
            temp[idx++] = c;
        }
    }
    temp[idx] = '\0';
    code_str = temp;
    encoded = true;
}

void RleCodec::decode()
{
    int len = code_str.length();
    char temp[1000];
    int idx = 0;
    int cnt = 1;
    for(int i = 0; i < len; i++)
    {
        char c = code_str[i];
        if(c >= '3' && c <= '9')
            cnt = c - '0';
        else
        {
            for(int i = 0; i < cnt; i++)
                temp[idx++] = c;
            cnt = 1;
        }
    }
    temp[idx] = '\0';
    code_str = temp;
    encoded = false;
}
