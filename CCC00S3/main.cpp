#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;

gp_hash_table<string, unordered_set<string>> indexer;

vector<int> findAll(string str, string sub) {
    vector<int> positions;
    int pos = str.find(sub, 0);

    while(pos != string::npos) {
        positions.push_back(pos);
        pos = str.find(sub,pos + 1);
    }

    return positions;
}


bool search(const string &origin, const string &target, unordered_set<string> *mem) {
    unordered_set<string> *OS = &indexer[origin];
    if (OS->empty()) {
        return false;
    }
    else if (OS->find(target) != OS->end()) {
        return true;
    }
    else {
        for (const string &s : *OS) {
            if (mem->find(s) == mem->end()) {
                mem->insert(s);
                if (search(s, target, mem)) {return true;}
            }
        }
        return false;
    }
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int websites, passedSites = 0;
    cin >> websites;

    string lineBefore, curLine, curSite;

    bool inSite = false;
    while (passedSites < websites) {
        getline(cin, curLine);
        if (curLine.substr(0, 6) == "<HTML>") {
            curSite = lineBefore;
            inSite = true;
        }
        else if (curLine == "</HTML>") {
            passedSites++;
            inSite = false;
        }

        if (inSite) {
            vector<int> finder = findAll(curLine, "<A HREF=\"");
            if (!finder.empty()) {
                for (int startIndex : finder) {
                    string targetSite;
                    for (int index = startIndex + 9; index < curLine.length(); index++) {
                        char curChar = curLine.at(index);
                        if (curChar == '"') {
                            break;
                        }
                        targetSite += curChar;
                    }
                    cout << "Link from " << curSite << " to " << targetSite << "\n";
                    indexer[curSite].insert(targetSite);
                }
            }
        }
        lineBefore = curLine;
    }

    string from, to;
    while (true) {
        getline(cin, from);
        if (from == "The End") {
            break;
        }
        getline(cin, to);
        unordered_set<string> mem;
        mem.insert(from);
        if (search(from, to, &mem)) {
            cout << "Can surf from " << from << " to " << to << ".\n";
        }
        else {
            cout << "Can't surf from " << from << " to " << to << ".\n";
        }
    }
    return 0;
}