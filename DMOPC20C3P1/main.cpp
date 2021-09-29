#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int amount;
    cin >> amount;

    unordered_set<int> holder;
    for (int i = 0; i < amount; i++) {
        int ipt;
        cin >> ipt;
        if (holder.find(ipt) != holder.end() || (ipt < 1 || ipt > amount)) {
            cout << "NO" << "\n";
            return 0;
        }
        holder.insert(ipt);
    }

    cout << "YES" << "\n";
    return 0;
}
