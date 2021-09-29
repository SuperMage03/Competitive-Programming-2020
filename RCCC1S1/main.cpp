#include <bits/stdc++.h>
using namespace std;

const string vowels = "aeiouy";
const string consonants = "bcdfghjklmnpqrstvwxyz";

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, C, V;
    cin >> N >> C >> V;

    string word;
    cin >> word;

    int curC = 0, curV = 0, maxC = 0, maxV = 0;
    for (char c : word) {
        if (vowels.find(c) != string::npos) {
            curV++;
        }
        else {
            maxV = max(curV, maxV);
            curV = 0;
        }
        if (consonants.find(c) != string::npos) {
            curC++;
        }
        else {
            maxC = max(curC, maxC);
            curC = 0;
        }
    }
    maxV = max(curV, maxV);
    maxC = max(curC, maxC);

    if (maxC > C || maxV > V) {
        cout << "NO" << "\n";
    }
    else {
        cout << "YES" << "\n";
    }

    return 0;
}
