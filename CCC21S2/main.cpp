#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;

ull columns, rows, brushes, num;
char mode;
unordered_set<ull> brushed;

int main() {
    cin >> rows >> columns >> brushes;
    bool countingBlack[rows + 1];
    memset(countingBlack, 0, rows + 1);

    for (ull i = 0; i < brushes; i++) {
        cin >> mode >> num;
        if (mode == 'R') {
            countingBlack[num] = !countingBlack[num];
        }
        else {
            if (brushed.find(num) != brushed.end()) {
                brushed.erase(num);
            }
            else {
                brushed.insert(num);
            }
        }
    }


    ull counter = 0;
    for (ull y = 1; y < rows + 1; y++) {
        if (!countingBlack[y]) {
            counter += brushed.size();
        }
        else {
            counter += columns - (int)brushed.size();
        }
    }

    cout << counter << "\n";
    return 0;
}
