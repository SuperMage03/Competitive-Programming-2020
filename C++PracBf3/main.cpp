#include <bits/stdc++.h>
using namespace std;

int main() {
    int num;
    scanf("%d", &num);
    int cur = num;
    if (num <= 1) {
        printf("%d\n", 2);
        return 0;
    }
    while (true) {
        int counter = 0;
        for (int i = 1; i <= sqrt(cur); i++) {
            if (cur % i == 0) counter+=2;
        }
        if (counter == 2) break;
        else cur++;
    }
    printf("%d\n", cur);
    return 0;
}
