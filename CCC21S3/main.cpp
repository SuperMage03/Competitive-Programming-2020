#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;

struct Friend {
    long long hearing, secondPerM, position;

    ull calcTime(int myPos) {
        long long toPerson = abs(position - myPos);
        if (toPerson <= hearing) {return 0;}
        else {
            return (ull)(toPerson - hearing) * (ull)secondPerM;
        }
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int fAmt;
    cin >> fAmt;

    Friend friends[fAmt];

    ull distMax = 0;

    for (int i = 0; i < fAmt; i++) {
        ull pos, speed, hearing;
        cin >> pos >> speed >> hearing;
        friends[i].position = pos;
        friends[i].secondPerM = speed;
        friends[i].hearing = hearing;
        distMax = max(distMax, pos);
    }

    ull curMin = 0x3f3f3f3f3f3f3f3f;

    for (ull i = 0; i <= 0; i++) {
        ull curMax = 0;
        for (auto &f : friends) {
            curMax += f.calcTime(i);
        }
        curMin = min(curMin, curMax);
    }

    for (ull i = distMax/2; i <= distMax; i++) {
        ull curMax = 0;
        for (auto &f : friends) {
            curMax += f.calcTime(i);
        }

        if (curMax >= curMin) {
            break;
        }
        else {
            curMin = min(curMin, curMax);
        }
    }

    int curPos = distMax / 2;
    int asd = 0;
    while (true) {
        ull curMax = 0;

        if (asd == 0) {

            for (auto &f : friends) {
                curMax += f.calcTime(curPos + 1);
            }
            int curHa = curMax;
            curMax = 0;
            for (auto &f : friends) {
                curMax += f.calcTime(curPos - 1);
            }

            if (curMax < curHa) {asd = 1;}
            else {asd = -1;}
        }
    }

    cout << curMin << "\n";

    return 0;
}
