#include "function.h"
#include <stack>

using std::stack;

void Crossing::solve()
{
    stack<State> state_stack;
    State now_state;
    set<State> next_state;
    list<State> now_path;

    this->_items.emplace_back(0);
    this->_items.emplace_back(0);
    this->_items.emplace_back(0);
    this->_items.emplace_back(1);
    state_stack.emplace(this->_items);

    while(!state_stack.empty())
    {
        now_state = state_stack.top();

        if(this->_explored.find(now_state) != this->_explored.end())
        {
            this->_explored.erase(now_state);
            state_stack.pop();
            now_path.pop_back();
            continue;
        }

        this->_explored.emplace(now_state);
        now_path.emplace_back(now_state);

        if(found(now_state))
        {
            this->_solutions.emplace(now_path);
        }
        else
        {
            next_state = extend(now_state);
            for(State s : next_state)
            {
                if(valid(s))
                    state_stack.emplace(s);
            }
        }
    }
}

set<State> Crossing::extend(State s)
{
    return set<State>({Go(s, 0, 0, 0),
                       Go(s, 1, 0, 0),
                       Go(s, 0, 1, 0),
                       Go(s, 0, 0, 1)});
}

State Crossing::Go(State s, int wolf, int goat, int cabbage)
{
    if(s[6] == 1)  // left
    {
        s[0] -= wolf;
        s[1] -= goat;
        s[2] -= cabbage;
        s[3] += wolf;
        s[4] += goat;
        s[5] += cabbage;
        s[6] = -(s[6]);
    }
    else  // right
    {
        s[0] += wolf;
        s[1] += goat;
        s[2] += cabbage;
        s[3] -= wolf;
        s[4] -= goat;
        s[5] -= cabbage;
        s[6] = -(s[6]);
    }
    return s;
}

bool Crossing::valid(State s)
{
    if(this->_explored.find(s) != this->_explored.end())
        return false;
    else if(s[0] < 0 || s[1] < 0 || s[2] < 0 || s[3] < 0 || s[4] < 0 || s[5] < 0)
        return false;
    else if((s[6] == -1 && s[1] != 0 && s[0] > s[1]) || (s[6] == 1 && s[4] != 0 && s[3] > s[4]))
        return false;
    else if((s[6] == -1 && s[2] != 0 && s[1] > s[2]) || (s[6] == 1 && s[5] != 0 && s[4] > s[5]))
        return false;
    else
        return true;
}

bool Crossing::found(State s)
{
    if(s[0] == 0 && s[1] == 0 && s[2] == 0)
        return true;
    else
        return false;
}
