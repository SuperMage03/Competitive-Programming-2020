#include <bits/stdc++.h>
using namespace std;

int count(string str, string content) {
    int counter = 0;
    for (int i = 0; i < str.length(); i++) {
        string curSubStr = str.substr(i, content.length());
        if (curSubStr == content) {
            counter++;
        }
    }
    return counter;
}

int main() {
    int ans = 0;
    string rhyme;
    cin >> rhyme;
    for (int interval = 0; interval < 25; interval++) {
        string curInterval = "";
        for (char curChar : rhyme) {
            curInterval += 'a' + (curChar - 'a' + interval) % 26;
        }
        ans += count(curInterval, "ang");
    }
    cout << ans << "\n";
    return 0;
}
