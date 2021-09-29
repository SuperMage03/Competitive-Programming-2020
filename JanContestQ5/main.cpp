#include <bits/stdc++.h>
using namespace std;

string derivative(string eq) {
    int xPos = eq.find('x');
    int coefficient = xPos == 1 ? stoi(eq.substr(0, 1) + "1") : stoi(eq.substr(0, xPos));
    int exponent = eq.length() - xPos == 1 ? 1 :  stoi(eq.substr(xPos + 2, eq.length() - (xPos + 2)));
    int newE = exponent - 1;
    int newC = exponent * coefficient;
    string f;
    if (newC == 1) {f = "+";}
    else if (newC == -1) {f = "-";}
    else {
        f = to_string(newC);
        if (f.at(0) != '-') {f = "+" + f;}
    }
    string s;
    if (newE == 0) {s = "";}
    else if (newE == 1) {s = "x";}
    else {s = "x^" + to_string(newE);}

    return f + s;
}

int main() {
    string eq1;
    cin >> eq1;
    if (eq1.at(0) != '-' || eq1.at(0) != '+') {
        eq1 = '+' + eq1;
    }

    vector<string> separated;
    string holder;
    for (int i = 0; i < eq1.length(); i++) {
        char cur = eq1.at(i);
        if (cur == '-' || cur == '+') {
            if (!holder.empty()) {separated.push_back(holder);}
            holder = cur;
        }
        else {
            holder += cur;
        }
    }
    if (!holder.empty()) {separated.push_back(holder);}

    string ans;
    for (auto &a : separated) {
        ans += derivative(a);
    }

    if (ans.at(0) == '+') {
        ans = ans.substr(1, ans.length() - 1);
    }

    cout << ans << "\n";
    return 0;
}
