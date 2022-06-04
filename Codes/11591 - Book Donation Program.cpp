#include <iostream>
#include <cmath>
using namespace std;

bool isPrime(int x){
    if(x <= 1)
        return false;
    for(int i = 2; i <= sqrt(x); i++)
        if(x % i == 0)
            return false;
    return true;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while(T--){
        int x, n;
        cin >> x >> n;
        int ctr = 0;
        int num;
        for(num = x; ; num++){
            if(isPrime(num))
                ctr++;
            if(ctr == n)
                break;
        }
        cout << num << endl;
    }
}
