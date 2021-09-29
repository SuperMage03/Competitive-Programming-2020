#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll hills[200005];

ll calcDanger(int hillAmt) {
    ll dangerF = 0;
    for (ll i = 0; i < hillAmt - 1; i++) {
        ll curHeight = hills[i], nextHeight = hills[i + 1];
        if (dangerF < abs(curHeight - nextHeight)) {
            dangerF = abs(curHeight - nextHeight);
        }
    }
    return dangerF;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll cases, hillAmt, changeAmt;
    cin >> cases;

    for (ll c = 0; c < cases; c++) {
        memset(hills, 0, 200005);
        cin >> hillAmt >> changeAmt;
        for (ll i = 0; i < hillAmt; i++) {
            cin >> hills[i];
        }
        cout << calcDanger(hillAmt) << "\n";
    }
    return 0;
}