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
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int angle;
    cin >> angle;

    int copy = angle, product = 1;
    for (int i = 2; i <= angle; i++) {
        if (copy == 1) {break;}
        if (isPrime(i) && copy % i == 0) {
            copy /= i;
            product *= i;
        }
    }

    cout << product << "\n";

    return 0;
}
