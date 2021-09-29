#include <bits/stdc++.h>
using namespace std;

/*
BFS - Breadth First Search
"Breadth" - Traversing through all nodes from a single point, put all points in a queue

 DFS - Depth First Search
 "Depth" - Getting as deep as possible with one path. For every edge that connects to the node, add it to a stack1 2

1 2
1 3
1 4
2 5
2 6
2 7
3 8
4 9
-1 -1
 */

queue<int> q; //LIFO
stack<int> s; //FIFO
deque<int> d; //All combinations of L and F

int main() {
    /*
    q.push(5);
    q.push(6);
    q.push(7);
    q.push(8);
    while (!q.empty()) {
        cout << q.front() << "\n";
        q.pop();
    }

    s.push(5);
    s.push(6);
    s.push(7);
    s.push(8);
    while(!s.empty()) {
        cout << s.top() << "\n";
        s.pop();
    }

    d.push_back(5);
    d.push_front(10);
    d.pop_back();
    d.pop_front();
    */

    vector<int> graph[40];
    int a, b;
    while (true) {
        cin >> a >> b;
        if (a == -1 || b == -1) {break;}
        graph[a].push_back(b);
    }

    q.push(1);
    while (!q.empty()) {
        int cur = q.front();
        //cout << cur << "\n";
        q.pop();
        for (int i : graph[cur]) {
            q.push(i);
        }
    }

    s.push(1);
    while (!s.empty()) {
        int cur = s.top();
        s.pop();
        cout << cur << "\n";
        for (int i : graph[cur]) {
            s.push(i);
        }
    }

    return 0;
}
