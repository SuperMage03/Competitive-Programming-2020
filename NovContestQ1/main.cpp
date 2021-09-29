#include <bits/stdc++.h>
using namespace std;



struct Node {
    int curVal = -1;
    unordered_set<int> linkedNodes;
};

unordered_set<int> allNodes;
unordered_map<int, Node> nodeMap;


bool stillNeedsVisit(unordered_map<int, bool> visited) {
    bool flag = false;
    for (int node : allNodes) {
        if (!visited[node]) {
            flag = true;
            break;
        }
    }
    return flag;
}

int main() {
    int days, curPLoc, YLoc;
    cin >> days;
    for (int i = 0; i < days; i++) {
        int a, b;
        cin >> a >> b;
        nodeMap[a].linkedNodes.insert(b);
        nodeMap[b].linkedNodes.insert(a);
        allNodes.insert(a);
        allNodes.insert(b);
    }
    cin >> curPLoc >> YLoc;

    nodeMap[curPLoc].curVal = 0;

    int curLoc = curPLoc;
    unordered_map<int, bool> visited;

    while (stillNeedsVisit(visited)) {
        int curDist = nodeMap[curLoc].curVal;
        unordered_set<int> nextNodes = nodeMap[curLoc].linkedNodes;

        for (int nextNode : nextNodes) {
            if (!visited[nextNode]) {
                nodeMap[nextNode].curVal = max(nodeMap[nextNode].curVal, curDist + 1);
            }
        }
        visited[curLoc] = true;

        //Search for next search node
        int biggestNode = -1;
        for (int possibleNode : allNodes) {
            if (!visited[possibleNode] && nodeMap[possibleNode].curVal != -1) {
                if (biggestNode == -1 || nodeMap[possibleNode].curVal > nodeMap[biggestNode].curVal) {
                    biggestNode = possibleNode;
                }
            }
        }

        curLoc = biggestNode;
        if (curLoc == -1) {break;}
    }


    cout << nodeMap[YLoc].curVal << "\n";



    return 0;
}
