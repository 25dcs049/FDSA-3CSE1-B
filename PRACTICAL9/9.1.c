
#include <iostream>
#include <queue>
using namespace std;

int graph[5][5] = {
    {0,1,1,0,0},
    {1,0,0,1,0},
    {1,0,0,1,1},
    {0,1,1,0,1},
    {0,0,1,1,0}
};

bool visited[5];

void DFS(int v) {
    visited[v] = true;
    cout << v << " ";

    for (int i = 0; i < 5; i++) {
        if (graph[v][i] && !visited[i])
            DFS(i);
    }
}

void BFS(int start) {
    bool visit[5] = {false};
    queue<int> q;

    q.push(start);
    visit[start] = true;

    while (!q.empty()) {
        int v = q.front();
        q.pop();

        cout << v << " ";

        for (int i = 0; i < 5; i++) {
            if (graph[v][i] && !visit[i]) {
                visit[i] = true;
                q.push(i);
            }
        }
    }
}

int main() {
    cout << "DFS: ";
    DFS(0);

    cout << "\nBFS: ";
    BFS(0);

    return 0;
}
