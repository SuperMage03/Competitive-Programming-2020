#include <bits/stdc++.h>
typedef unsigned long long ull;
using namespace std;

ull prime;
ull power[105];

ull createHash(string hashing) {
    ull hash = 0;
    for (ull i = 0; i < hashing.length(); i++) {
        if (power[i] == 0) {
            power[i] = power[i-1] * prime;
        }
        hash += (hashing.at(i) - 'a' + 1) * power[i];
    }
    return hash;
}

bool isPrime(ull num) {
    if (num < 2) {return false;}
    ull counter = 0;
    for (ull div = 1; div <= round((double) sqrt(num)); div++) {
        if (num % div == 0) {
            counter++;
        }
    }
    return counter == 1;
}

ull closestPrime(ull num) {
    ull i = num;
    while (true) {
        if (isPrime(i)) {return i;}
        i++;
    }
}

int main() {
    memset(power, 0, 105);
    power[0] = 1;
    cin >> prime;
    prime = closestPrime(prime);
    int hashes;
    cin >> hashes;
    string str;
    for (ull counter = 0; counter < hashes; counter++) {
        cin >> str;
        cout << createHash(str) << "\n";
    }
}
