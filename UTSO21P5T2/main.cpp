#include <bits/stdc++.h>
using namespace std;

const int mod = 1000000007;
int arr[100005], N;

struct SegmentTree {
private:
    struct Node {
        int val, L, R;
        Node *LNode = nullptr, *RNode = nullptr;
    };

    Node *rootNode = nullptr;

    void buildTree(Node *node, int L, int R) {
        node->L = L;
        node->R = R;
        if (L == R) {
            node->val = arr[L];
        }
        else {
            int mid = (L + R) / 2;
            node->LNode = new Node();
            node->RNode = new Node();
            buildTree(node->LNode, L, mid);
            buildTree(node->RNode, mid + 1, R);
        }
    }
public:
    SegmentTree() {
        rootNode = new Node();
        buildTree(rootNode, 0, N - 1);
    }
};


int main() {
    return 0;
}
