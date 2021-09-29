#include <bits/stdc++.h>
using namespace std;

unordered_map<int, unordered_set<int>> graph;
int ans = -1;
bool visited[1000000];

unordered_set<int> allPoints;

void traverse(int current, int target, int depth) {
    visited[current] = true;
    if (current == target) {
        ans = max(ans, depth);
    }
    else {
        for (int next : graph[current]) {
            if (!visited[next]) {
                traverse(next, target, depth + 1);
            }
        }
    }
    visited[current] = false;
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
        for (int b : allPoints) {
            traverse(a, b, 0);
        }
    }
    cout << ans << "-otone" << "\n";
    return 0;
}
