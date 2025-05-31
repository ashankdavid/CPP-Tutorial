#include<bits/stdc++.h>
using namespace std;

class UnionFind{
	private:
	vector<int> parent;
	vector<int> rank;

	public:
	UnionFind(int n){
		parent.resize(n);
		rank.resize(n);

		// populate parents[] with their node parents
		for(int i=0; i<n; i++){
			parent[i] = i;
		}
	}
	int find(int u){
		if(parent[u] != u)
			parent[u] = find(parent[u]);

		return parent[u];
	}

	bool union_set(int u, int v){
		int root_u = find(u);
		int root_v = find(v);

		if(root_u != root_v){
			// union by rank
			if(rank[root_u] > rank[root_v])
				parent[root_v] = root_u;
			else if(rank[root_u] < rank[root_v])
				parent[root_u] = root_v;
			else{
				parent[root_v] = root_u;
				rank[root_u]++;
			}
			return true;
		}
		return false;
	}
};

int mstKrushKal(vector<vector<int>> &edges, int n){
	sort(edges.begin(), edges.end());
	UnionFind uf(n);
	int mst_weight = 0;

	for(auto edge : edges){
		int w = edge[0];
		int u = edge[1];
		int v = edge[2];

		if(uf.union_set(u, v)){
			mst_weight += w;
		}
	}
	return mst_weight;
}

int main(){
	int V, E;
	cin >> V >> E;

	vector<vector<int>> edges;

	for(int i=0; i<E; i++){
		int u, v, w;
		cin >> u >> v >> w;
		edges.push_back({w, u, v});
	}

	int mstWeight = mstKrushKal(edges, V);
	cout << mstWeight << endl;

	return 0;
}