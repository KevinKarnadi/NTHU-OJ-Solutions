#include <iostream>
#include <queue>
using namespace std;

int main()
{
    int capacity;
    cin >> capacity;
    deque<int> cbi;

    int N;
    cin >> N;
    for(int i=0; i<N; i++)
    {
        string cmd;
        cin >> cmd;
        if(cmd=="push_back")
        {
            int data;
            cin >> data;
            if(cbi.size() == capacity)
                cbi.pop_front();
            cbi.push_back(data);
        }
        else if(cmd=="pop_front")
        {
            cbi.pop_front();
        }
        else if(cmd=="print")
        {
            for(int j=0; j<cbi.size(); j++)
            {
                cout << cbi[j] << endl;
            }
            cout << "----" << endl;
        }
    }
    return 0;
}
