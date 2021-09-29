#include <bits/stdc++.h>
using namespace std;

struct Node {
    int nodeName = 0, curDist = INT16_MAX;
    vector<pair<int, int>> cNodes;
};

bool operator < (const Node &n1, const Node &n2) {
    return n1.curDist > n2.curDist;
}


unordered_map<int, Node> makeDijkstra(unordered_map<int, Node> Nodes, int Source) {
    priority_queue<pair<int, Node*>> Q;
    vector<int> holder;
    bool visited[Nodes.size() + 5];

    //Clears the nodes
    for (auto &node : Nodes) {
        node.second.nodeName = node.first;
    }

    Nodes[Source].curDist = 0;
    Q.push({0, &Nodes[Source]});

    while (!Q.empty()) {
        pair<int, Node*> curNode = Q.top();
        Q.pop();

        visited[curNode.second->nodeName] = true;

        for (auto &nextNodes : curNode.second->cNodes) {
            int nextNodeNum = nextNodes.first;
            int distance = nextNodes.second;
            if (!visited[nextNodeNum] && curNode.second->curDist + distance < Nodes[nextNodeNum].curDist) {
                Nodes[nextNodeNum].curDist = curNode.second->curDist + distance;
                Q.push({Nodes[nextNodeNum].curDist, &Nodes[nextNodeNum]});
            }

        }
    }

    return Nodes;
}

int calcDist(unordered_map<int, Node> &Graph, int Source, int Destination) {
    int shortest = makeDijkstra(Graph, Source)[Destination].curDist;
    shortest = shortest == INT16_MAX ? -1 : shortest;
    return shortest;
}

int main() {
    int N, M;
    cin >> N >> M;
    unordered_map<int, Node> Nodes;
    for (int i = 0; i < M; i++) {
        int a, b, dist;
        cin >> a >> b >> dist;
        Nodes[a].cNodes.emplace_back(b, dist);
        Nodes[b].cNodes.emplace_back(a, dist);
    }
    int u, v;
    cin >> u >> v;
    cout << calcDist(Nodes, u, v) << "\n";
    return 0;
}

/*
9 10
5 4 1
4 2 6
2 6 4
6 3 3
1 3 4
1 2 5
7 8 6
7 10 10
8 9 6
10 9 8
5 9
 */