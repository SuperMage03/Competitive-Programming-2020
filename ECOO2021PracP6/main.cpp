#include <bits/stdc++.h>
using namespace std;
pair<int, int> dir[] = {{0, 1}, {1, 0}};
queue<pair<int, int>> Q;

int L, W, bAmt;

struct Bully {
    int sX, sY, speed;
    char facing;

    pair<int, int> calcPos(int time) {
        if (facing == 'L') {
            return {sX - speed * time, sY};
        }
        else if (facing == 'R') {
            return {sX + speed * time, sY};
        }
        else if (facing == 'U') {
            return {sX, sY - speed * time};
        }
        else {
            return {sX, sY + speed * time};
        }
    }

    bool inGrid(int time) {
        pair<int, int> newBPos = calcPos(time);
        if (1 <= newBPos.first <= L && 1 <= newBPos.second <= W) {
            return true;
        }
        else {
            return false;
        }
    }

} bullies[100005];



int main() {
    int counter = 0, time = 0;
    Q.push({1, 1});

    cin >> L >> W >> bAmt;
    for (int i = 0; i < bAmt; i++) {
        int x, y, s; char d;
        cin >> y >> x >> s >> d;
        bullies[i].sX = x;
        bullies[i].sY = y;
        bullies[i].speed = s;
        bullies[i].facing = d;
    }

    while (!Q.empty()) {
        pair<int, int> curPos = Q.front();
        Q.pop();
        time++;

        cout << curPos.first << " " << curPos.second << "\n";

        for (auto &d : dir) {
            pair<int, int> newPos = {curPos.first + d.first, curPos.second + d.second};
            if (newPos.first > L || newPos.second > W) {
                continue;
            }

            bool possible = true;
            for (Bully &b : bullies) {
                if (possible) {
                    pair<int, int> newBPos = b.calcPos(time);
                    if (b.facing == 'L') {
                        if (newPos.second == newBPos.second && newPos.first <= newBPos.first && b.inGrid(time)) {
                            possible = false;
                        }
                    }
                    else if (b.facing == 'R') {
                        if (newPos.second == newBPos.second && newPos.first >= newBPos.first && b.inGrid(time)) {
                            possible = false;
                        }
                    }
                    else if (b.facing == 'U') {
                        if (newPos.second <= newBPos.second && newPos.first == newBPos.first && b.inGrid(time)) {
                            possible = false;
                        }
                    }
                    else {
                        if (newPos.second >= newBPos.second && newPos.first == newBPos.first && b.inGrid(time)) {
                            possible = false;
                        }
                    }
                }
            }

            if (possible) {
                if (newPos.first == L && newPos.second == W) {
                    counter++;
                }
                else {
                    Q.push(newPos);
                }
            }
        }
    }

    cout << counter << "\n";

    return 0;
}
