#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

struct Rumba {
    ll rY, rXFinish;
} rumba[200000];


struct sortRY {
    inline bool operator() (const Rumba& r1, const Rumba& r2) {
        return (r1.rY < r2.rY);
    }
};


struct SegTree {
    struct Node {
        ll from = 0, to = 0;
        ll min = INT64_MAX, max = INT64_MIN, size = 1;
        Node *LNode = nullptr, *RNode = nullptr;
    };

    Node *root = nullptr;

    void init(ll size) {
        root = new Node();
        buildTree(root, 0, size - 1);
    }

    static void buildTree(Node *node, ll L, ll R) {
        node->from = L; node->to = R;
        if (L == R) {
            node->min = rumba[L].rXFinish;
            node->max = rumba[L].rXFinish;
        }
        else {
            ll mid = (L + R) / 2;
            node->LNode = new Node();
            node->RNode = new Node();
            buildTree(node->LNode, L, mid);
            buildTree(node->RNode, mid + 1, R);
            node->size = node->LNode->size + node->RNode->size;
            node->min = min(node->LNode->min, node->RNode->min);
            node->max = max(node->LNode->max, node->RNode->max);
        }
    }

    ll querySize(ll from, ll to, ll val, Node* node) {
        //Case 1 [L, R] is outside [QL, QR]
        if (node->to < from || to < node->from) {
            return 0;
        }
            //Case 2 [L, R] is inside [QL, QR]
        else if (from <= node->from && to >= node->to) {
            return queryVal(val, node);
        }
            //Case 3 [L, R] is partially inside [QL, QR], Keep branching until inside
        else {
            ll QL = querySize(from, to, val, node->LNode); //Left
            ll QR = querySize(from, to, val, node->RNode); //Right
            return QL + QR;
        }
    }

    ll queryVal(ll val, Node* node) {
        if (node->max < val) {
            return 0;
        }
        else if (node->min >= val) {
            return node->size;
        }
        else {
            ll QL = queryVal(val, node->LNode);
            ll QR = queryVal(val, node->RNode);
            return QL + QR;
        }
    }
} ST;





ll searchRY(ll num,ll curL,ll curR){
    ll mid = (curL + curR) / 2;

    if (curL == curR){
        return curL;
    }
    if (num >= rumba[mid].rY){
        return searchRY(num, mid + 1, curR);
    }

    else {
        return searchRY(num, curL, mid);
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll rAmt, cAmt;
    cin >> rAmt >> cAmt;

    for (ll i = 0; i < rAmt; i++) {
        cin >> rumba[i].rXFinish >> rumba[i].rY;
    }

    sort(rumba, rumba + rAmt, sortRY());
    ST.init(rAmt);

    ll counter = 0;
    for (ll i = 0; i < cAmt; i++) {
        ll curCordX, curCordYEnd;
        cin >> curCordX >> curCordYEnd;

        ll SRY = searchRY(curCordYEnd, 0, rAmt) - 1;
        ll ans = ST.querySize(0, SRY, curCordX, ST.root);
        counter += ans;
    }

    cout << counter << "\n";
    return 0;
}