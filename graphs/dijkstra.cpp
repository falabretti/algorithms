#include <bits/stdc++.h>

using namespace std;

#define INF 0x3f3f3f3f

typedef pair<int, int> edge;
typedef vector<edge> adj_list;

void add_edge(adj_list adj[], int v, int u, int w) {

    adj[v].push_back(make_pair(u, w));
    adj[u].push_back(make_pair(v, w));
}

void path(vector<int>& parent, int v) {

    if (parent[v] == -1) {
        return;
    }

    path(parent, parent[v]);
    printf("%d ", v);
}

void dijkstra(adj_list adj[], int v_size, int src, int dest) {

    priority_queue<edge, vector<edge>, greater<edge>> pq;
    vector<int> dist(v_size, INF);
    vector<bool> processed(v_size, false);
    vector<int> parent(v_size, -1);

    pq.push(make_pair(0, src));
    dist[src] = 0;

    while (!pq.empty()) {

        int cur = pq.top().second;
        pq.pop();
        processed[cur] = true;

        if (cur == dest) {
            break;
        }

        for (auto [v, w] : adj[cur]) {

            if (not processed[v] and dist[cur] + w < dist[v]) {
                parent[v] = cur;
                dist[v] = dist[cur] + w;
                pq.push(make_pair(dist[v], v));
            }
        }
    }

    printf("distance: %d\n", dist[dest]);
    printf("path: %d ", src);
    path(parent, dest);
    printf("\n");
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int v = 9;
    adj_list adj[v];
    
    add_edge(adj, 0, 1, 4); 
    add_edge(adj, 0, 7, 8); 
    add_edge(adj, 1, 2, 8); 
    add_edge(adj, 1, 7, 11); 
    add_edge(adj, 2, 3, 7); 
    add_edge(adj, 2, 8, 2); 
    add_edge(adj, 2, 5, 4); 
    add_edge(adj, 3, 4, 9); 
    add_edge(adj, 3, 5, 14); 
    add_edge(adj, 4, 5, 10); 
    add_edge(adj, 5, 6, 2); 
    add_edge(adj, 6, 7, 1); 
    add_edge(adj, 6, 8, 6); 
    add_edge(adj, 7, 8, 7);

    dijkstra(adj, v, 0, 8);

    return 0;
}
