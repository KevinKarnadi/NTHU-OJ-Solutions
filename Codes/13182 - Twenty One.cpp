#include <iostream>
#include <string>
#include "function.h"
using namespace std;

Guest::Guest()
{
}

Guest::Guest(string s, int m, int ski)
{
    name = s;
    money = m;
    skill = ski;
}

Guest::~Guest()
{
}

string Guest::get_name()
{
    return name;
}

int Guest::get_money()
{
    return money;
}

int Guest::get_skill()
{
    return skill;
}

void Guest::Win(int m)
{
    money += m;
}

Casino::Casino()
{
}

Casino::~Casino()
{
}

void Casino::Enterance(int f)
{
    fee = f;
}

void Casino::GuestEnter(string s, int m, int ski)
{
    for(int i = 0; i < list_num; i++)
    {
        if(blacklist[i] == s)
            return;
    }
    for(int i = 0; i < guest_num; i++)
    {
        if(guest[i]->get_name() == s)
            return;
    }
    if(m <= fee)
    {
        income += m;
        blacklist[list_num++] = s;
    }
    else
    {
        guest[guest_num++] = new Guest(s, m, ski);
        guest[guest_num - 1]->Win(-fee);
        income += fee;
    }
}

void Casino::Win(string s, int m)
{
    int i;
    for(i = 0; i < list_num; i++)
    {
        if(blacklist[i] == s)
            return;
    }
    for(i = 0; i < guest_num; i++)
    {
        if(guest[i]->get_name() == s)
            break;
    }
    if(i == guest_num)
        return;
    if(guest[i]->get_money() + m > 0)
    {
        income -= m;
        if(m > 2 * guest[i]->get_skill())
            blacklist[list_num++] = guest[i]->get_name();
    }
    else
    {
        income += guest[i]->get_money();
        blacklist[list_num++] = guest[i]->get_name();
    }
    guest[i]->Win(m);
}

void Casino::EndDay()
{
    guest_num = 0;
}

void Casino::Result()
{
    cout << income << endl;
    for(int i = 0; i < list_num; i++)
        cout << blacklist[i] << endl;
}
