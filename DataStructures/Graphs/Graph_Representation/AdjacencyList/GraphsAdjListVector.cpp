#include<iostream>
#include<vector>
using namespace std;

class Graph
{
    public:
    vector<vector<int>> adj;

    Graph(int n)
    {
        adj.resize(n);
    }

    void addEdge(int u, int v, bool direction)
    {
        // direction = 0 -> undirected
        // direction = 1 -> directed 

        // create an edge from u to v
        adj[u].push_back(v); // this will create an edge between u and v

        if(direction == 0) // if it's undirected, create the opposite edge as well
        {
            adj[v].push_back(u);
        }
    }

    void printAdjList()
    {
        for(int i = 0; i < adj.size(); i++)
        {
            cout << i << " -> ";
            for(auto j: adj[i])
            {
                cout << j << ", ";
            }
            cout << endl;
        }
    }

};

int main()
{
    int n;
    cout << "Enter the number of Nodes: " << endl;
    cin >> n;

    int m;
    cout << "Enter the number of Edges: " << endl;
    cin >> m;

    Graph g(n);

    for(int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        
        // creating an undirected graph
        g.addEdge(u, v, 0);
    }

    // print graph
    g.printAdjList();
    return 0;
}
