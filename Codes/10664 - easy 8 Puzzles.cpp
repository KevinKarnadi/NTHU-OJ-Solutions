#include <iostream>
#include <vector>
#include <set>
using namespace std;

using State = vector<vector<int>>;

set<State> visited;

State goal = {{1, 2, 3}, {4, 5, 6}, {7, 8, 0}};

State swap(State s, int y, int x, int dy, int dx)
{
    int temp = s[y][x];
    s[y][x] = s[y+dy][x+dx];
    s[y+dy][x+dx] = temp;
    return s;
}

bool valid(int y, int x, int dy, int dx)
{
    if(y + dy < 0 || y + dy > 2 || x + dx < 0 || x + dx > 2)
        return false;
    else
        return true;
}

set<State> extend(State s, int y, int x)
{
    set<State> states;
    State next;
    if(valid(y, x, -1, 0))  // up
    {
        next = swap(s, y, x, -1, 0);
        if(visited.find(next) == visited.end())
        {
            states.insert(next);
        }
    }
    if(valid(y, x, 0, 1))  // right
    {
        next = swap(s, y, x, 0, 1);
        if(visited.find(next) == visited.end())
        {
            states.insert(next);
        }
    }
    if(valid(y, x, 1, 0))  // down
    {
        next = swap(s, y, x, 1, 0);
        if(visited.find(next) == visited.end())
        {
            states.insert(next);
        }
    }
    if(valid(y, x, 0, -1))  // left
    {
        next = swap(s, y, x, 0, -1);
        if(visited.find(next) == visited.end())
        {
            states.insert(next);
        }
    }
    return states;
}

bool found(State s)
{
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            if(s[i][j] != goal[i][j])
                return false;
        }
    }
    return true;
}

int main()
{
    int n;
    cin >> n;
    while(n--)
    {
        State grid;
        for(int i = 0; i < 3; i++)
        {
            vector<int> this_row;
            for(int j = 0; j < 3; j++)
            {
                int x;
                cin >> x;
                this_row.push_back(x);
            }
            grid.push_back(this_row);
        }

        if(found(grid))
        {
            cout << "You can solve it within 0 steps." << endl;
        }
        else
        {
            set<State> q;
            q.insert(grid);

            int exit = 0;
            int step = 0;
            while(!q.empty())
            {
                step++;
                if(step > 14)
                    break;

                set<State> next_states;
                set<State> todelete;
                for(auto s : q)
                {
                    visited.insert(s);

                    set<State> next;

                    int y, x;
                    for(int i = 0; i < 3; i++)
                    {
                        for(int j = 0; j < 3; j++)
                        {
                            if(s[i][j] == 0)
                            {
                                y = i;
                                x = j;
                                break;
                            }
                        }
                    }
                    next = extend(s, y, x);

                    for(auto n : next)
                    {
                        next_states.insert(n);
                        if(found(n))
                        {
                            exit = 1;
                            break;
                        }
                    }
                    if(exit)
                        break;
                    todelete.insert(s);
                }
                if(exit)
                    break;
                for(auto s : next_states)
                {
                    q.insert(s);
                }
                for(auto s : todelete)
                {
                    q.erase(s);
                }
            }
            if(step > 14)
                cout << "You'd better skip this game." << endl;
            else
                cout << "You can solve it within " << step << " steps." << endl;
            visited.clear();
        }
    }
}
