#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

const ll p = 31;
const ll m = 44654641650887;

ll curPower = 1;
int freqArr[26], curFreq[26];
unordered_set<ll> indexer;

ll makeHash(string str) {
    ll hash = 0;
    for (int i = str.length() - 1; i >= 0; i--) {
        if (i != str.length() - 1) {
            curPower = (curPower * p) % m;
        }
        hash += ((str.at(i) - 'a') * curPower) % m;
        curFreq[str.at(i) - 'a']++;
    }
    return hash;
}

bool isPerm() {
    for (int i = 0; i < 26; i++) {
        if (freqArr[i] != curFreq[i]) {
            return false;
        }
    }
    return true;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    memset(freqArr, 0, 26);
    memset(curFreq, 0, 26);

    string sub, str;
    cin >> sub >> str;

    for (char &c : sub) {
        freqArr[c - 'a']++;
    }

    ll hash;
    for (int i = 0; i <= (int)str.length() - (int)sub.length(); i++) {
        if (i == 0) {
            hash = makeHash(str.substr(i, sub.length()));
        }
        else {
            char remove = str.at(i - 1);
            char add = str.at(i + sub.length() - 1);
            curFreq[remove - 'a']--;
            curFreq[add - 'a']++;
            hash -= ((remove - 'a') * curPower) % m;
            hash = (hash + m) % m;
            hash = ((hash * p) % m + (add - 'a')) % m;
        }

        if (isPerm()) {
            indexer.insert(hash);
        }
    }

    cout << indexer.size() << "\n";
    return 0;
}
