#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;


ull getSum(ull numAmt) {
    ull sum = (numAmt * (1 + numAmt)) / 2;
    return sum;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ull cases;
    cin >> cases;

    ull numAmt, sum;
    for (ull i = 0; i < cases; i++) {
        cin >> numAmt >> sum;
        ull expectedSum = getSum(numAmt);
        ull needed = expectedSum - sum;
        ull possiblePairs = (needed - 1) / 2;
        if (needed > numAmt) {
            possiblePairs -= ((needed - 1) - numAmt);
        }
        cout << possiblePairs << "\n";
    }

    return 0;
}
