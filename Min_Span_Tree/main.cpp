#include <bits/stdc++.h>
using namespace std;

/*
 Taken a huge graph with some number of edges and vertices
 The MST is a set of edges taken suck that it connects all the nodes together,
 this set of edges has the minimum possible sum

 There are 2 algorithms used to find the MST:
 -Prim's algorithm (USE BFS or DFS keeping track of the sum of the weights, nodes visited)

 -Kruskal's algorithm(using a Disjoint Set data structure, sorts edges and inserts them into
  the DSU if the nodes are not already connected)
 */

typedef long long ll;
const int MAXN = 100005;

vector<pair<ll, pair<int, int>>> edges;
int N, K, par[MAXN], subsetRank[MAXN];

int find(int v) {
    if (par[v] == v) {return v;}
    else {return par[v] = find(par[v]);}
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    //use a priority queue for the Prim's algorithm
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
    vector<pair<ll, int>> graph[MAXN];
    bool visited[MAXN];

    cin >> N >> K;
    /*
    ll wi;
    for (int i = 0; i < N - 1; i++) {
        cin >> wi;
        graph[i].push_back({wi, i + 1});
        graph[i + K].push_back({0, i});

        if (i + K < N) {
            graph[i].push_back({0, i + K});
            graph[i].push_back({0, i});
        }
    }

    //Prim's algorithm
    ll minSpanDist = 0;
    pq.push({0, 0});
    while (!pq.empty()) {
        ll dist = pq.top().first;
        int curMode
    }
    return 0;
    */

    //Kruskal's algorithm

    for (int i = 0; i < N - 1; i++) {
        ll wi;
        cin >> wi;
        edges.push_back({wi, {i, i + 1}});
        if (i + K < N) {
            edges.push_back({0, {i, i + K}});
        }
    }
    sort(edges.begin(), edges.end());
    for (int i = 0; i < N; i++) {
        subsetRank[i] = 0;
        par[i] = i;
    }
    ll minSpanDist = 0;
    for (pair<ll, pair<int, int>> edge : edges) {
        ll dist = edge.first;
        int n1 = edge.second.first, n2 = edge.second.second;
        int p1 = find(n1), p2 = find(n2);
    }
}
