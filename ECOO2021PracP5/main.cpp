#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;

int points, rockets, A, B, startA, startB;
gp_hash_table<int, vector<int>> grid;

unordered_set<string> counter;

int solve(int turn, int curA, int curB) {
    int outCome1 = -1, outCome2 = -1;
    counter.insert(to_string(curA) + " " + to_string(curB));
    counter.insert(to_string(curB) + " " + to_string(curA));

    for (int a : grid[curA]) {
        if (counter.find(to_string(curA) + " " + to_string(a)) == counter.end()) {
            outCome1 = solve(turn + 1, curA, a);
        }
    }


    if (outCome1 != turn % 2) {
        for (int b : grid[curB]) {
            if (counter.find(to_string(curB) + " " + to_string(b)) == counter.end()) {
                outCome2 = solve(turn + 1, curB, b);
            }
        }
    }



    if (outCome1 == -1 && outCome2 == -1) {
        return turn % 2;
    }

    if ((outCome1 != -1 && outCome1 == turn % 2) || (outCome2 != -1 && outCome2 == turn % 2)) {
        return turn % 2;
    }

    else {
        return (turn + 1) % 2;
    }
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> points;
    rockets = points - 1;

    for (int i = 0; i < rockets; i++) {
        cin >> A >> B;
        grid[A].push_back(B);
        grid[B].push_back(A);
    }

    cin >> startA >> startB;
    counter.insert(to_string(startA) + " " + to_string(startB));
    counter.insert(to_string(startB) + " " + to_string(startA));

    //A side
    int aOutCome = 1, bOutCome = 1;
    for (int a : grid[startA]) {
        if (counter.find(to_string(startA) + " " + to_string(a)) == counter.end()) {
            aOutCome = solve(0, startA, a);
        }
    }

    if (aOutCome != 0) {
        //B side
        for (int b : grid[startB]) {
            if (counter.find(to_string(startB) + " " + to_string(b)) == counter.end()) {
                bOutCome = solve(0, startB, b);
            }
        }
    }

    if (aOutCome == 0 || bOutCome == 0) {
        cout << "Let's play >:)" << "\n";
    }

    else {
        cout << "NOU >:(" << "\n";
    }


    return 0;
}
