#include <bits/stdc++.h>
using namespace std;

int grid[100005][3], mem[100005][3];

int vacationFunc(int x, int y, int height, int last) {
    if (y == height) return 0;
    else if (mem[y][x] != -1) return mem[y][x];

    int counter = 0;
    for (int abc = 0; abc < 3; abc++) {
        if (abc == last) continue;
        counter = max(counter, grid[y][x] + vacationFunc(abc, y+1, height, abc));
    }
    mem[y][x] = counter;
    return mem[y][x];
}

int vacation(int height) {
    int max1 = vacationFunc(0,0, height,0);
    int max2 = max(vacationFunc(1, 0, height, 1), vacationFunc(2, 0, height, 2));
    return max(max1, max2);
}

int main() {
    int days; scanf("%d", &days);
    memset(mem, -1, sizeof(mem));
    for (int i = 0; i < days; i++) {
        scanf("%d %d %d", &grid[i][0], &grid[i][1], &grid[i][2]);
    }
    printf("%d\n", vacation(days));
    return 0;
}
