#include <bits/stdc++.h>
using namespace std;

int main() {
    int stones, steps;
    scanf("%d %d", &stones, &steps);
    int heights[stones], plsWork[stones]; plsWork[0] = 0;
    for (int i = 0; i < stones; i++) scanf("%d", &heights[i]);
    fill(plsWork + 1, plsWork + stones, INT_MAX);

    for (int y = 1; y < stones; y++) {
        for (int x = 1; x <= steps; x++) {
            int before = y - x < 0 ? 0 :  y - x;
            plsWork[y] = min(plsWork[y], abs(heights[y]-heights[before]) + plsWork[before]);
        }
    }

    printf("%d", plsWork[stones-1]);
    return 0;
}
