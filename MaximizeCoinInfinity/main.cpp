#include <bits/stdc++.h>
using namespace std;

int main() {
    int coins, target;
    scanf("%d", &coins);
    int value[coins];
    for (int i = 0; i < coins; i++) {
        scanf("%d", &value[i]);
    }
    scanf("%d", &target);
    int maxCoin[target]; maxCoin[0] = 0;
    fill(maxCoin + 1, maxCoin + target + 1, -1);

    for (int y = 1; y < target + 1; y++) {
        for (int curValue : value) {
            if (y - curValue >= 0) {
                maxCoin[y] = max(maxCoin[y], maxCoin[y-curValue] + 1);
            }
        }
    }

    printf("%d", maxCoin[target]);
    return 0;
}
