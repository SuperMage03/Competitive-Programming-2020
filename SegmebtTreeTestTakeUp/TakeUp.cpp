#include <iostream>
#include <numeric>
using namespace std;

const int MAXN = 100005;
int N, M;

struct Node {
    int L, R, minVal, maxVal, gcdVal;
} SegTree[4 * MAXN];

int arr[MAXN];

//Euclidean Algorithm
int oldGCD(int a, int b) {
    if (b == 0) {return a;}
    return oldGCD(b, a % b);
}

void initTree(int v, int L, int R) {
    SegTree[v].L = L;
    SegTree[v].R = R;
    if (L == R) {
        SegTree[v].minVal = arr[L];
        SegTree[v].maxVal = arr[L];
        SegTree[v].gcdVal = arr[L];
    }
    else {
        int mid = (L + R) / 2;
        initTree(v * 2, L, mid);
        initTree(v * 2 + 1, mid + 1, R);
        SegTree[v].minVal = min(SegTree[v * 2].minVal, SegTree[v * 2 + 1].minVal);
        SegTree[v].maxVal = max(SegTree[v * 2].maxVal, SegTree[v * 2 + 1].maxVal);
        SegTree[v].gcdVal = gcd(SegTree[v * 2].gcdVal, SegTree[v * 2 + 1].gcdVal);
    }
}

int minQuery(int v, int QL, int QR) {
    int L = SegTree[v].L, R = SegTree[v].R;
    if (QR < L || R < QL) {
        return INT_MAX;
    }
    else if (QL <= L && R <= QR) {
        return SegTree[v].minVal;
    }
    else {
        return min(minQuery(v * 2, QL, QR), minQuery(v * 2 + 1, QL, QR));
    }
}

int gcdQuery(int v, int QL, int QR) {
    int L = SegTree[v].L, R = SegTree[v].R;
    if (QR < L || R < QL) {
        //gcd(0, x) = x;
        return 0;
    }
    else if (QL <= L && R <= QR) {
        return SegTree[v].gcdVal;
    }
    else {
        return gcd(gcdQuery(v * 2, QL, QR), gcdQuery(v * 2 + 1, QL, QR));
    }
}

void updateMinQuery(int v, int idx, int newVal) {
    int L = SegTree[v].L, R = SegTree[v].R;
    if (idx < L || R < idx) {
        return;
    }
    if (idx == L && R == idx) {
        SegTree[v].minVal = newVal;
        SegTree[v].gcdVal = newVal;
        SegTree[v].maxVal = newVal;
        return;
    }
    updateMinQuery(v * 2, idx, newVal);
    updateMinQuery(v * 2 + 1, idx, newVal);

    SegTree[v].minVal = min(SegTree[v * 2].minVal, SegTree[v * 2 + 1].minVal);
    SegTree[v].maxVal = max(SegTree[v * 2].maxVal, SegTree[v * 2 + 1].maxVal);
    SegTree[v].gcdVal = gcd(SegTree[v * 2].gcdVal, SegTree[v * 2 + 1].gcdVal);
}


int rangeCount(int v, int QL, int QR, int val) {
    int L = SegTree[v].L, R = SegTree[v].R;
    //1. If the gcd of a node > val, return 0
    //2. Seg[v].minVal > val, return 0, also if maxVal < val
    //3. Seg[v].gcdVal == val && Seg[v].maxVal == val (maxVal == minVal), return the elements
    if (SegTree[v].gcdVal > val || SegTree[v].minVal > val || SegTree->maxVal < val) {
        return 0;
    }
    if (QR < L || R < QL) {
        return 0;
    }
    if (QL <= L && R <= QR) {
        if (SegTree[v].gcdVal == val && SegTree[v].maxVal == val) {return R - L + 1;}
    }

    return rangeCount(v * 2, QL, QR, val) + rangeCount(v * 2 + 1, QL, QR, val);
}

int main() {
    cin.sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> M;
    for (int i = 1; i <= N; i++) {cin >> arr[i];}
    initTree(1, 1, N);
    char qType;
    int v1, v2;
    for (int q = 0; q < M; q++) {
        cin >> qType >> v1 >> v2;
        if (qType == 'C') {
            arr[v1] = v2;

        }
        else if (qType == 'M') {
            cout << minQuery(1, v1, v2) << "\n";
        }
        else if (qType == 'G') {
            cout << gcdQuery(1, v1, v2) << "\n";
        }
        else {
            int gcdValue = gcdQuery(1, v1, v2);
            cout << rangeCount(1, v1, v2, gcdValue) << "\n";
        }
    }


    return 0;
}
