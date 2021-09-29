#include <bits/stdc++.h>
using namespace std;

struct Board {
    int curKX, curKY, curPX, curPY, curTurn, KMoves;
};

bool inBoard(int x, int y) {
    if (1 <= x && x <= 8 && 1 <= y && y <= 8) {
        return true;
    }
    return false;
}

bool isPosKing(int x, int y) {
    if (x == 5 && (y == 1 || y == 8)) {
        return true;
    }
    return false;
}

pair<int, int> knightMoves[] = {{1, 2}, {-1, 2}, {1, -2}, {-1, -2},
                                {2, 1}, {2, -1}, {-2, 1}, {-2, -1}};

queue<Board> Q;
int startKX, startKY, startPX, startPY;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> startKX >> startKY >> startPX >> startPY;

    Q.push({startKX, startKY, startPX, startPY, 1, 0});

    while (!Q.empty()) {
        Board board = Q.front();
        Q.pop();

        int curKX = board.curKX, curKY = board.curKY;
        int curPX = board.curPX, curPY = board.curPY;
        int curTurn = board.curTurn, curKMoves = board.KMoves;

        if (curTurn % 2 == 1) {
            for (pair<int, int> move : knightMoves) {
                int newKX = curKX + move.first, newKY = curKY + move.second;
                if (!inBoard(newKX, newKY) || (newKX == curPX && newKY == curPY) || isPosKing(newKX, newKY)) {
                    continue;
                }
                Q.push({newKX, newKY, curPX, curPY, curTurn + 1, curKMoves + 1});
            }
        }
        else {
            int newPX = curPX, newPY = curPY + 1;
            if (!inBoard(newPX, newPY)) {
                continue;
            }
            if (newPX == curKX && newPY == curKY) {
                cout << curKMoves << "\n";
                return 0;
            }
            Q.push({curKX, curKY, newPX, newPY, curTurn + 1, curKMoves});
        }
    }

    cout << "Not possible" << "\n";
    return 0;
}
