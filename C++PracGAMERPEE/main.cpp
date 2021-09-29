#include <bits/stdc++.h>
#define f first
#define s second
using namespace std;
typedef pair<int, int> point;
array<point, 4> dir = {point{0,1}, point{0,-1}, point{1,0}, point{-1,0}};

int main() {
    int searches, size1, size2;
    cin >> searches;

    for (int i = 0; i < searches; i++) {
        cin >> size1 >> size2;
        char grid[size2][size1];
        int check[size2][size1];
        memset(check, -1, sizeof(check));
        point start; string temp;

        for (int y = 0; y < size2; y++) {
            cin >> temp;
            for (int x = 0; x < size1; x++) {
                if (temp.at(x) == 'C') start = {x, y};
                grid[y][x] = temp.at(x);
            }
        }


        int counter = 99999;
        queue<point> q;
        check[start.s][start.f] = 0;
        q.push(start);
        while (!q.empty()) {
            point curPos = q.front();
            q.pop();
            for (point add : dir) {
                point newPos = {curPos.f + add.f, curPos.s + add.s};
                if (newPos.f < size1 && newPos.f >= 0 && newPos.s < size2 && newPos.s >= 0) {
                    if (check[newPos.s][newPos.f] == -1) {
                        if (grid[newPos.s][newPos.f] == 'W') {
                            counter = min(counter, check[curPos.s][curPos.f]+1);
                            break;
                        }
                        else if (grid[newPos.s][newPos.f] != 'X') {
                            q.push(newPos);
                            check[newPos.s][newPos.f] = check[curPos.s][curPos.f]+1;
                        }
                    }
                }
            }
        }

        if (counter < 60) cout << counter << endl;
        else cout << "#notworth" << endl;
    }
    return 0;
}