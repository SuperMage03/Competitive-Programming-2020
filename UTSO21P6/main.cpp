#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll hills[200005];

ll calcDanger(ll hillAmt, ll index, ll newVal) {
    ll dangerF = 0;
    for (ll i = 0; i < hillAmt - 1; i++) {
        ll curHeight = i == index ? newVal : hills[i], nextHeight = hills[i + 1];
        if (dangerF < abs(curHeight - nextHeight)) {
            dangerF = abs(curHeight - nextHeight);
        }
    }
    return dangerF;
}

ll hahaCalcDanger(int hillAmt) {
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

    ll cases, hillAmt, changeAmt, dangerF, dangerFLoc;
    cin >> cases;

    for (ll c = 0; c < cases; c++) {
        memset(hills, 0, 200005);
        cin >> hillAmt >> changeAmt;
        for (ll i = 0; i < hillAmt; i++) {
            cin >> hills[i];
        }

        dangerF = hahaCalcDanger(hillAmt);

        ll newDanger = dangerF, newHeight, curDanger;
        if (changeAmt == 1) {
            //Case 1
            ll aTb = hills[dangerFLoc + 1] - hills[dangerFLoc];
            aTb = aTb < 0 ? -1 : 1;
            newHeight = hills[dangerFLoc];
            curDanger = 0;
            while (curDanger < dangerF) {
                newHeight += aTb;
                curDanger = calcDanger(hillAmt, dangerFLoc, newHeight);
                newDanger = min(newDanger, curDanger);
            }

            //Case 2
            ll bTa = hills[dangerFLoc] - hills[dangerFLoc + 1];
            bTa = bTa < 0 ? -1 : 1;
            newHeight = hills[dangerFLoc + 1];
            curDanger = 0;
            while (curDanger < dangerF) {
                newHeight += bTa;
                curDanger = calcDanger(hillAmt, dangerFLoc + 1, newHeight);
                newDanger = min(newDanger, curDanger);
            }
        }
        cout << newDanger << "\n";
    }
    return 0;
}
