#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> constructAdjacencyList(int n, const vector<vector<int>>& edges) {
    vector<vector<int>> adjList(n);

    for (auto& edge : edges) {
        int u = edge[0];
        int v = edge[1];
        adjList[u].push_back(v);
        adjList[v].push_back(u); // since the graph is undirected
    }

    for (int i = 0; i < n; ++i) {
        sort(adjList[i].begin(), adjList[i].end());
    }

    return adjList;
}

void printAdjacencyList(const vector<vector<int>>& adjList) {
    for (int i = 0; i < adjList.size(); ++i) {
        cout << i;
        for (int neighbor : adjList[i]) {
            cout << " " << neighbor;
        }
        cout << endl;
    }
}

int main() {
    int n, m;
    if (!(cin >> n >> m)) {
        cerr << "Invalid input format!" << endl;
        return 1;
    }

    vector<vector<int>> edges(m, vector<int>(2));
    for (int i = 0; i < m; ++i) {
        if (!(cin >> edges[i][0] >> edges[i][1])) {
            cerr << "Invalid edge format!" << endl;
            return 1;
        }
    }

    vector<vector<int>> adjList = constructAdjacencyList(n, edges);

    printAdjacencyList(adjList);

    return 0;
}
