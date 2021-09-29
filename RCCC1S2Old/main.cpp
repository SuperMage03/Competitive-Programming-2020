#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;

ull numbers[1505];
unordered_map<ull, int> products;
vector<pair<int, int>> pairs;
unordered_set<int> tracker[1505], t;


ull factorial(ull num) {
    long double fact;
    fact = sqrtl(M_PI) * powl(num / M_E, num);
    fact *= powl(((8  * num + 4) * num + 1) * num + (long double)1 / 30, (long double)1 / 6);

    ull k = floorl(fact);
    ull g = k % 1000000000;

    return g;
}

ull combination(ull n, ull r) {
    return factorial(n) / (factorial(r) * factorial(n - r));
}

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
            products[prod]++;
            pairs.emplace_back(i, j);
        }
    }

    ull totalPairs = 0;
    for (auto &curPairs : pairs) {
        ull prod = numbers[curPairs.first] * numbers[curPairs.second];
        if (tracker[curPairs.first].find(curPairs.second) != tracker[curPairs.first].end() ||
            tracker[curPairs.second].find(curPairs.first) != tracker[curPairs.second].end()) {
            totalPairs--;
        }
        else {
            if (t.find(prod) == t.end() && products[prod] >= 2) {
                totalPairs += combination(products[prod], 2);
                t.insert(prod);
                cout << products[prod] << endl;
            }
        }

        tracker[curPairs.first].insert(curPairs.second);
        tracker[curPairs.second].insert(curPairs.first);
    }



    cout << totalPairs * 8 << "\n";
    return 0;
}