#include <bits/stdc++.h>
using namespace std;

int main() {
    int size, ans = 0;
    scanf("%d", &size);
    int nums[size];
    for (int i = 0; i < size; i++) {
        scanf("%d", &nums[i]);
    }

    bool adj = false;
    int possible[2] = {0, 0}, record;
    for (int i = 0; i < size-1; i++) {
        if (abs(nums[i+1] - nums[i]) == 1) {
            if (!adj) {
                adj = true; record = i;
                possible[0] += nums[i];
                possible[1] += nums[i+1];
            }
            else {
                possible[(record)%2] += nums[i+1];
                record++;
            }
        }
        else {
            if (adj) {
                adj = false;
                ans += max(possible[0], possible[1]);
                possible[0] = 0; possible[1] = 0;
            }
            else ans += nums[i];
        }
    }
    if (possible[0] != 0 || possible[1] != 0) ans += max(possible[0], possible[1]);

    printf("%d\n", ans);
    return 0;
}