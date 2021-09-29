#include <bits/stdc++.h>
using namespace std;

int DP[5281];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    fill(DP, DP + 5281, 0x3f3f3f3f);

    int initialDist, clubAmount;
    cin >> initialDist >> clubAmount;

    int clubs[clubAmount];
    for (int &i : clubs) {
        cin >> i;
    }

    DP[initialDist] = 0;

    for (int i = initialDist; i >= 0; i--) {
        if (DP[i] == 0x3f3f3f3f) {continue;}
        for (int &club : clubs) {
            if (i - club >= 0) {
                DP[i - club] = min(DP[i - club], DP[i] + 1);
            }
        }
    }

    if (DP[0] != 0x3f3f3f3f) {
        cout << "Roberta wins in " << DP[0] << " strokes.\n";
    }
    else {
        cout << "Roberta acknowledges defeat.\n";
    }
    return 0;
}
