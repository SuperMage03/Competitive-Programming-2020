#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;

int main() {
    int battery, apps;
    scanf("%d %d", &battery, &apps);
    ull value[apps], cost[apps];
    char name[apps][200];
    for (int i = 0; i < apps; i++) {
        scanf("%s %llu %llu", &name[i], &value[i], &cost[i]);
    }

    ull grid[apps+1][battery+1];
    memset(grid, 0, sizeof(grid));
    for (int y = 1; y < apps + 1; y++) {
        ull curItemVal, curItemCost;
        for (int x = 0; x < battery + 1; x++) {
            curItemCost = cost[y-1];
            curItemVal = value[y-1];
            grid[y][x] = grid[y-1][x];
            if (curItemCost <= x) {
                long long spare = x - curItemCost;
                ull newMax = grid[y-1][spare] + curItemVal;
                grid[y][x] = max(newMax, grid[y][x]);
            }
        }
    }

    ull curBackTrack = grid[apps][battery];
    int batteryCounter = battery;
    ull minCost = 0;
    vector<string> appNames;
    for (int y = apps; y >= 1; y--) {
        if (curBackTrack == 0) break;
        else if (grid[y-1][battery] == curBackTrack) continue;
        else {
            minCost += cost[y-1];
            appNames.emplace_back(name[y-1]);
            batteryCounter -= cost[y-1];
            curBackTrack -= value[y-1];
        }
    }
    sort(appNames.begin(), appNames.end());


    /*
    for (int y = 0; y < apps+1; y++) {
        for (unsigned int val : grid[y]) {
            cout << val << ' ';
        }
        cout << "\n";
    }
     */

    printf("%llu %llu\n", grid[apps][battery], minCost);
    for (string appName : appNames) {cout << appName + " ";}
    cout << "\n";
    return 0;
}