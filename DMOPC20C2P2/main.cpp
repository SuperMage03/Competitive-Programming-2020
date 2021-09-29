#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second


pair<int, int> colourIndex[1000005];

int main() {
    cin.sync_with_stdio(false);
    cin.tie(nullptr);

    int ans = 0;

    int length, requests;
    cin >> length >> requests;


    for (int i = 1; i < length + 1; i++) {
        int curCol;
        cin >> curCol;
        if (colourIndex[curCol].f == 0) {
            colourIndex[curCol].f = i;
            colourIndex[curCol].s = i;
        }
        else {
            colourIndex[curCol].s = i;
        }
    }

    for (int i = 0; i < requests; i++) {
        int from, to;
        cin >> from >> to;
        int minVal = colourIndex[from].f;
        int maxVal = colourIndex[to].s;
        if (minVal != 0 && maxVal != 0) {
            if (maxVal - minVal >= 0) {
                ans = max(ans, maxVal - minVal + 1);
            }
        }
    }

    cout << ans << "\n";

    return 0;
}
