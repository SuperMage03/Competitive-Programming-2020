#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie();

    int quarters, machine[3];
    cin >> quarters >> machine[0] >> machine[1] >> machine[2];

    int curM = 0, played = 0;
    while (quarters != 0) {
        quarters--;
        played++;
        machine[curM]++;
        if (curM == 0 && machine[curM] % 35 == 0) {
            quarters += 30;
        }
        else if (curM == 1 && machine[curM] % 100 == 0) {
            quarters += 60;
        }
        else if (curM == 2 && machine[curM] % 10 == 0) {
            quarters += 9;
        }
        curM = (curM + 1) % 3;
    }

    cout << "Martha plays " << played << " times before going broke." << "\n";
    return 0;
}
