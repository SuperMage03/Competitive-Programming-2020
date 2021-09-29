#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int intervals, quarries;
    cin >> intervals >> quarries;

    vector<int> start, end;

    for (int i = 0; i < intervals; i++) {
        int a, b;
        cin >> a >> b;
        start.push_back(a);
        end.push_back(b);
    }
    sort(start.begin(), start.end());
    sort(end.begin(), end.end());

    int q;
    for (int i = 0; i < quarries; i++) {
        cin >> q;
        int ub = upper_bound(start.begin(), start.end(), q) - start.begin();
        int lb = lower_bound(end.begin(), end.end(), q) - end.begin();
        cout << ub - lb << endl;
    }


    return 0;
}
