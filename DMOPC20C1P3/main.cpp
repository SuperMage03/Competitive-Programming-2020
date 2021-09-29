#include <bits/stdc++.h>
using namespace std;

int main() {
    long long amount;
    scanf("%lld", &amount);
    long long sequence[amount], LR[amount], RL[amount];
    LR[0] = 0; RL[0] = 0;
    for (long long i = 0; i < amount; i++) {
        scanf("%lld", &sequence[i]);
    }

    long long curMax = sequence[0];
    for (long long i = 1; i < amount; i++) {
        curMax = max(curMax, sequence[i]);
        LR[i] = LR[i-1] + (abs(sequence[i] - curMax));
    }

    long long seqRev[amount], counter = 0;
    for (long long i = amount-1; i >= 0; i--) {
        seqRev[counter] = sequence[i];
        counter++;
    }

    long long curMin = seqRev[0];
    for (long long i = 1; i < amount; i++) {
        curMin = max(curMin, seqRev[i]);
        RL[i] = RL[i-1] + (abs(seqRev[i] - curMin));
    }

    reverse(RL, RL+amount);

    long long ans = LONG_LONG_MAX;
    for (long long i = 0; i < amount; i++) {
        ans = min(ans, LR[i]+RL[i]);
    }

    printf("%lld\n", ans);
    for(long long a : LR) cout << a << ' ';
    cout << endl;
    for(long long a : RL) cout << a << ' ';
    cout << endl;
    return 0;
}
