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
    int start, end;
    cin >> start >> end;
    int counter = 0;
    for (int nums = start; nums <= end; nums++) {
        if (isPrime(nums)) {
            counter++;
        }
    }
    cout << counter << "\n";
    isPrime(counter) ? cout << "Yes\n" : cout << "No\n";
    return 0;
}
