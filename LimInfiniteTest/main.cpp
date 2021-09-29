#include <bits/stdc++.h>
using namespace std;
typedef long double ld;

int main() {
    ld counter = 0;
    unsigned long long curPow = 0;
    while (true) {
        counter += powl(-0.5, curPow);
        curPow++;
        cout << counter << "\n";
    }

    return 0;
}
