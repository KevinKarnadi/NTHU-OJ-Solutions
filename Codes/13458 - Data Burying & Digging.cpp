#include <iostream>
#include <stack>
#include <queue>
using namespace std;

int main() {
    int T;
    cin >> T;
    while(T--) {
        int S, B;
        cin >> S >> B;
        stack<int> layer[S];
        while(B--) {
            int spot, n;
            cin >> spot >> n;
            for(int i = 0; i < n; i++) {
                int d;
                cin >> d;
                layer[spot].push(d);
            }
        }
        int M;
        cin >> M;
        int prev = 0;
        for(int i = 0; i < M; i++) {
            int p;
            cin >> p;
            p--;
            int temp = p;
            if(i > 0)
                p -= prev;
            while(p--) {
                for(int i = 0; i < S; i++) {
                    if(!layer[i].empty())
                        layer[i].pop();
                }
            }
            for(int i = 0; i < S; i++) {
                if(layer[i].empty())
                    cout << '0';
                else
                    cout << layer[i].top();
                if(i == S - 1)
                    cout << endl;
                else
                    cout << ' ';
            }
            prev = temp;
        }
    }
}
