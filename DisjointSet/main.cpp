#include <bits/stdc++.h>
using namespace std;



struct DisjointSet {
private:
    struct Node {
        int parent = INT16_MIN, subsetRank = 0;
    };

    unordered_map<int, Node> graph;

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
    int size = 0;
    void connect(int p1, int p2) {
        Node *node1 = &graph[p1], *node2 = &graph[p2];
        node1->parent = findParent(p1);
        node2->parent = findParent(p2);

        if (node1->subsetRank > node2->subsetRank) {node2->parent = p1;}
        else if (node1->subsetRank < node2->subsetRank) {node1->parent = p2;}
        else {
            node2->parent = p1;
            node1->subsetRank++;
        }
    }

    bool connected(int p1, int p2) {
        return graph[p1].parent == graph[p2].parent;
    }
};


int main() {
    DisjointSet DS;

    int points, queries;
    cin >> points >> queries;

    for (int i = 0; i < points; i++) {
        int a, b;
        cin >> a >> b;
        DS.connect(a, b);
    }



    return 0;
}

/*
6 3
1 2
2 3
3 4
4 6
6 5
19 14
1 4
1
1 19
0
14 19
1
 */