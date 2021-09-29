#include <bits/stdc++.h>

using namespace std;

int main() {
    int size;
    scanf("%d", &size);
    vector<int> nums;
    for (int i = 0; i < size; i++) {
        int ipt;
        scanf("%d", &ipt);
        nums.push_back(ipt);
    }

    sort(nums.begin(), nums.end(), greater<int>());

    for (int i = size-1; i >= 0; i--) {
        printf("%d\n", nums[i]);
        nums.pop_back();
    }


    return 0;
}