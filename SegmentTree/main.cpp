#include <bits/stdc++.h>
using namespace std;

int arr[1000];

struct STNode {
    int val, left, right;
} SegTree[4 * 1000];

void buildTree(int index, int curL, int curR) {
    SegTree[index].left = curL;
    SegTree[index].right = curR;
    if (curL == curR) {
        SegTree[index].val = arr[curL];
    }
    else {
        int mid = (curL + curR) / 2;
        buildTree(index * 2, curL, mid);
        buildTree(index * 2 + 1, mid + 1, curR);
        SegTree[index].val = min(SegTree[index * 2].val, SegTree[index * 2 + 1].val);
    }
}

int queryMin(int index, int QL, int QR) {
    int curL = SegTree[index].left, curR = SegTree[index].right;
    //Case 1 [L, R] is outside [QL, QR], Return infinity
    if (curR < QL || QR < curL) {
        return 1e9;
    }
    //Case 2 [L, R] is inside [QL, QR], Return node val
    else if (QL <= curL && QR >= curR) {
        return SegTree[index].val;
    }
    //Case 3 [L, R] is partially inside [QL, QR], Keep branching until inside
    else {
        int minL = queryMin(index * 2, QL, QR); //Left
        int minR = queryMin(index * 2 + 1, QL, QR); //Right
        return min(minL, minR);
    }
}

void update(int curIdx, int index, int newVal) {
    int L = SegTree[curIdx].left, R = SegTree[curIdx].right;
    //Case 1: index outside [L, R]
    if (R < index || index < L) {
        return;
    }
    //Case 2: index is found
    if (L == R && L == index) {
        SegTree[curIdx].val = newVal;
        return;
    }
    //Case 3: index is partially within [L, R]
    if (L <= index && index <= R) {
        update(curIdx * 2, index, newVal);
        update(curIdx * 2 + 1, index, newVal);
        SegTree[curIdx].val = min(SegTree[curIdx * 2].val, SegTree[curIdx * 2 + 1].val);
        return;
    }
}

int main() {
    int amount;
    scanf("%d", &amount);
    for (int i = 0; i < amount; i++) {
        scanf("%d", &arr[i]);
    }
    buildTree(1, 0, amount - 1);
    update(1, 0, -1);
    int QL, QR;
    while (true) {
        scanf("%d %d", &QL, &QR);
        printf("Minimum Value is %d\n", queryMin(1, QL, QR));
    }
    return 0;
}
