#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;

ll counter = 0, tracker = 0;
int rAmt, cAmt;
pair<int, int> roomba[200005]; //{x, y}
pair<int, int> cord[200005]; //{x, y}

tree<pair<int, int>, null_type, less<>, rb_tree_tag, tree_order_statistics_node_update> OST;


int SearchCord(int L, int R, int val) {
    int mid = (L + R) / 2;

    if (L == R) {
        return L;
    }
    else if (val <= get<0>(cord[mid])) {
        return SearchCord(L, mid, val);
    }
    else {
        return SearchCord(mid + 1, R, val);
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> rAmt >> cAmt;

    for (int i = 0; i < rAmt; i++) {
        cin >> roomba[i].first >> roomba[i].second;
    }

    for (int i = 0; i < cAmt; i++) {
        cin >> cord[i].first >> cord[i].second;
    }
    cord[cAmt] = {INT16_MAX, INT16_MAX};

    sort(roomba, roomba + rAmt);
    sort(cord, cord + cAmt);

    int lastSearchIdx = 0;
    for (int i = 0; i < rAmt; i++) {
        int curRX = roomba[i].first, curRY = roomba[i].second;

        int curSearchIdx = SearchCord(0, cAmt, curRX);
        curSearchIdx += (cord[curSearchIdx].first == curRX);

        counter += OST.size() - OST.order_of_key({curRY, 0});

        for (int j = lastSearchIdx; j < curSearchIdx; j++) {
            int curCY = cord[j].second;
            counter += (curRY <= curCY);
            tracker++;
            OST.insert({curCY, tracker});
        }

        lastSearchIdx = curSearchIdx;
    }

    cout << counter << "\n";
    return 0;
}