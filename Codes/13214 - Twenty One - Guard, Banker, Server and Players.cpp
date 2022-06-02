#include <iostream>
#include <sstream>
#include <cstring>
#include "function.h"
using namespace std;

int win;

Human::Human(string n, int m, int ski)
{
    name = n;
    money = m;
    skill = ski;
    bets = 0;
    cards = 0;
}

Human::~Human()
{
}

void Human::Draw()
{
    this->cards = 0;
    string res = "";
    while (res.size() <= 0)
        getline(cin, res);
    stringstream ss(res);
    while (ss >> res)
    {
        int temp = 0;
        for (auto i : res)
            temp = temp * 10 + i - '0';
        this->cards += temp;
    }
}

Guard::Guard(int ski) : Human::Human("Guard", 0, ski)
{
}

void Guard::Pay(Human *human)
{
    int pay = human->skill - this->skill;
    human->money += pay;
    this->money -= pay;
}

Banker::Banker(int ski) : Human::Human("Banker", 0, ski)
{
}

void Banker::Pay(Human *human)
{
    if(human->name == "Guard")
    {
        human->money += 100;
        this->money -= 100;
    }
    else
    {
        win = 0;
        win += human->bets;
        if(human->skill < this->skill)
            win += (10 * human->cards);
        if(human->cards == 21)
            win *= 2;
        human->money += win;
        this->money -= win;
    }
}

int Banker::Win(Human *human)
{
    int A = human->cards;
    int B = this->cards;
    if(A <= 21 && (B > 21 || A > B))
        return 0;
    else if(B <= 21 && (A > 21 || B >= A))
        return 1;
    else if(A > 21 && B > 21)
        return 2;
}

Server::Server(int ski) : Human::Human("Server", 0, ski)
{
}

Player::Player(string name, int m, int ski) : Human::Human(name, m, ski)
{
}

Player::~Player()
{
}

void Player::Pay(Human *human)
{
    if(this->bets >= this->money)
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
    int bet;
    cin >> bet;
    this->bets = bet;
    cin.ignore();
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
    if(win > 3 * this->skill)
        return true;
    else
        return false;
}

void Player::Order(Human *banker, Human *server)
{
    banker->money += 2000;
    server->money += 1000;
    this->money -= 3000;
}

Casino::Casino()
{
    int player_num = 0;
    int total_income = 0;
    int today_income = 0;
    int blacklist_num = 0;
}

Casino::~Casino()
{
    delete banker;
    delete guard;
    delete server;
    delete [] player;
}

void Casino::Enterance(int f, int u)
{
    this->fee = f;
    this->U = u;
}

void Casino::Guest(string s, int m, int ski)
{
    for(int i = 0; i < blacklist_num; i++)
    {
        if(blacklist[i] == s)
            return;
    }
    for(int i = 0; i < player_num; i++)
    {
        if(player[i]->name == s)
            return;
    }
    if(fee >= m)
    {
        blacklist[blacklist_num++] = s;
    }
    else
    {
        today_income += fee;
        player[player_num++] = new Player(s, m - fee, ski);
    }
}

void Casino::TwentyOne()
{
    int banker_ski, guard_ski, server_ski;
    cin >> banker_ski >> guard_ski >> server_ski;
    banker = new Banker(banker_ski);
    guard = new Guard(guard_ski);
    server = new Server(server_ski);
    int k;
    cin >> k;
    string n;
    int record[1009];
    for(int i = 0; i < 1009; i++)
        record[i] = 0;
    for(int i = 0; i < k; i++)
    {
        cin >> n;
        int flag = 1;
        Player* new_player = new Player(n, 0, 0);
        new_player->Bet();
        new_player->Draw();

        for(int j = 0; j < this->blacklist_num; j++)
        {
            if(this->blacklist[j] == n)
            {
                flag = 0;
                break;
            }
        }
        if(flag)
        {
            for(int j = 0; j < this->player_num; j++)
            {
                if(this->player[j]->name == n)
                {
                    record[j] = 1;
                    this->player[j]->bets = new_player->bets;
                    this->player[j]->cards = new_player->cards;
                }
            }
        }
        delete new_player;
    }
    this->banker->Draw();

    for(int i = 0; i < this->player_num; i++)
    {
        if(record[i] == 1)
        {
            if(banker->Win(player[i]) == 1)
            {
                player[i]->Pay(banker);
                if(player[i]->Bankrupt())
                {
                    banker->Pay(guard);
                    blacklist[blacklist_num++] = player[i]->name;
                }
            }
            else if(banker->Win(player[i]) == 0)
            {
                banker->Pay(player[i]);
                if(player[i]->Cheat(banker))
                {
                    banker->Pay(guard);
                    blacklist[blacklist_num++] = player[i]->name;
                    if(player[i]->skill > guard->skill)
                        guard->Pay(player[i]);
                }
                if(player[i]->money > server->skill)
                    player[i]->Order(banker, server);
                if(player[i]->Bankrupt())
                {
                    banker->Pay(guard);
                    blacklist[blacklist_num++] = player[i]->name;
                }
            }
        }
    }

    cout << banker->money << " " << guard->money << " " << server->money << endl;
    for(int i = 0; i < player_num; i++)
    {
        if(record[i] == 1)
            cout << player[i]->name << " " << player[i]->money << endl;
    }
    today_income += banker->money;
    banker->money = 0;
}

void Casino::EndDay()
{
    player_num = 0;
    if(today_income >= U)
        blacklist_num = 0;
    total_income += today_income;
    today_income = 0;
}

void Casino::Result()
{
    cout << total_income << endl;
    for(int i = 0; i < blacklist_num; i++)
        cout << blacklist[i] << endl;
}
