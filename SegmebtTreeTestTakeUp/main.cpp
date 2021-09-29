#include <iostream>
#include <numeric>
using namespace std;

const int MAXN = 100005;
int N, M, arr[MAXN];


struct Node {
    int L, R, minVal, maxVal, gcdVal;
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
        if (L == R) {
            node->minVal = arr[L];
            node->maxVal = arr[L];
            node->gcdVal = arr[L];
        }
        else {
            int mid = (L + R) / 2;
            node->LNode = new Node();
            node->RNode = new Node();
            buildTree(node->LNode, L, mid);
            buildTree(node->RNode, mid + 1, R);
            node->minVal = min(node->LNode->minVal, node->RNode->minVal);
            node->maxVal = max(node->LNode->maxVal, node->RNode->maxVal);
            node->gcdVal = gcd(node->LNode->gcdVal, node->RNode->gcdVal);
        }
    }

    static int minQuery(Node *node, int QL, int QR) {
        int L = node->L, R = node->R;
        if (QR < L || R < QL) {
            return INT_MAX;
        }
        else if (QL <= L && R <= QR) {
            return node->minVal;
        }
        else {
            return min(minQuery(node->LNode, QL, QR), minQuery(node->RNode, QL, QR));
        }
    }

    static int gcdQuery(Node *node, int QL, int QR) {
        int L = node->L, R = node->R;
        if (QR < L || R < QL) {
            return 0;
        }
        else if (QL <= L && R <= QR) {
            return node->gcdVal;
        }
        else {
            return gcd(gcdQuery(node->LNode, QL, QR), gcdQuery(node->RNode, QL, QR));
        }
    }

    static void updateMinQuery(Node *node, int idx, int newVal) {
        int L = node->L, R = node->R;
        if (idx < L || R < idx) {
            return;
        }
        if (idx == L && R == idx) {
            node->minVal = newVal;
            node->gcdVal = newVal;
            node->maxVal = newVal;
            return;
        }
        updateMinQuery(node->LNode, idx, newVal);
        updateMinQuery(node->RNode, idx, newVal);

        node->minVal = min(node->LNode->minVal, node->RNode->minVal);
        node->maxVal = max(node->LNode->maxVal, node->RNode->maxVal);
        node->gcdVal = gcd(node->LNode->gcdVal, node->RNode->gcdVal);
    }


    int rangeCount(Node *node, int QL, int QR, int val) {
        int L = node->L, R = node->R;
        if (node->gcdVal > val || node->minVal > val || root->maxVal < val) {
            return 0;
        }
        if (QR < L || R < QL) {
            return 0;
        }
        if (QL <= L && R <= QR) {
            if (node->gcdVal == val && node->maxVal == val) {
                return R - L + 1;
            }
        }

        return rangeCount(node->LNode, QL, QR, val) + rangeCount(node->RNode, QL, QR, val);
    }
} ST;




int main() {
    cin.sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;
    for (int i = 1; i <= N; i++) {cin >> arr[i];}
    ST.init();

    char qType;
    int v1, v2;

    for (int q = 0; q < M; q++) {
        cin >> qType >> v1 >> v2;
        if (qType == 'C') {
            arr[v1] = v2;
        }
        else if (qType == 'M') {
            cout << ST.minQuery(ST.root, v1, v2) << "\n";
        }
        else if (qType == 'G') {
            cout << ST.gcdQuery(ST.root, v1, v2) << "\n";
        }
        else {
            int gcdValue = ST.gcdQuery(ST.root, v1, v2);
            cout << ST.rangeCount(ST.root, v1, v2, gcdValue) << "\n";
        }
    }

    return 0;
}
