#include <bits/stdc++.h>
using namespace std;


struct Grid {
    //0 Black, 1 Gold
    int colour = 0;
    void flip() {
        colour = (colour + 1) % 2;
    }
};

int columns, rows, brushes;
Grid canvas[105][105];


void printGrid() {
    for (int y = 1; y < rows + 1; y++) {
        for (int x = 1; x < columns + 1; x++) {
            cout << canvas[x][y].colour << " ";
        }
        cout << "\n";
    }
}

void brushRow(int rowNum) {
    for (int x = 1; x < columns + 1; x++) {
        canvas[x][rowNum].flip();
    }
}

void brushCol(int colNum) {
    for (int y = 1; y < rows + 1; y++) {
        canvas[colNum][y].flip();
    }
}

int totalGold() {
    int counter = 0;
    for (int y = 1; y < rows + 1; y++) {
        for (int x = 1; x < columns + 1; x++) {
            counter += canvas[x][y].colour;
        }
    }
    return counter;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> rows >> columns >> brushes;

    int num; char mode;
    for (int i = 0; i < brushes; i++) {
        cin >> mode >> num;

        if (mode == 'R') {
            brushRow(num);
        }
        else {
            brushCol(num);
        }
    }

    cout << totalGold() << "\n";

    //printGrid();
    return 0;
}