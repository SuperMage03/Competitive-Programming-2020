#include <bits/stdc++.h>
typedef unsigned long long ull;
using namespace std;

const ull p = 63;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int cases; cin >> cases;

    for (int c = 0; c < cases; c++) {
        string curStr; cin >> curStr;
        unordered_set<ull> indexer;
        ull storage = 0, pow = 1, curHash;
        for (int taking = 1; taking <= curStr.length(); taking++) {
            curHash = storage * p + int(curStr[taking-1]);
            indexer.insert(curHash);
            storage = curHash;
            if (taking > 1) {pow = pow * p;}
            for (int from = 0, to = taking; to < curStr.length(); from++, to++) {
                curHash = curHash - int(curStr[from]) * pow;
                curHash = curHash * p + int(curStr[to]);
                indexer.insert(curHash);
            }
        }
        cout << indexer.size() + 1 << "\n";
    }

    return 0;
}