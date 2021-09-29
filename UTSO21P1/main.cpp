#include <bits/stdc++.h>
using namespace std;

int calcFit(int size) {
    int counter = 0;
    for (int y = 0; y < size + 1; y++) {
        for (int x = y % 2; x < size + 1; x += 2) {
            counter++;
        }
    }
    return counter;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int people;
    cin >> people;

    int fitted = 0, curSize = 0;

    while (fitted < people) {
        curSize++;
        fitted = calcFit(curSize);
    }

    cout << curSize << "\n";
    return 0;
}
