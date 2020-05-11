#include <bits/stdc++.h>
using namespace std;

#define MAX 102

bool visited[MAX];
vector<int> adj[MAX];

void bfs(int v) {
    queue<int> q;
    visited[v] = true;
    q.push(v);

    while (!q.empty()) {
        int x = q.front();
        printf("%d ", x);
        q.pop();

        for (int a : adj[x]) {
            if (visited[a]) continue;
            visited[a] = true;
            q.push(a);
        }
    }

    printf("\n");
}

int main() {
    memset(visited, 0, sizeof(visited));
    for (int i = 0; i < MAX; i++) adj[i].clear();

    int n;
    cin >> n;

    while (n--) {
        int a, b;
        cin >> a >> b;

        adj[a].push_back(b);
        // adj[b].push_back(a);
    }

    int s;
    cin >> s;

    bfs(s);

    return 0;
}