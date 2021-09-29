#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll salary[500001], totRev[500001], change;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int citizens, operations;
    cin >> citizens >> operations;

    for (int i = 1; i <= citizens; i++) {
        cin >> salary[i];
        totRev[i] = 0;
    }

    for (int i = 0; i < operations; i++) {
        int mode, start, end;
        cin >> mode;
        if (mode == 1) {
            cin >> start >> end >> change;
            for (int s = start; s <= end; s++) {
                salary[s] += change;
            }
        }
        else {
            cin >> start >> end;
            for (int s = start; s <= end; s++) {
                totRev[s] += salary[s];
            }
        }
    }

    for (int i = 1; i <= citizens; i++) {
        cout << totRev[i] << " ";
    }
    cout << "\n";

    return 0;
}
