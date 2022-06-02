#include <queue>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// G[i] is the neighbor towns of town i
vector<int> diamondTowns;
vector<int> G[100005];
int Dist[100005];

struct node
{
    int id;
    int dist;
    node(int id, int l)
    {
        this->id = id;
        this->dist = l;
    }
};

int main()
{
    int N, M, K;
    cin >> N >> M >> K;
    for (int i = 0; i < M; i++)
    {
        int a, b;
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    for (int i = 0; i < K; i++)
    {
        int x;
        cin >> x;
        diamondTowns.push_back(x);
    }
    fill(Dist, Dist+100005, -1);

    deque<int> Q;

    for(int i = 0; i < K; i++)
    {
        Dist[diamondTowns[i]] = 0;
        Q.push_back(diamondTowns[i]);
    }

    while(!Q.empty())
    {
        int id = Q.front();
        Q.pop_front();
        int d = Dist[id];
        for(auto n : G[id])
        {
            if(Dist[n] == -1)
            {
                Dist[n] = d + 1;
                Q.push_back(n);
            }
        }
    }

    for (int i = 1; i <= N; i++)
    {
        cout << Dist[i] << '\n';
    }
    return 0;
}
