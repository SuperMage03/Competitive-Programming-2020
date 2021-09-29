#include <bits/stdc++.h>
using namespace std;

struct Node {
    int nodeName = 0;
    bool connected = false;
    vector<pair<int, int>> connections;
};

Node nodes[100001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int nodeAmount, freeInterval;
    cin >> nodeAmount >> freeInterval;
    for (int i = 1; i <= nodeAmount - 1; i++) {
        int weight;
        cin >> weight;
        nodes[i].connections.emplace_back(i + 1, weight);
        nodes[i + 1].connections.emplace_back(i, weight);
        if (i + freeInterval <= nodeAmount) {
            nodes[i].connections.emplace_back(i + freeInterval, 0);
            nodes[i + freeInterval].connections.emplace_back(i, 0);
        }
    }

    int weightSum = 0;
    priority_queue<pair<int, Node*>, vector<pair<int, Node*>>, greater<>> pq;
    pq.push({0, &nodes[1]});

    while (!pq.empty()) {
        int curWeight = pq.top().first;
        Node* curNode = pq.top().second;
        pq.pop();

        if (curNode->connected) {
            continue;
        }

        weightSum += curWeight;
        curNode->connected = true;

        for (pair<int, int> connection : curNode->connections) {
            int cNode = connection.first;
            int cWeight = connection.second;
            pq.push({cWeight, &nodes[cNode]});
        }
    }

    cout << weightSum << "\n";
    return 0;
}
