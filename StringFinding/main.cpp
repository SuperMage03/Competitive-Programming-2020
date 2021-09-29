#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

const ll p = 31;
const ll m = 44654641650887;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string str, substring;
    cin >> str >> substring;

    ll strVal = 0, rollingVal = 0, power = 1;

    for (int idx = 0; idx < substring.length(); idx++){
        if (idx != 0) {power =  (power * p) % m;}
        strVal += ((int) (substring.at(substring.length() - (idx + 1)) - 'a') * power) % m;
        strVal %= m;
    }

    for (int i = 0; i <= str.length() - substring.length(); i++) {
        if (i == 0) {
            power = 1;
            for (int idx = 0; idx < substring.length(); idx++) {
                if (idx != 0) {power = (power * p) % m;}
                rollingVal += ((int) (str.at(substring.length() - (idx + 1)) - 'a') * power) % m;
                rollingVal %= m;
            }
        }
        else {
            char remove = str.at(i - 1);
            char add = str.at(i + substring.length() - 1);
            rollingVal -= ((int) (remove - 'a') * power) % m;
            rollingVal = (rollingVal + m) % m;
            rollingVal = ((rollingVal * p) % m + (int) (add - 'a')) % m;
        }

        if (rollingVal == strVal) {
            cout << i << "\n";
            return 0;
        }
    }

    cout << -1 << "\n";
    return 0;
}