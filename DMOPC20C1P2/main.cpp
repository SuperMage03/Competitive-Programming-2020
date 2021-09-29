#include <bits/stdc++.h>
using namespace std;

int main() {
    int trains, days;
    scanf("%d %d", &trains, &days);
    vector<int> arr1, arr2;
    for (int i = 0; i < trains; i++) {
        int temp; scanf("%d", &temp);
        arr1.push_back(temp);
    }

    for (int day = 0; day < days; day++) {
        int amount; scanf("%d", &amount);
        arr2 = vector<int>(arr1.begin() + amount, arr1.end());
        arr1 = vector<int>(arr1.begin(), arr1.begin() + amount);
        long long sum1 = 0; sum1 = accumulate(arr1.begin(), arr1.begin() + arr1.size(), sum1);
        long long sum2 = 0; sum2 = accumulate(arr2.begin(), arr2.begin() + arr2.size(), sum2);

        if (sum1 >= sum2) {
            printf("%lld\n", sum1);
            arr1 = vector<int>(arr2.begin(), arr2.end());
        }
        else {
            printf("%lld\n", sum2);
        }
    }

    return 0;
}
