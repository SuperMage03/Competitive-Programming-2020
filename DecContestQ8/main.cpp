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



int main() {
    cin.sync_with_stdio(false);
    cin.tie(nullptr);

    int start;
    cin >> start;

    int fibA = 1, fibB = 1, fibTemp;
    while (true) {
        if (isPrime(fibB) && fibB > start) {
            break;
        }
        fibTemp = fibA + fibB;
        fibA = fibB;
        fibB = fibTemp;
    }

    cout << fibB << "\n";
    return 0;
}
