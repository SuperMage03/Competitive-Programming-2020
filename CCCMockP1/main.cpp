#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int a, counter = 0;
    cin >> a;
    while (a != 0) {
        if (a & 1) {
            counter++;
        }
        a = a >> 1;
    }
    cout << counter << "\n";

    string x;
    cin >> x;
    int toDec = 0, curPower = 1;

    for (int i = x.length() - 1; i >= 0; i--) {
        if (x.at(i) == '1') {
            toDec += curPower;
        }
        curPower *= 2;
    }
    cout << toDec << "\n";

    return 0;
}
