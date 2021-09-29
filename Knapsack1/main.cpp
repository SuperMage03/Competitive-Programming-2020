#include <bits/stdc++.h>
using namespace std;

int main() {
    int items, caps;
    scanf("%d %d", &items, &caps);
    size_t cost[items], value[items];
    for (int i = 0; i < items; i++) {
        scanf("%llu %llu", &cost[i], &value[i]);
    }

    size_t firstRow[caps+1];
    memset(firstRow, 0, sizeof(firstRow));
    for (int y = 1; y < items+1; y++) {
        unsigned long long curItemVal, curItemCost;
        size_t newRow[caps+1];
        for (int x = 0; x < caps+1; x++) {
            curItemCost = cost[y-1];
            curItemVal = value[y-1];
            newRow[x] = firstRow[x];

            if (curItemCost <= x) { //If the cost is fit for the current grid cost value
                long long spare = x - curItemCost;
                size_t newMax = firstRow[spare] + curItemVal;
                //cout << grid[y][spare] + curItemVal << endl;
                newRow[x] = max(newMax, newRow[x]);
            }
        }
        copy(newRow, newRow + caps + 1, firstRow);
    }
    /*
    for (int y = 0; y < items+1; y++) {
        for (unsigned int val : grid[y]) {
            cout << val << ' ';
        }
        cout << "\n";
    }
     */
    printf("%llu", firstRow[caps]);
    return 0;
}