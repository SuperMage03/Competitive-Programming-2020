#include <bits/stdc++.h>
#define f first
#define s second
using namespace std;
typedef pair<int, int> point;

unsigned int DS[3006][3006];

struct Triangle {
    unsigned int sum = 0;
    unordered_set<string> points;

    bool has(point p) {
        return points.find(to_string(p.f) + " " + to_string(p.s)) != points.end();
    }

    void addPoint(point p) {
        points.insert(to_string(p.f) + " " + to_string(p.s));
        sum += DS[p.s][p.f];
    }

    void popPoint(point p) {
        points.erase(to_string(p.f) + " " + to_string(p.s));
        sum -= DS[p.s][p.f];
    }
};



int main() {
    cin.sync_with_stdio(false);
    cin.tie(nullptr);

    int tSize, qSize;
    cin >> tSize >> qSize;

    for (int y = 0; y < tSize; y++) {
        for (int x = 0; x < y + 1; x++) {
            cin >> DS[y][x];
        }
    }


    Triangle t;
    //Setup
    for (int y = 0; y < qSize; y++) {
        for (int x = 0; x < y + 1; x++) {
            t.addPoint({x, y});
        }
    }

    cout << t.sum << "\n";
    for (auto &a : t.points) {
        cout << a << "\n";
    }


    return 0;
}
