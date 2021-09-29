#include <bits/stdc++.h>
using namespace std;

struct DS {
    int mass, index, DB;
};

int main() {
    int T;
    cin >> T;

    DS person[T];
    for (int i = 0; i < T; i++) {
        cin >> person[i].mass >> person[i].index >> person[i].DB;
    }

    int maxW;
    cin >> maxW;

    int firstRow[maxW + 1];
    memset(firstRow, 0, sizeof(firstRow));

    for (int y = 1; y < T + 1; y++) {
        int curV, curW, newRow[maxW + 1];
        for (int x = 0; x < maxW + 1; x++) {
            curV = person[y - 1].DB;
            curW = person[y - 1].mass;
            newRow[x] = firstRow[x];
            if (curW <= x) {
                int spare = x - curW;
                int newMax = firstRow[spare] + curV;
                newRow[x] = max(newMax, newRow[x]);
            }
        }
        copy(newRow, newRow + (maxW + 1), firstRow);
    }

    cout << firstRow[maxW] << "\n";
    return 0;
}
