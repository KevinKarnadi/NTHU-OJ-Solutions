#include "function.h"
#include <stack>

using std::stack;

void Crossing::solve()
{
    stack<State> state_stack;
    State now_state;
    set<State> next_states;
    list<State> now_path;

    int min_sz = NULL;

    this->_npeople.emplace_back(0);
    this->_npeople.emplace_back(0);
    this->_npeople.emplace_back(1);
    state_stack.emplace(this->_npeople);

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
            if(min_sz == NULL || now_path.size() < min_sz)
                min_sz = now_path.size();
        }
        else
        {
            next_states = extend(now_state);
            for(State itr : next_states)
            {
                if(valid(itr))
                    state_stack.emplace(itr);
            }
        }
    }

    for(auto sol : this->_solutions)
    {
        if(sol.size() > min_sz)
            this->_solutions.erase(sol);
    }
}

set<State> Crossing::extend(State s)
{
    return set<State>({Go(s, 0, 1),
                       Go(s, 1, 0),
                       Go(s, 1, 1),
                       Go(s, 2, 0),
                       Go(s, 0, 2)});
}

State Crossing::Go(State s, int missionary, int cannibal)
{
    if (s[4] == 1)
    {
        s[0] -= missionary;
        s[1] -= cannibal;
        s[2] += missionary;
        s[3] += cannibal;
        s[4] = -(s[4]);
    }
    else if (s[4] == -1)
    {
        s[0] += missionary;
        s[1] += cannibal;
        s[2] -= missionary;
        s[3] -= cannibal;
        s[4] = -(s[4]);
    }
    return s;
}

bool Crossing::valid(State s)
{
    if (this->_explored.find(s) != this->_explored.end())
        return false;
    else if (s[0] < 0 || s[1] < 0 || s[2] < 0 || s[3] < 0)
        return false;
    else if (s[0] != 0 && s[0] < s[1])
        return false;
    else if (s[2] != 0 && s[2] < s[3])
        return false;
    else
        return true;
}

bool Crossing::found(State s)
{
    if (s[0] == 0 && s[1] == 0)
        return true;
    else
        return false;
}
