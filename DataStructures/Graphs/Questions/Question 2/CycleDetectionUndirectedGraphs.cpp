#include<iostream>
#include <unordered_map>
#include<queue>
#include<list>
#include <vector>
#include <string>
using namespace std;

bool iscyclicBFS(int src,unordered_map<int,bool> &visited,   unordered_map<int,list<int>> adj){
    unordered_map<int,int> parent;
    parent[src]=-1;
    visited[src]=1;
    queue<int> q;
    q.push(src);
    while(!q.empty()){
        int front = q.front();
        q.pop();
        
        for(auto neighbour: adj[front]){
            if(visited[neighbour]==true && neighbour!=parent[front]){
                return true;
            }
            else if(!visited[neighbour]){
                q.push(neighbour);
                visited[neighbour]=1;
                parent[neighbour]=front;
            }
        }
    }
    return false;
}

bool iscyclicDFS(int node,int parent, unordered_map<int,bool> &visited, unordered_map<int,list<int>> &adj){
    visited[node]=true;
    for(auto neighbour: adj[node]){
        if(!visited[neighbour]){
            bool cycledetected=iscyclicDFS(neighbour, node,visited,adj);
            if(cycledetected)
                return true;
        }
        else if(neighbour != parent){
           //cycle present
            return true;
        }
    }
 return false;
}

string cycleDetection (vector<vector<int>>& edges, int n, int m)
{
    // create adjacency list
    unordered_map<int,list<int>> adj;
    for(int i=0;i<m;i++){
        int u = edges[i][0];
        int v = edges[i][1];
        
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    //to handle disconnected components 
        unordered_map<int,bool> visited;
    for(int i=0;i<n;i++){
        if(!visited[i]){
            // bool ans = iscyclicBFS(i,visited,adj);
            bool ans = iscyclicBFS(i,visited,adj);
            if(ans == 1){
                return "Yes";
            }
                
        }
    }
    return "No";
}
int main() {
    int n, m; // Number of vertices (n) and edges (m)
    cout << "Enter the number of vertices (n) and edges (m): ";
    cin >> n >> m;

    vector<vector<int>> edges(m, vector<int>(2));
    cout << "Enter the edges (in format u v where u and v are vertices):" << endl;
    for (int i = 0; i < m; ++i) {
        cin >> edges[i][0] >> edges[i][1];
    }

    string result = cycleDetection(edges, n, m);
    cout << "Cycle detected? " << result << endl;

    return 0;
}