/*
	Implementation of adjacency list with weight
	Espacio de complejida 
*/

#include <bits/stdc++.h>

using namespace std;

typedef int weight;

typedef pair<int, weight> Edge;

typedef vector<Edge> List;

struct Graph
{
	vector<List> edges;
	int n;
	bool bi;

	Graph(int N, bool Bi = true):
	n(N), edges(N,List()), bi(Bi)
	{}

	void addEdge(int u, int v, weight w){
		if(bi) edges[v].push_back(Edge(u,w));
		edges[u].push_back(Edge(v,w));
	}
};

int main ( ){

	cout << " Nodos aristas" << endl;
	int n,m; cin >> n >> m;

	Graph *g;
	g = new Graph(n);
	int u, v, w;
	for(int i = 0; i < m ; i++)
		cin >> u >> v >> w, g->addEdge(--u,--v,w);

	for( int i = 0 ; i < n; i++){
		for( int j = 0;  j < g->edges[i].size();j++)
			cout << i << "con :" << g->edges[i][j].first << " peso " << g->edges[i][j].second << endl;
	}
	delete g;

	return 0;
} 