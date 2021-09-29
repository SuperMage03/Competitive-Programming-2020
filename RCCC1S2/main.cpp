#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
typedef unsigned long long ull;

ull numbers[1500], totalPairs = 0;

struct DS {
    int pairs = 0;
    gp_hash_table<int, int> freqArr;
};

unordered_map<ull, DS> products;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int numAmt;
    cin >> numAmt;

    for (int i = 0; i < numAmt; i++) {
        cin >> numbers[i];
    }

    for (int i = 0; i < numAmt; i++) {
        for (int j = i + 1; j < numAmt; j++) {
            ull prod = numbers[i] * numbers[j];
            products[prod].pairs++;
            products[prod].freqArr[i]++;
            products[prod].freqArr[j]++;
        }
    }

    for (int i = 0; i < numAmt; i++) {
        for (int j = i + 1; j < numAmt; j++) {
            ull prod = numbers[i] * numbers[j];
            totalPairs += products[prod].pairs - 1;
            totalPairs -= products[prod].freqArr[i] - 1;
            totalPairs -= products[prod].freqArr[j] - 1;
        }
    }

    cout << totalPairs * 4 << "\n";

    return 0;
}