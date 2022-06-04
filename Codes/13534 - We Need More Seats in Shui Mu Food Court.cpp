#include <iostream>
#include <cstdlib>
#include "function.h"
using namespace std;

int n, m;
int last_leave = 0;

class Group {
public:
    int people;
    int arrive;
    int leave;
    string store;
};

Group group[10005];
string store_list[10005];

template<class T>
void mySort(T arr[], int l, int r) {
    for(int i = l; i < r; i++) {
        int minidx = i;
        for(int j = i+1; j < r; j++) {
            if(arr[j].arrive < arr[minidx].arrive) {
                minidx = j;
            }
            else if(arr[j].arrive == arr[minidx].arrive) {
                if(arr[j].store < arr[minidx].store)
                    minidx = j;
            }
        }
        swap(arr[i], arr[minidx]);
    }
}

template<class T>
void mySort_name(T arr[], int l, int r) {
    for(int i = l; i < r; i++) {
        int minidx = i;
        for(int j = i+1; j < r; j++) {
            if(arr[j] < arr[minidx])
                minidx = j;
        }
        swap(arr[i], arr[minidx]);
    }
}

void solve() {
    cin >> n;
    for(int i = 0; i < n; i++) {
        int P, A, L;
        string S;
        cin >> P >> A >> L >> S;
        if(L > last_leave)
            last_leave = L;
        group[i].people = P;
        group[i].arrive = A;
        group[i].leave = L;
        group[i].store = S;
        store_list[i] = S;
    }
    mySort<Group>(group, 0, n);
    mySort_name<string>(store_list, 0, n);
    cin >> m;
    while(m--) {
        string cmd;
        cin >> cmd;
        if(cmd == "TIME_ARRIVE") {
            int K;
            cin >> K;
            cout << group[K-1].arrive << "\n";
        }
        else if(cmd == "TRAFFIC_AT") {
            int T;
            cin >> T;
            long long traffic = 0;
            for(int i = 0; i < n; i++) {
                if(group[i].arrive > T)
                    break;
                if(group[i].arrive <= T && T < group[i].leave)
                    traffic += group[i].people;
            }
            cout << traffic << "\n";
        }
        else if(cmd == "MAX_TRAFFIC") {
            int time;
            long long max_traffic = 0;
            for(int i = group[0].arrive; i < last_leave; i++) {
                long long traffic = 0;
                for(int j = 0; j < n; j++) {
                    if(group[j].arrive <= i && i < group[j].leave)
                        traffic += group[j].people;
                }
                if(traffic > max_traffic) {
                    max_traffic = traffic;
                    time = i;
                }
            }
            cout << time << " " << max_traffic << "\n";
        }
        else if(cmd == "STORE_LIST") {
            string prev = "";
            string temp[n];
            int len = 0;
            for(int i = 0; i < n; i++) {
                if(store_list[i] == prev)
                    continue;
                temp[len++] = store_list[i];
                prev = store_list[i];
            }
            for(int i = 0; i < len; i++) {
                cout << temp[i];
                cout << (i == len-1 ? "\n" : " ");
            }
        }
    }
}
