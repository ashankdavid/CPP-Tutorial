#include <iostream>
#include <vector>

using namespace std;

class Graph {
private:
    int V; // number of vertices
    vector<vector<int>> adjMatrix;

public:
    // Constructor to initialize the graph with V vertices
    Graph(int vertices) {
        V = vertices;
        adjMatrix.resize(V, vector<int>(V, 0)); // Initialize VxV matrix with 0
    }

    // Function to add an edge between vertex u and vertex v
    void addEdge(int u, int v) {
        adjMatrix[u][v] = 1; // Assuming it's an unweighted graph
        adjMatrix[v][u] = 1; 
    }

    // Function to print the adjacency matrix
    void printAdjMatrix() {
        cout << "Adjacency Matrix:" << endl;
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                cout << adjMatrix[i][j] << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    // Create a graph with 5 vertices
    Graph graph(6);

    // Add edges
    graph.addEdge(0, 1);
    graph.addEdge(0, 3);
    graph.addEdge(1, 2);
    graph.addEdge(1, 3);
    graph.addEdge(2, 3);
    graph.addEdge(2, 4);
    graph.addEdge(2, 5);
    graph.addEdge(3, 4);
    graph.addEdge(4, 5);

    // Print adjacency matrix
    graph.printAdjMatrix();

    return 0;
}
