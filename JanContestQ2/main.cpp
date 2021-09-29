#include <bits/stdc++.h>
#define f first
#define s second
using namespace std;

const vector<pair<int, int>> dir = {{1, 0}, {-1, 0}, {0, -1}, {0, 1}};
int track[10][10];
bool visited[10][10];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int size;
    cin >> size;

    memset(track, 0, 100);
    memset(visited, 0, 100);

    pair<int, int> start;
    for (int j = 0; j < size; j++) {
        string cur;
        cin >> cur;
        for (int i = 0; i < size; i++) {
            char c = cur.at(i);
            if (c == '.') {track[j][i] = 1;}
            else if (c == '#') {track[j][i] = 0;}
            else if (c == 'S') {
                track[j][i] = 2;
                start = {i, j};
            }
            else {track[j][i] = 3;}
        }
    }




    vector<pair<int, int>> stack;
    stack.push_back(start);

    while (!stack.empty()) {
        pair<int, int> cur = stack.back();
        stack.pop_back();
        if (track[cur.s][cur.f] == 3) {
            cout << 1 << "\n";
            return 0;
        }
        visited[cur.s][cur.f] = true;

        for (auto &curD : dir) {
            pair<int, int> nextPos = {cur.f + curD.f, cur.s + curD.s};
            if (nextPos.f >= 0 && nextPos.f < size && nextPos.s >= 0 && nextPos.s < size && !visited[nextPos.s][nextPos.f] && track[nextPos.s][nextPos.f] != 0) {
                stack.push_back(nextPos);
            }
        }
    }

    cout << 0 << "\n";
    return 0;
}
