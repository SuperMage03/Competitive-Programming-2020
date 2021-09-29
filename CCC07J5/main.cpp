#include <bits/stdc++.h>
using namespace std;

int main() {
    int def[] = {0, 990, 1010, 1970, 2030, 2940, 3060, 3930, 4060, 4970, 5030, 5990, 6010, 7000};
    int a, b, extra;
    scanf("%d %d %d", &a, &b, &extra);
    long finalHotel[14+extra];
    for (int i = 0; i < 14; i++) {
        finalHotel[i] = def[i];
    }
    for (int i = 14; i < 14+extra; i++) {
        scanf("%ld", &finalHotel[i]);
    }
    sort(finalHotel, finalHotel+(14+extra));

    long memory[14+extra];
    memset(memory, 0, sizeof(memory));
    memory[0] = 1;

    for (int i = 1; i < 14+extra; i++) {
        int first = finalHotel[i]-a > 0 ? finalHotel[i] - a : 0;
        int least = finalHotel[i]-b;
        for (int j = i-1; j >= 0; j--) {
            if (finalHotel[j] <= first && finalHotel[j] >= least) {
                memory[i] += memory[j];
            }
            else if (finalHotel[j] < least) break;
        }
    }

    printf("%ld\n", memory[14+extra-1]);

    return 0;
}