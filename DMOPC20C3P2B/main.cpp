#include <iostream>
#include <algorithm>
using namespace std;

struct Note {
    int singer, note;
};

bool operator<(const Note &n1, const Note &n2) {
    return n1.note < n2.note;
}


Note chart[20][2000000];


int main() {
    ios::sync_with_stdio(false);
    cin.tie();

    int singers, beats, interval;
    cin >> singers >> beats >> interval;

    int ans = 0;

    for (int y = 0; y < singers; y++) {
        for (int x = 0; x < beats; x++) {
            int curNote;
            cin >> curNote;
            chart[x][y] = {y, curNote};
        }
    }

    for (int x = 0; x < beats - 1; x++) {
        sort(chart[x], chart[x] + singers);
        int L = 0, R = 0;
        while (L < singers && R < singers) {
            Note left = chart[x][L], right = chart[x][R];

            if (right.note - left.note > interval) {L++;}
            else if (right.note - left.note < interval) {R++;}
            else {
                if (chart[x + 1][right.singer].note - chart[x + 1][left.singer].note == interval) {
                    ans++;
                }
                L++; R++;
            }
        }
    }



    cout << ans << "\n";
    return 0;
}