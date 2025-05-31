#include <bits/stdc++.h> 
using namespace std;

vector<pair<pair<int, int>, int>> calculatePrimsMST(int n, int m, vector<pair<pair<int, int>, int>> &g) {
    // Adjacency list representation of the graph
    vector<vector<pair<int, int>>> graph(n + 1);

    // Construct the graph from the input edges
    for (int i = 0; i < m; ++i) {
        int u = g[i].first.first;
        int v = g[i].first.second;
        int w = g[i].second;
        graph[u].push_back({v, w});
        graph[v].push_back({u, w});
    }

    // Priority queue to store the edges (weight, current_node, next_node)
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
    // Key array to keep track of the minimum weight edge connecting each node to MST
    vector<int> key(n + 1, INT_MAX);
    // MST edges
    vector<pair<pair<int, int>, int>> mst_edges;

    // Start from node 1 (can start from any node)
    int start_node = 1;
    key[start_node] = 0;
    pq.push({0, {start_node, start_node}});

    while (!pq.empty()) {
        // Pop the edge with the smallest weight
        auto top = pq.top();
        pq.pop();
        int weight = top.first;
        int u = top.second.first;
        int parent = top.second.second;

        if (key[u] != weight)
            continue;

        // Add the edge to the MST
        if (u != parent) {
            mst_edges.push_back({{parent, u}, weight});
        }

        // Explore neighbors
        for (auto& neighbor : graph[u]) {
            int v = neighbor.first;
            int w = neighbor.second;
            if (w < key[v]) {
                key[v] = w;
                pq.push({w, {v, u}});
            }
        }
    }

    return mst_edges;
}

int main() {
    int T;
    cin >> T; // Number of test cases

    while (T--) {
        int n, m;
        cin >> n >> m; // Number of nodes (1-indexed) and edges

        vector<pair<pair<int, int>, int>> edges(m);
        // Reading edges
        for (int i = 0; i < m; ++i) {
            int u, v, w;
            cin >> u >> v >> w;
            edges[i] = {{u, v}, w};
        }

        // Get MST using Prim's algorithm
        vector<pair<pair<int, int>, int>> mst_edges = calculatePrimsMST(n, m, edges);

        cout << endl;

        // Output MST edges with weights
        for (auto& edge : mst_edges) {
            int u = edge.first.first;
            int v = edge.first.second;
            int weight = edge.second;
            cout << u << " " << v << " " << weight << "\n";
        }
    }

    return 0;
}
