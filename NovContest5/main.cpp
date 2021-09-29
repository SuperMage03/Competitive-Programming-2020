#include <bits/stdc++.h>
using namespace std;

string indexer = " qwertyuiopasdfghjklzxcvbnmQWERTYUIOPASDFGHJKLZXCVBNM";

int main() {
    string ipt, newIpt;
    getline(cin, ipt);

    for (char curChar : ipt) {
        if (indexer.find(curChar) != string::npos) {newIpt += curChar;}
    }

    transform(newIpt.begin(), newIpt.end(), newIpt.begin(), ::toupper);

    string holder;
    vector<string> iptList;
    while (newIpt.find(' ') != string::npos) {
        iptList.push_back(newIpt.substr(0, newIpt.find(' ')));
        newIpt = newIpt.substr(newIpt.find(' ') + 1, newIpt.length() - newIpt.find(' '));
    }
    iptList.push_back(newIpt);


    for (int i = iptList.size() - 1; i >= 0; i--) {
        if (iptList[i].length() <= 3) {
            iptList.erase(iptList.begin() + i);
        }
        else {
            iptList[i] = iptList[i].substr(1, iptList[i].length() - 3);
        }
    }

    sort(iptList.begin(), iptList.end());

    for (int i = 0; i < iptList.size(); i++) {
        if (iptList[i].length() > 5) {iptList[i] += ".";}
    }

    newIpt.clear();

    for (string a : iptList) {newIpt += a + " ";}

    newIpt.erase(newIpt.begin() + newIpt.length() - 1);

    if (newIpt.at(newIpt.length() - 1) != '.') {newIpt += ".";}

    cout << newIpt << "\n";

    return 0;
}