#include <iostream>
#include <vector>

using namespace std;

// Function to perform DFS traversal of the graph
void dfsTraversalUtil(int node, const vector<vector<int>>& adjacencyList, vector<bool>& visited, vector<int>& traversalOrder) {
    visited[node] = true;
    traversalOrder.push_back(node);

    // Traverse neighbors of the current node
    for (int neighbor : adjacencyList[node]) {
        if (!visited[neighbor]) {
            dfsTraversalUtil(neighbor, adjacencyList, visited, traversalOrder);
        }
    }
}

vector<int> dfsTraversal(int n, const vector<vector<int>>& adjacencyList) {
    vector<bool> visited(n, false); // Keep track of visited nodes
    vector<int> traversalOrder; // To store the DFS traversal order

    // Start DFS from vertex 0
    dfsTraversalUtil(0, adjacencyList, visited, traversalOrder);

    return traversalOrder;
}

int main() {
    int n, m;
    cin >> n >> m; // Number of vertices (n) and edges (m)

    vector<vector<int>> adjacencyList(n);

    // Read edges and construct adjacency list
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        adjacencyList[u].push_back(v);
    }

    // Perform DFS traversal starting from vertex 0
    vector<int> result = dfsTraversal(n, adjacencyList);

    // Output the traversal order
    for (int node : result) {
        cout << node << " ";
    }
    cout << endl;

    return 0;
}







// Difficult One

// #include <iostream>
// #include <vector>

// using namespace std;

// // Depth-First Search (DFS) function to explore a connected component
// void dfs(int node, vector<vector<int>>& adj_list, vector<bool>& visited, vector<int>& component) {
//     visited[node] = true;       // Mark the current node as visited
//     component.push_back(node);  // Add the current node to the component

//     // Explore all neighboring nodes (adjacent vertices)
//     for (int neighbor : adj_list[node]) {
//         if (!visited[neighbor]) {
//             dfs(neighbor, adj_list, visited, component);  // Recursively visit unvisited neighbors
//         }
//     }
// }

// // Function to find all connected components using DFS
// vector<vector<int>> depthFirstSearch(int V, vector<vector<int>>& edges) {
//     // Initialize adjacency list for the graph
//     vector<vector<int>> adj_list(V);

//     // Construct adjacency list from the given edges (assuming undirected graph)
//     for (auto& edge : edges) {
//         int u = edge[0];
//         int v = edge[1];
//         adj_list[u].push_back(v);
//         adj_list[v].push_back(u);  // Add both directions for undirected graph
//     }

//     vector<bool> visited(V, false);     // Array to track visited nodes
//     vector<vector<int>> components;     // Vector to store all connected components

//     // Traverse all nodes and perform DFS from each unvisited node
//     for (int i = 0; i < V; ++i) {
//         if (!visited[i]) {
//             vector<int> component;       // Create a new component vector
//             dfs(i, adj_list, visited, component);  // Explore the component starting from node i
//             components.push_back(component);       // Add the component to the list of components
//         }
//     }

//     return components;  // Return the list of connected components
// }

// int main() {
//     int V, E;
//     cout << "Enter number of vertices (V) and number of edges (E): ";
//     cin >> V >> E;

//     vector<vector<int>> edges(E, vector<int>(2));
//     cout << "Enter edges (format: u v):" << endl;
//     for (int i = 0; i < E; ++i) {
//         cin >> edges[i][0] >> edges[i][1];  // Read each edge (u, v)
//     }

//     // Find all connected components in the graph using DFS
//     vector<vector<int>> components = depthFirstSearch(V, edges);

//     // Output the number of components and each component's vertices
//     cout << "Number of connected components: " << components.size() << endl;
//     for (const auto& component : components) {
//         cout << "Component:";
//         for (int vertex : component) {
//             cout << " " << vertex;  // Print each vertex in the component
//         }
//         cout << endl;
//     }

//     return 0;
// }
