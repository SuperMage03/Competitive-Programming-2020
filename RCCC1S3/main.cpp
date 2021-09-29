#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int>> swaps;
int numAmt, swapAmt;
int nums[1005];

int calcPoints(const int *num) {
    int points = 0;
    for (int i = 1; i < numAmt; i++) {
        if (num[i] >= num[i - 1]) {points++;}
    }
}

void swap(int *temp, pair<int, int> a) {
    int t = temp[a.first - 1];
    temp[a.first - 1] = temp[a.second - 1];
    temp[a.second - 1] = t;
}

vector<pair<int, int>> nextStep() {
    vector<pair<int, int>> ans;
    int curMax = -1;
    pair<int, int> curSwap;
    int temp[numAmt], temp2[numAmt];
    for (auto a : swaps) {
        copy(nums, nums + numAmt, temp);
        swap(temp, a);
        for (auto b : swaps) {
            copy(temp, temp + numAmt, temp2);
            swap(temp2, b);
            int p = calcPoints(temp2);

            if (p == numAmt - 1) {
                ans.push_back(a);
                ans.push_back(b);
                return ans;
            }

            if (p > curMax) {
                curMax = p;
                curSwap = a;
            }
        }
    }
    ans.push_back(curSwap);
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> numAmt >> swapAmt;
    for (int i = 0; i < numAmt; i++) {
        cin >> nums[i];
    }
    for (int i = 0; i < swapAmt; i++) {
        int a, b;
        cin >> a >> b;
        swaps.emplace_back(a, b);
    }
    vector<pair<int, int>> allMoves;
    while (calcPoints(nums) != numAmt - 1) {
        vector<pair<int, int>> v = nextStep();
        for (auto a : v) {
            allMoves.push_back(a);
            swap(nums, a);
        }
    }

    cout << allMoves.size() << "\n" << nums[0];
    for (int i = 1; i < numAmt; i++) {
        cout << " " << nums[i];
    }
    cout << "\n";

    for (pair<int, int> p : allMoves) {
        cout << p.first << " " << p.second << "\n";
    }

    return 0;
}
