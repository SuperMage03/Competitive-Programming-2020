#include <bits/stdc++.h>
using namespace std;

bool isPrime(int num) {
    if (num < 2) {return false;}
    int counter = 0;
    for (int div = 1; div <= round((double) sqrt(num)); div++) {
        if (num % div == 0) {
            counter++;
        }
    }
    return counter == 1;
}

int getNextPel(int num, bool next) {
    if (next) {num++;}
    while (true) {
        string strNum = to_string(num);
        string reverseNum = to_string(num);
        reverse(reverseNum.begin(), reverseNum.end());
        if (strNum == reverseNum) {
            return num;
        }
        num++;
    }
}

int main() {
    cin.sync_with_stdio(false);
    cin.tie(nullptr);

    int start;
    cin >> start;
    start = getNextPel(start, false);
    while (true) {
        if (isPrime(start)) {
            break;
        }
        start = getNextPel(start, true);
    }

    cout << start << "\n";
    return 0;
}
