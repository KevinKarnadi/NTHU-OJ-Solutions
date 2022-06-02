#include <iostream>
#include <queue>
#include <set>
using namespace std;

int maxlvl, maxhp, mhp, mdmg;
int dmg[16], hl[16];

typedef struct State
{
    int lvl, hp, mhp;
    int dist;
    State(int lvl, int hp, int mhp) : lvl(lvl), hp(hp), mhp(mhp), dist(0) {}
} State;

bool visited[16][301][401];

State lvlup(State s)
{
    s.lvl += 1;
    s.dist += 1;
    return s;
}

State atk(State s)
{
    s.mhp -= dmg[s.lvl];
    s.dist += 1;
    return s;
}

State heal(State s)
{
    s.hp += hl[s.lvl];
    if(s.hp > maxhp)
        s.hp = maxhp;
    s.dist += 1;
    return s;
}

bool valid(State s)
{
    if(s.lvl > maxlvl)
        return false;
    else
        return true;
}

int main()
{
    cin >> maxlvl >> maxhp >> mhp >> mdmg;
    for(int i = 1; i <= maxlvl; i++)
    {
        cin >> dmg[i] >> hl[i];
    }

    queue<State> q;
    q.push(State(1, maxhp, mhp));

    while(!q.empty())
    {
        State now = q.front();
        if(visited[now.lvl][now.hp][now.mhp])
        {
            q.pop();
            continue;
        }
        visited[now.lvl][now.hp][now.mhp] = true;

        if(now.mhp <= 0)
            break;

        if(now.dist > 0)
        {
            now.hp -= mdmg;
            if(now.hp <= 0)
            {
                q.pop();
                continue;
            }
        }

        q.pop();

        State next = lvlup(now);
        if(valid(next))
            q.push(next);

        next = atk(now);
        if(valid(next))
            q.push(next);

        next = heal(now);
        if(valid(next))
            q.push(next);
    }

    if(q.empty())
        cout << -1 << endl;
    else
        cout << q.front().dist << endl;
}
