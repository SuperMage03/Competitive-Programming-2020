#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;

int main() {
    int items, caps;
    scanf("%d %d", &items, &caps);
    int cost[items], value[items], totalV = 0;
    for (int i = 0; i < items; i++) {
        scanf("%d %d", &cost[i], &value[i]);
        totalV += value[i];
    }

    ull firstRow[totalV+1]; firstRow[0] = 0;
    fill(firstRow + 1, firstRow+(totalV+1), 10000000000000);

    for (int y = 0; y < items; y++) {
        int curItemVal = value[y], curItemCost = cost[y];
        for (int x = totalV; x >= curItemVal; x--) {
            int spare = x - curItemVal;
            firstRow[x] = min(firstRow[x], firstRow[spare] + curItemCost);
        }
    }

    for (int x = totalV; x >= 0; x--) {
        if (firstRow[x] <= caps) {
            printf("%d\n", x);
            return 0;
        }
    }


    return 0;
}