#include <bits/stdc++.h>
using namespace std;

int main() {
    int amount, num;
    scanf("%d %d", &amount, &num);

    int arr[amount];
    for (int i = 0; i < amount; i++) {
        arr[i] = i+1;
    }

    int leftIdx = 0, rightIdx = amount-1;
    while (leftIdx != rightIdx) {
        int midPoint = leftIdx + (rightIdx - leftIdx)/2;
        if (num == arr[midPoint]) {
            leftIdx = midPoint;
            break;
        }

        if (num < arr[midPoint]) {
            rightIdx = midPoint-1;
        }
        else {
            leftIdx = midPoint+1;
        }
        cout << leftIdx << " " << rightIdx << "\n";
    }

    cout << leftIdx << " " << (arr[leftIdx] == num) << "\n";

    return 0;
}
