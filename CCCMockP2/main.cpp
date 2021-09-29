#include <bits/stdc++.h>
using namespace std;


vector<int> graph[100005];
int dist[100005];
bool visited[100005];
multiset<pair<int, int>> pq;

void calcDijkstra(int a) {
    memset(visited, 0, 100005);
    fill(dist, dist + 100005, 0x3f3f3f3f);
    dist[a] = 0;
    pq.insert({0, a});

    while (!pq.empty()) {
        pair<int, int> curHouse = *(pq.begin());
        pq.erase(pq.begin());
        visited[curHouse.second] = true;

        for (int nextNode : graph[curHouse.second]) {
            if (!visited[nextNode] && curHouse.first + 1 < dist[nextNode]) {
                dist[nextNode] = curHouse.first + 1;
                pq.insert({dist[nextNode], nextNode});
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int houses, roads, journeys, mustGo;
    cin >> houses >> roads >> journeys >> mustGo;

    for (int i = 0; i < roads; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    calcDijkstra(mustGo);
    for (int i = 0; i < journeys; i++) {
        int a, b;
        cin >> a >> b;
        if (dist[a] != 0x3f3f3f3f && dist[b] != 0x3f3f3f3f) {
            cout << dist[a] + dist[b] << "\n";
        }
        else {
            cout << -1 << "\n";
        }

    }




    return 0;
}
