#include <bits/stdc++.h>
using namespace std;

vector<double> rivers;

int main() {
    int initialRivers;
    cin >> initialRivers;

    for (int i = 0; i < initialRivers; i++) {
        double flow;
        cin >> flow;
        rivers.push_back(flow);
    }

    int mode;
    while (true) {
        cin >> mode;
        if (mode == 77) {break;}
        else if (mode == 99) {
            int number;
            double leftPercent;
            cin >> number >> leftPercent;

            double newRiver = rivers[number - 1] * ((100 - leftPercent) / 100);
            rivers[number - 1] = rivers[number - 1] * (leftPercent / 100);
            rivers.insert(rivers.begin(), number, newRiver);
        }
        else {
            int number;
            cin >> number;
            rivers[number - 1] += rivers[number];
            rivers.erase(rivers.begin() + number);
        }

    }

    for (double &opt : rivers) {
        cout << round(opt) << " ";
    }
    cout << "\n";

    return 0;
}
