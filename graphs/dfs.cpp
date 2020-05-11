#include <bits/stdc++.h>
using namespace std;

bool visited[102];
vector<int> adj[102];

void dfs(int v) {
    visited[v] = true;
    for (int a : adj[v]) {
        if (visited[a]) continue;
        dfs(a);
    }
}

int main() {
    memset(visited, 0, sizeof(visited));
    for (int i = 0; i < 102; i++) adj[i].clear();

    int n;
    cin >> n;

    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;

        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    // dfs(v);

    return 0;
}