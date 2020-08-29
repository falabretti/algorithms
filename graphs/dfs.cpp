#include <bits/stdc++.h>
using namespace std;

#define MAX 101

bool visited[MAX];
vector<int> adj[MAX];

void add_edge(int v, int u) {

    adj[v].push_back(u);
    adj[u].push_back(v);
}

void dfs(int cur) {

    if (visited[cur]) {
        return;
    }

    visited[cur] = true;
    cout << cur << " ";

    for (int next : adj[cur]) {
        dfs(next);
    }
}

int count(int node_size) {

    int c = 0;

    for (int cur = 0; cur < node_size; cur++) {        
        if (!visited[cur]) {
            c++;
            dfs(cur);
        }
    }

    return c;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    memset(visited, 0, sizeof(visited));
    for (auto& vec : adj) vec.clear();

    int n = 4;
    int e = 6;

    add_edge(0, 1);
    add_edge(0, 2);
    add_edge(1, 2);
    add_edge(2, 0);
    add_edge(2, 3);
    add_edge(3, 3);

    dfs(2);
    cout << "\n";

    return 0;
}