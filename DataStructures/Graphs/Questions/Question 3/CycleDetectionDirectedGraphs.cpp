#include <iostream>
#include <vector>
#include <unordered_map>
#include <list>

using namespace std;

bool checkCycleDFS(int node, unordered_map<int, bool> &visited, unordered_map<int, bool> &dfsvisited, unordered_map<int, list<int>> &adj) {
    visited[node] = true;
    dfsvisited[node] = true;
    
    for (auto neighbour : adj[node]) {
        if (!visited[neighbour]) {
            bool cycleDetected = checkCycleDFS(neighbour, visited, dfsvisited, adj);
            if (cycleDetected)
                return true;
        } else if (dfsvisited[neighbour]) {
            return true;
        }
    }
    dfsvisited[node] = false;
    return false;
}

bool detectCycleInDirectedGraph(int n, vector<pair<int, int>> &edges) {
    unordered_map<int, list<int>> adj;
    
    // Create adjacency list
    for (const auto &edge : edges) {
        int u = edge.first;
        int v = edge.second;
        adj[u].push_back(v);
    }
    
    // Call DFS for all nodes
    unordered_map<int, bool> visited;
    unordered_map<int, bool> dfsvisited;
    
    for (int i = 1; i <= n; ++i) {
        if (!visited[i]) {
            if (checkCycleDFS(i, visited, dfsvisited, adj)) {
                return true;
            }
        }
    }
    return false;
}

int main() {
    int n, m;
    cin >> n >> m;
    
    vector<pair<int, int>> edges;
    
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        edges.push_back({u, v});
    }
    
    bool hasCycle = detectCycleInDirectedGraph(n, edges);
    
    if (hasCycle) {
        cout << "true" << endl;
    } else {
        cout << "false" << endl;
    }
    
    return 0;
}
