#include <bits/stdc++.h>
using namespace std;

unordered_set<string> perms;
void getPerm(string storage, string left) {
    if (storage.length() == 4) {
        perms.insert(storage);
    }
    else {
        for (int i = 0; i < left.length(); i++) {
            char cur = left.at(i);
            string newLeft;
            for (int j = 0; j < left.length(); j++) {
                if (j != i) {
                    newLeft += left.at(j);
                }
            }
            getPerm(storage + cur, newLeft);
        }
    }
}

int main() {
    getPerm("", "HOMEROOM");
    cout << perms.size() << "\n";
    return 0;
}
