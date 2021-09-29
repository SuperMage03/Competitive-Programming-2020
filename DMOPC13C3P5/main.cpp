#include <bits/stdc++.h>
using namespace std;

int main() {
    int maxTime, maxFood, rAmount;
    scanf("%d %d %d", &maxTime, &maxFood, &rAmount);
    int impV[rAmount], times[rAmount], food[rAmount];
    for (int i = 0; i < rAmount; i++) {
        scanf("%d %d %d", &impV[i], &times[i], &food[i]);
    }
    int curRow[maxTime + 1][maxFood + 1], newRow[maxTime + 1][maxFood + 1];
    memset(curRow, 0, sizeof(curRow));
    int curItemVal, curItemTime, curItemFood;
    for (int z = 1; z < rAmount + 1; z++) {
        curItemFood = food[z - 1];
        curItemTime = times[z - 1];
        curItemVal  = impV[z - 1];
        for (int y = 0; y < maxTime + 1; y++) {
            for (int x = 0; x < maxFood + 1; x++) {
                if (curItemFood <= x && curItemTime <= y) {
                    int spareTime = y - curItemTime;
                    int spareFood = x - curItemFood;
                    int newMax = curRow[spareTime][spareFood] + curItemVal;
                    newRow[y][x] = max(newMax, curRow[y][x]);
                }
                else {
                    newRow[y][x] = curRow[y][x];
                }
            }
        }
        for (int j = 0; j < maxTime + 1; j++) {
            for (int i = 0; i < maxFood + 1; i++){
                curRow[j][i] = newRow[j][i];
            }
        }
    }
    printf("%d\n", curRow[maxTime][maxFood]);

    return 0;
}
