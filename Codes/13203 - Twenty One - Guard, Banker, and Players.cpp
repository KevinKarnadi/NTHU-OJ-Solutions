#include <iostream>
#include <cstring>
#include <string>
#include "function.h"
using namespace std;

int win;

Human::Human(string n, int m, int ski)
{
    name = n;
    money = m;
    skill = ski;
    kicked = false;
    cards = 0;
    bets = 0;
}

int Human::get_money()
{
    return this->money;
}

Guard::Guard(int ski) : Human("Guard", 0, ski) {}

void Guard::Pay(Human *human)
{
    int pay = human->skill - this->skill;
    this->money -= pay;
    human->money += pay;
}

void Guard::Kick(Human *human, int flag)
{
    human->kicked = true;
    if(flag == 1)  // cheat
    {
        if(this->skill < human->skill)
            this->Pay(human);
    }
}

Banker::Banker(int ski) : Human("Banker", 0, ski) {}

void Banker::Pay(Human *human)
{
    if(human->name == "Guard")
    {
        this->money -= 100;
        human->money += 100;
    }
    else
    {
        win = 0;
        win += human->bets;
        if(human->skill < this->skill)
            win += (10 * human->cards);
        if(human->cards == 21)
            win *= 2;
        this->money -= win;
        human->money += win;
    }
}

int Banker::Win(Human *human)
{
    int A = human->cards;
    int B = this->cards;
    if(A > 21 && B > 21)
        return 2;
    else if(A <= 21 && (A > B || B > 21))
        return 0;
    else if(B <= 21 && (A > 21 || B >= A))
        return 1;
}

void Banker::Draw()
{
    string s;
    getline(cin, s);
    int sum = 0;
    int idx = 0;
    int num = 0;
    while(s[idx] != '\0')
    {
        if(isdigit(s[idx]))
            num = num * 10 + (s[idx] - '0');
        else
        {
            sum += num;
            num = 0;
        }
        idx++;
    }
    sum += num;
    this->cards = sum;
}

Player::Player(string name, int m, int ski) : Human(name, m, ski) {}

void Player::Pay(Human *human)
{
    if(this->money <= this->bets)
    {
        human->money += this->money;
        this->money = 0;
    }
    else
    {
        human->money += this->bets;
        this->money -= this->bets;
    }
}

void Player::Bet()
{
    string temp;
    cin >> temp;
    int bet;
    cin >> bet;
    this->bets = bet;
    cin.ignore();
}

void Player::Draw()
{
    string s;
    getline(cin, s);
    int sum = 0;
    int idx = 0;
    int num = 0;
    while(s[idx] != '\0')
    {
        if(isdigit(s[idx]))
            num = num * 10 + (s[idx] - '0');
        else
        {
            sum += num;
            num = 0;
        }
        idx++;
    }
    sum += num;
    this->cards = sum;
}

bool Player::Kicked()
{
    return this->kicked;
}

bool Player::Bankrupt()
{
    if(this->money <= 0)
        return true;
    else
        return false;
}

bool Player::Cheat(Human *human)
{
    if(win > 2 * this->skill)
        return true;
    else
        return false;
}
