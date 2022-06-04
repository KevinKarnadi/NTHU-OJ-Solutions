#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    priority_queue<int> room;
    vector<int> available;
    for(int i = 0; i < n; i++) {
        room.push(i);
        available.push_back(1);
    }

    int m;
    int avail = n;
    cin >> m;
    while(m--) {
        string cmd;
        int k;
        cin >> cmd >> k;
        if(cmd == "RESERVE") {
            if(avail < k)
                cout << "RESERVE: no vacant rooms" << "\n";
            else {
                cout << "RESERVE: reserve room ";
                for(int i = 0; i < k; i++) {
                    int roomNum = room.top();
                    cout << roomNum;
                    if(i != k-1)
                        cout << ",";
                    available[roomNum] = 0;
                    room.pop();
                    avail--;
                }
                cout << "\n";
            }
        }
        else if(cmd == "UNRESERVE") {
            if(k >= n)
                cout << "UNRESERVE: " << k << " has not been reserved" << "\n";
            else if(available[k] == 0) {
                available[k] = 1;
                room.push(k);
                avail++;
                cout << "UNRESERVE: unreserved room " << k << "\n";
            }
            else
                cout << "UNRESERVE: " << k << " has not been reserved" << "\n";
        }
    }
}
