#include <iostream>
using namespace std;

int main(){
    int T;
    cin >> T;
    while(T--){
        int n, m, t;
        cin >> n >> m >> t;
        for(int i = 1; i <= n; i++){
            if(i > t-m && i <= t)
                cout << "^";
            else
                cout << "-";
        }
        cout << endl;
    }
}
