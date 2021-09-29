#include <bits/stdc++.h>
using namespace std;

unordered_map<int, unordered_set<int>> graph;
unordered_set<int> allPoints;
vector<unordered_set<int>> groups;

void traverse(int current, unordered_set<int> &group) {
    group.insert(current);
    for (int next : graph[current]) {
        if (group.count(next) == 0) {
            traverse(next, group);
        }
    }
}

void grouping(int start) {
    unordered_set<int> cur;
    traverse(start, cur);
    groups.push_back(cur);
}

int main() {
    cin.sync_with_stdio(false);
    cin.tie(nullptr);

    int paths;
    cin >> paths;

    for (int i = 0; i < paths; i++) {
        int pointA, pointB;
        cin >> pointA >> pointB;
        graph[pointA].insert(pointB);
        graph[pointB].insert(pointA);
        allPoints.insert(pointA);
        allPoints.insert(pointB);
    }

    for (int a : allPoints) {
        int flag = true;
        for (unordered_set<int> u : groups) {
            if (u.count(a) != 0) {
                flag = false;
                break;
            }
        }
        if (flag) {
            grouping(a);
        }
    }
    cout << groups.size() - 1 << "\n";
    return 0;
}
