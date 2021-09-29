#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;

gp_hash_table<int, int> chart[20];
int chart2[200000][20];
int main() {
    ios::sync_with_stdio(false);
    cin.tie();

    int singers, beats, interval;
    cin >> singers >> beats >> interval;

    for (int y = 0; y < singers; y++) {
        for (int x = 0; x < beats; x++) {
            int curNote;
            cin >> curNote;
            chart[x][curNote] = y;
            chart2[y][x] = curNote;
        }
    }

    int ans = 0;
    for (int y = 0; y < beats - 1; y++) {
        for (auto &note_singer : chart[y]) {
            int note = note_singer.first;
            int targetNote = note + interval;
            if (chart[y].find(targetNote) != chart[y].end()) {
                if (chart2[chart[y][targetNote]][y + 1] - chart2[note_singer.second][y + 1] == interval) {
                    ans++;
                }
            }
        }
    }

    cout << ans << "\n";
    return 0;
}