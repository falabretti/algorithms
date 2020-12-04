#include <bits/stdc++.h>

using namespace std;

class Graph {

    int node_size;
    vector<int>* adj;
    bool* visited;

    public:

    Graph(int node_size);
    void add_edge(int v, int u);
    void DFS(int v);
};

Graph::Graph(int node_size) {

    this->node_size = node_size;
    this->adj = new vector<int>[node_size];
}

void Graph::add_edge(int v, int u) {

    adj[v].push_back(u);
    adj[u].push_back(v);
}

void Graph::DFS(int v) {

    visited = new bool[node_size];
    memset(visited, false, sizeof(bool) * node_size);
}

int main() {

    Graph g(10);

    g.add_edge(0, 1);
    g.add_edge(0, 2);
    g.add_edge(1, 2);
    g.add_edge(2, 0);

    g.DFS(2);

    return 0;
}
