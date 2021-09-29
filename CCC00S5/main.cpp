#include <bits/stdc++.h>
using namespace std;



int sheepAmount;
bool eaten[1005];
vector<int> holder;
pair<double, double> sheep[1005];

double hypotSq(pair<double, double> &pos1, pair<double, double> &pos2) {
    return pow(pos2.second - pos1.second, 2) + pow(pos2.first - pos1.first, 2);
}

double findA(pair<double, double> &pos1, pair<double, double> &pos2, int offset) {
    double a, c, d, e, f;
    c = pos1.first; d = pos1.second;
    e = pos2.first; f = pos2.second;
    a = (c * c + d * d - e * e - f * f - offset) / (2 * c - 2 * e);
    return a;
}

bool inRange(pair<double, double> &pos) {
    if (pos.first >= 0 && pos.first <= 1000 && pos.second >= 0 && pos.second <= 1000) {
        return true;
    }
    return false;
}

bool isClosest(int curSheep, pair<double, double> &pos) {
    holder.clear();
    holder.push_back(curSheep);
    double distToBeat = hypotSq(sheep[curSheep], pos);
    for (int i = 0; i < sheepAmount; i++) {
        if (i == curSheep) {continue;}
        double curDist = hypotSq(sheep[i], pos);
        if (curDist < distToBeat) {
            return false;
        }
        else if (curDist == distToBeat) {
            holder.push_back(i);
        }
    }
    return true;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cout << fixed;
    cout << setprecision(2);

    fill(eaten, eaten + 1005, true);
    cin >> sheepAmount;

    for (int i = 0; i < sheepAmount; i++) {
        pair<double, double> curSheep = sheep[i];
        bool flag = true;
        for (int j = 0; j < sheepAmount; j++) {
            if (i != j && eaten[j]) {
                pair<double, double> compareSheep = sheep[j];
                if (compareSheep.first == curSheep.first) {
                    if (curSheep.second < compareSheep.first) {
                        eaten[j] = false;
                        continue;
                    }
                    else {
                        eaten[i] = false;
                        break;
                    }
                }
                pair<double, double> aPoint = {findA(curSheep, compareSheep, 0), 0};
                if (inRange(aPoint) && isClosest(i, aPoint)) {
                    flag = false;
                }
            }
        }
        if (flag) {
            eaten[i] = false;
        }
    }

    for (int i = 0; i < sheepAmount; i++) {
        if (eaten[i]) {
            cout << "The sheep at (" << sheep[i].first << ", " << sheep[i].second << ") might be eaten.\n";
        }
    }

    return 0;
}