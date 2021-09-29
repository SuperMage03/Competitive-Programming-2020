#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second
typedef pair<size_t, size_t> DI;
const size_t mod = 1000000007;
const size_t pp = 2000000016;

pair<DI, DI> MM(pair<DI, DI> m1, pair<DI, DI> m2){
    pair<DI, DI> ans = {{(m1.f.f * m2.f.f + m1.f.s * m2.s.f) % mod, (m1.f.f * m2.f.s + m1.f.s * m2.s.s) % mod},
                        {(m1.s.f * m2.f.f + m1.s.s * m2.s.f) % mod, (m1.s.f * m2.f.s + m1.s.s * m2.s.s) % mod}};
    return ans;
}



int main() {
    string in;
    cin >> in;

    size_t num = 0;
    for(char c : in) {
        int value = c - '0';
        num = num * 10 + value;
        num %= pp;
    }
    pair<DI, DI> result = {{1, 0}, {0, 1}};
    pair<DI, DI> counter = {{1,1}, {1,0}};

    while (num != 0){
        if (num & 1){
            result = MM(result, counter);
        }
        counter = MM(counter, counter);
        num = num >> 1;
    }
    printf("%llu\n", result.s.f);

    return 0;
}