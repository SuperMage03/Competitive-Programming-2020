#include <bits/stdc++.h>
using namespace std;


int ans = 0, amount, cell[1500][1500], mem[1500][1500];

const pair<int, int> dirs[] = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};

void solveCell(int &x, int &y) {
    vector<pair<int, int>> possible;
    for (pair<int, int> dir : dirs) {
        int nextX = x + dir.first, nextY = y + dir.second;
        if (nextX >= 0 && nextX <= amount-1 && nextY >= 0 && nextY <= amount-1 && cell[y][x] < cell[nextY][nextX]) {
            possible.emplace_back(nextX, nextY);
        }
    }

    if (possible.empty()) {
        mem[y][x] = 0;
    }

    else {
        for (pair<int, int> nextPos : possible) {
            if (mem[nextPos.second][nextPos.first] == -1) {
                solveCell(nextPos.first, nextPos.second);
            }
            mem[y][x] = max(mem[y][x], 1 + mem[nextPos.second][nextPos.first]);
        }
    }

    ans = max(ans, mem[y][x]);
}


int main() {
    cin.sync_with_stdio(false);
    cin.tie(nullptr);

    for (auto &a : mem) {
        fill(a, a + 1500, -1);
    }
    for (auto &a : cell) {
        memset(a, 0, 1500);
    }

    cin >> amount;
    for (int row = 0; row < amount; row++) {
        for (int col = 0; col < amount; col++) {
            cin >> cell[row][col];
        }
    }

    for (int row = 0; row < amount; row++) {
        for (int col = 0; col < amount; col++) {
            if (mem[row][col] == -1) {solveCell(col, row);}
        }
    }

    cout << ans << "\n";
    return 0;
}
