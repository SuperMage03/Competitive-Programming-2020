#include <bits/stdc++.h>
using namespace std;

struct WoodPiece {
    int left, right, width;

    int areaT2() {
        return (left + right) * width;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int woodAmt;
    cin >> woodAmt;

    WoodPiece pieces[woodAmt + 1];
    int curHeight, curWidth;
    cin >> pieces[0].left;

    for (int i = 0; i < woodAmt; i++) {
        cin >> curHeight;
        pieces[i].right = curHeight;
        pieces[i + 1].left = curHeight;
    }

    double total = 0;
    for (int i = 0; i < woodAmt; i++) {
        cin >> curWidth;
        pieces[i].width = curWidth;
        total += pieces[i].areaT2();
    }
    total /= 2;
    cout << total << "\n";

    return 0;
}
