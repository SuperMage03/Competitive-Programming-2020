#include <bits/stdc++.h>
using namespace std;

int N, M;
string initCfg;

struct Node {
    int L, R, freq[10], lazy;
    Node *LNode = nullptr, *RNode = nullptr;
};

struct SegTree {
    Node *root = nullptr;

    void init() {
        root = new Node();
        buildTree(root, 0, N - 1);
    }

    static void buildTree(Node *node, int L, int R) {
        node->L = L;
        node->R = R;
        node->lazy = 0;
        if (L == R) {
            memset(node->freq, 0, 10);
            node->freq[initCfg.at(L) - '0'] = 1;
        }
        else {
            int mid = (L + R) / 2;
            node->LNode = new Node();
            node->RNode = new Node();
            buildTree(node->LNode, L, mid);
            buildTree(node->RNode, mid + 1, R);
            for (int i = 0; i < 10; i++) {
                node->freq[i] = node->LNode->freq[i] + node->RNode->freq[i];
            }
        }
    }


    static void printGraph(Node *node) {
        cout << "Left: " << node->L << " Right: " << node->R << " Lazy: " << node->lazy << "\n";
        for (int a : node->freq) {
            cout << a << ", ";
        }
        cout << "\n";
        if (node->L != node->R) {
            printGraph(node->LNode);
            printGraph(node->RNode);
        }
    }

    static int sumQuery(Node *node, int QL, int QR) {
        int L = node->L, R = node->R;
        if (QR < L || R < QL) {return 0;}
        if (QL <= L && R <= QR) {
            int counter = 0;
            for (int i = 0; i < 10; i++) {
                counter += i * node->freq[i];
            }
            return counter;
        }
        pushDownLazy(node);
        return sumQuery(node->LNode, QL, QR) + sumQuery(node->RNode, QL, QR);
    }

    static void pushDownLazy(Node *node) {
        //If it's not a leaf node
        if (node->L != node->R) {
            rotate(node->LNode->freq, node->LNode->freq + 10 - node->lazy, node->LNode->freq + 10);
            node->LNode->lazy += node->lazy;
            node->LNode->lazy %= 10;

            rotate(node->RNode->freq, node->RNode->freq + 10 - node->lazy, node->RNode->freq + 10);
            node->RNode->lazy += node->lazy;
            node->RNode->lazy %= 10;

            node->lazy = 0;
        }
    }


    //Updates the accessing data with adding lazy nodes
    //shiftFreq before updateNode
    static void updateNode(Node *node, int UL, int UR) {
        int L = node->L, R = node->R;
        if (UR < L || R < UL) {return;}
        if (UL <= L && R <= UR) {
            node->lazy++;
            node->lazy %= 10;
            rotate(node->freq, node->freq + 10 - 1, node->freq + 10);
            return;
        }
        //Update if the node is partially in range
        pushDownLazy(node);
        updateNode(node->LNode, UL, UR);
        updateNode(node->RNode, UL, UR);
        for (int i = 0; i < 10; i++) {
            node->freq[i] = node->LNode->freq[i] + node->RNode->freq[i];
        }
    }

    static int getSum(Node *node, int QL, int QR) {
        int sum = sumQuery(node, QL, QR);
        updateNode(node, QL, QR);
        return sum;
    }
};

SegTree ST;

int main() {
    cin.sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;
    cin >> initCfg;
    ST.init();

    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        cout << ST.getSum(ST.root, a - 1, b - 1) << "\n";
        //ST.printGraph(ST.root);
    }
    return 0;
}
