#include <bits/stdc++.h>
using namespace std;


const int MAXN = 2500005;
int N, M;
string initCfg;


struct Node {
    //Lazy holds number of pending presses to do
    int L, R, freq[10], lazy;
} seg[4 * MAXN];


void buildTree(int v, int L, int R) {
    seg[v].L = L; seg[v].R = R; seg[v].lazy = 0;
    if (L == R) {
        memset(seg[v].freq, 0, 10);
        seg[v].freq[initCfg[L - 1] - '0'] = 1;
    }
    else {
        int mid = (L + R) / 2;
        buildTree(v * 2, L, mid);
        buildTree(v * 2 + 1, mid + 1, R);
        for (int i = 0; i < 10; i++) {
            seg[v].freq[i] = seg[v * 2].freq[i] + seg[v * 2 + 1].freq[i];
        }
    }
}

void push_lazy(int v) {
    //Thus will update the current node, and give the lazy value for the two children
    int L = seg[v].L, R = seg[v].R;
    //Change the frequency somehow
    /*
     [1, 3, 0, 0, 4, 6, 5, 0, 0, 1] shifted right by 3
     [0, 0, 1, 1, 3, 0, 0, 4, 6, 5] new frequency
    */
    int tmp[10];
    seg[v].lazy %= 10;
    for (int i = 0; i < 10; i++) {
        tmp[i] = seg[v].freq[(i - seg[v].lazy + 10) % 10];
    }
    for (int i = 0; i < 10; i++) {
        seg[v].freq[i] = tmp[i];
    }

    if (L == R) {
        seg[v].lazy = 0;
        return;
    }
    seg[v * 2].lazy += seg[v].lazy;
    seg[v * 2].lazy %= 10;
    seg[v * 2 + 1].lazy += seg[v].lazy;
    seg[v * 2 + 1].lazy %= 10;
    seg[v].lazy = 0;
}

void update(int v, int UL, int UR) {
    int L = seg[v].L, R = seg[v].R;

    if (UR < L || R < UL) {return;}
    if (UL <= L && R <= UR) {
        seg[v].lazy++;
        seg[v].lazy %= 10;
        return;
    }
    update(v * 2, UL, UR);
    update(v * 2 + 1, UL, UR);
    for (int i = 0; i < 10; i++) {
        seg[v].freq[i] = seg[v * 2].freq[i] + seg[v * 2 + 1].freq[i];
    }

}

int sumQuery(int v, int QL, int QR) {
    int L = seg[v].L, R = seg[v].R;
    push_lazy(v);
    if (QR < L || R < QL) {return 0;}
    if (QL <= L && R <= QR) {
        int tot = 0;
        for (int i = 0; i < 10; i++) {
            tot += i * seg[v].freq[i];
        }
        return tot;
    }
    return sumQuery(v * 2, QL, QR) + sumQuery(v * 2 + 1, QL, QR);
}

int main() {
    cin.sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;
    cin >> initCfg;

    buildTree(1, 1, N);

    for (int q = 0; q < M; q++) {
        //Update a RANGE
        //Makes Updates much faster --> Lazy Propagation
        //The idea of lazy prop is you want to procrastinate pm updates as much as possible
        //Holding them until later guarantees that you have best performance because anything that is not necessary,
        //You will never do.
        //If you ever get multiple updates
        int a, b;
        cin >> a >> b;
        cout << sumQuery(1, a, b) << "\n";
        update(1, a, b);

    }

    return 0;
}
