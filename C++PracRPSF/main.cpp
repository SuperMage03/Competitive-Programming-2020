#include <bits/stdc++.h>
using namespace std;

int main() {
    map<string, string> indexer = {{"Scissors", "Rock"}, {"Rock", "Paper"}, {"Paper", "Scissors"}, {"Fox","Foxen"}};
    int rounds; char play[256];
    scanf("%d", &rounds);
    for (int i = 0; i < rounds; i++) {
        scanf("%s", &play);
        if (string(play) == "Foxen") {
            break;
        }
        cout << indexer[string(play)] << endl;
    }
    return 0;
}
