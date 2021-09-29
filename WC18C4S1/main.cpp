#include <bits/stdc++.h>
using namespace std;

struct DisjointSet {
private:
    struct Node {
        int parent = INT16_MIN, subsetRank = 0;
    };

    int findParent(int n) {
        Node *node = &graph[n];
        if (node->parent == INT16_MIN || node->parent == n) {
            node->parent = n;
            return n;
        }
        int parent = findParent(node->parent);
        node->parent = parent;
        return node->parent;
    }

public:
    unordered_map<int, Node> graph;

    void connect(int p1, int p2) {
        int px = findParent(p1), py = findParent(p2);
        if (px != py) {
            Node *node1 = &graph[px], *node2 = &graph[py];
            if (node1->subsetRank > node2->subsetRank) {node2->parent = p1;}
            else if (node1->subsetRank < node2->subsetRank) {node1->parent = p2;}
            else {
                node2->parent = p1;
                node1->subsetRank++;
            }
        }
    }

    bool connected(int p1, int p2) {
        return findParent(p1) == findParent(p2);
    }
};

int main() {
    cin.sync_with_stdio(false);
    cin.tie(nullptr);

    DisjointSet DS;

    int planets, routes, friends;
    cin >> planets >> routes >> friends;

    string races;
    cin >> races;

    for (int i = 0; i < routes; i++) {
        int a, b;
        cin >> a >> b;
        if (races.at(a - 1) == races.at(b - 1)) {
            DS.connect(a, b);
        }
    }

    int counter = 0;
    for (int i = 0; i < friends; i++) {
        int a, b;
        cin >> a >> b;
        counter = DS.connected(a, b) ? counter + 1 : counter;
    }

    cout << counter << "\n";

    return 0;
}
