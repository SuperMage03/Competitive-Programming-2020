#include <bits/stdc++.h>
using namespace std;

int main() {
    int size;
    scanf("%d", &size);
    int nums[size];
    for (int i = 0; i < size; i++) {
        scanf("%d", &nums[i]);
    }

    int highest, with = nums[0], without = 0;
    for (int i = 1; i < size; i++) {
        highest = max(with, without);
        with = without + nums[i];
        without = highest;
    }
    printf("%d\n", max(with, without));
    return 0;
}