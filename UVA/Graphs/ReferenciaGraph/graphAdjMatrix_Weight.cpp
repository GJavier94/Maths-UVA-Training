/*
Implementation of adjacency matrix with weight
Complexicity space of  n²
*/


#include <bits/stdc++.h>

using namespace std;

typedef int weight;

typedef vector<weight> List;

struct Graph
{
	vector<List> edges;
	bool bi;
	int n;

	Graph(int N, bool Bi = true):
	n(N), edges(N, List(N)), bi(Bi)
	{}
	void addEdge(int u,int v, weight w){
		if(bi) edges[v][u] = w;
		edges[u][v] = w;

		// en el caso de que sea no dirigido se carga a asi 
	}
};

int main ( ){

	Graph *g;
	int n,m;
	cout << "Nodos, aristas" << endl;
	cin >> n >> m;
	int u,v;
	weight w ;

	g = new Graph(n);

	for(int i = 0 ; i < m ;i++)
		cin >> u >> v >> w, g-> addEdge(--u,--v, w);

	for( int i  = 0; i < n ; i++){

		for (int j = 0; j < g->edges[i].size(); j++)
		{
			cout << g->edges[i][j] <<  " ";
		}
		cout << endl;
	}

		
	delete g;

	return 0;	
}




