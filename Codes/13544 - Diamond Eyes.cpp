#include <iostream>
#include <vector>
using namespace std;

int a, n;

int A_Angry[125] = {0};
int A_Fearful[125] = {0};
int A_Happy[125] = {0};
int A_Sad[125] = {0};

int B_Angry[125] = {0};
int B_Fearful[125] = {0};
int B_Happy[125] = {0};
int B_Sad[125] = {0};

int bigger;

int main() {
    cin >> a >> n;
    bigger = a;
    for(int i = 0; i < n; i++) {
        int t;
        string e;
        cin >> t >> e;
        if(e == "Angry") {
            for(int j = t; j <= a; j++)
                A_Angry[j]++;
        }
        else if(e == "Fearful") {
            for(int j = t; j <= a; j++)
                A_Fearful[j]++;
        }
        else if(e == "Happy") {
            for(int j = t; j <= a; j++)
                A_Happy[j]++;
        }
        else if(e == "Sad") {
            for(int j = t; j <= a; j++)
                A_Sad[j]++;
        }
    }

    cin >> a >> n;
    if(a > bigger)
        bigger = a;
    for(int i = 0; i < n; i++) {
        int t;
        string e;
        cin >> t >> e;
        if(e == "Angry") {
            for(int j = t; j <= a; j++)
                B_Angry[j]++;
        }
        else if(e == "Fearful") {
            for(int j = t; j <= a; j++)
                B_Fearful[j]++;
        }
        else if(e == "Happy") {
            for(int j = t; j <= a; j++)
                B_Happy[j]++;
        }
        else if(e == "Sad") {
            for(int j = t; j <= a; j++)
                B_Sad[j]++;
        }
    }

    int ages[bigger + 1];
    int len = 0;
    for(int i = 0; i < bigger + 1; i++) {
        if(A_Angry[i] == B_Angry[i] &&
           A_Fearful[i] == B_Fearful[i] &&
           A_Happy[i] == B_Happy[i] &&
           A_Sad[i] == B_Sad[i])
        {
            ages[len++] = i;
        }
    }
    cout << len << "\n";
    for(int i = 0; i < len; i++) {
        cout << ages[i];
        cout << (i == len-1 ? "\n" : " ");
    }
}
