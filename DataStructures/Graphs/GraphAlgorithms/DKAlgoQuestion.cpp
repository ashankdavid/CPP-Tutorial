#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

// Dijkstra's algorithm to find shortest paths from source node (node 0) to all other nodes
vector<int> dijkstra(vector<vector<pair<int, int>>>& graph, int V) {
    vector<int> dist(V, INT_MAX); // Initialize distances with infinity
    dist[0] = 0; // Distance from source node 0 to itself is 0
    
    // Priority queue to process nodes based on shortest distance (min-heap)
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, 0}); // (distance, node)
    
    while (!pq.empty()) {
        int curr_dist = pq.top().first;
        int u = pq.top().second;
        pq.pop();
        
        // If we encounter a distance larger than the known shortest distance, skip processing
        if (curr_dist > dist[u]) continue;
        
        // Explore neighbors of node u
        for (auto& neighbor : graph[u]) {
            int v = neighbor.first;
            int weight = neighbor.second;
            
            // Relaxation: Update distance to node v if a shorter path through u is found
            if (dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v}); // Push the updated distance and node to priority queue
            }
        }
    }
    
    return dist; // Return shortest path distances from node 0 to all nodes
}

int main() {
    int T;
    cin >> T; // Number of test cases
    
    while (T--) {
        int V, E;
        cin >> V >> E; // Number of vertices and edges
        
        // Create adjacency list representation of the graph
        vector<vector<pair<int, int>>> graph(V); // Each element is a vector of pairs (node, weight)
        
        for (int i = 0; i < E; ++i) {
            int X, Y, weight;
            cin >> X >> Y >> weight; // Read edge (X, Y) with weight
            graph[X].push_back({Y, weight}); // Add edge (X -> Y) with given weight
            graph[Y].push_back({X, weight}); // For undirected graph, add edge (Y -> X) as well
        }
        
        // Apply Dijkstra's algorithm from source node 0
        vector<int> distances = dijkstra(graph, V);
        
        // Output shortest path distances from source node 0 to all other nodes
        for (int i = 0; i < V; ++i) {
            cout << distances[i] << " ";
        }
        cout << "\n"; // Move to next line for the next test case
    }
    
    return 0;
}
