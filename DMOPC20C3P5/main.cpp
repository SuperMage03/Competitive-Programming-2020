#include <bits/stdc++.h>
typedef unsigned long long ull;
using namespace std;

const ull primeMod = 1e9 + 7;
ull powers[1000005];

ull power(ull base, ull power) {
    ull counter = 1;
    while (power != 0) {
        if (power & 1) {
            counter *= base;
        }
        power = power >> 1;
        base *= base;
    }
    return counter;
}


ull binaryExp(ull base, ull power, ull mod) {
    ull counter = 1;

    base %= mod;
    if (base == 0) {
        return 0;
    }

    while (power != 0) {
        if (power & 1) {
            counter *= base;
            counter %= mod;
        }
        power = power >> 1;
        base *= base;
        base %= mod;
    }

    return counter;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ull amount, modulo;
    cin >> amount >> modulo;

    for (ull i = 0; i < amount; i++) {
        cin >> powers[i];
    }

    ull finalPow = 1;
    for (ull i = amount - 1; i >= 1; i--) {
        finalPow = binaryExp(powers[i], finalPow, primeMod);
    }

    cout << binaryExp(powers[0], finalPow, modulo) << "\n";
    return 0;
}
