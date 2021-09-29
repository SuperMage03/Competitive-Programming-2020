#include <bits/stdc++.h>
using namespace std;

int main() {
    int cases, curMax;
    scanf("%d", &cases);
    int base[19];
    memset(base,0,sizeof(base));
    base[0] = 192; base[1] = 442;
    base[2] = 692; base[3] = 942;
    for (int i = 0; i < cases; i++) {
        scanf("%d", &curMax);
        int x = 0;
        while (base[x] <= curMax) {
            if (base[x+1] == 0) {
                base[x+1] = base[x-3] + 1000;
            }
            x++;
        }
        printf("%d\n", base[x]);
    }
    return 0;
}
