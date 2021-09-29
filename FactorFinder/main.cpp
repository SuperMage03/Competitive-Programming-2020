#include <bits/stdc++.h>
using namespace std;

vector<int> factors;
int main() {
    int a;
    cin >> a;

    for (int i = 1; i <= a; i++) {
        if (a % i == 0) {
            factors.push_back(i);
        }
    }

    cout << factors.size() << endl;

    for (int &i : factors) {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}
