#include <bits/stdc++.h>
using namespace std;

int main() {
    int tests; cin >> tests;
    for (int i = 0; i < tests; i++) {
        string curTest; cin >> curTest;
        bool math = false, compSci = false;
        for (char subject : curTest) {
            if (subject == 'M') {math = true;}
            else if (subject == 'C') { compSci = true;}
        }

        if (math && compSci) {cout << "NEGATIVE MARKS\n";}
        else if (math || compSci) {cout << "FAIL\n";}
        else {cout << "PASS\n";}
    }

    return 0;
}
