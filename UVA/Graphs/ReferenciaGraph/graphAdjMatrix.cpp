/*

Implementation de matriz de  adyacencia
complejidad espacial de n²
*/

#include <bits/stdc++.h>

using namespace std;

typedef vector<int> List;

struct Graph
{		
	vector<List> edges;// |E|
	bool bi;
	int n;// |V|
	Graph(int N , bool Bi = true):
	n(N), edges(N,List(N,0)),bi(Bi)
	{}

	void addEdge( int u , int v){
		if( bi) edges[v][u] = 1;
		edges[u][v] = 1; 

		// si fuera un grafo ponderado se les carga el peso 
	}
};


int main( ){

	Graph *g;
	cout << " nodos, aritas" << endl;
	int n , m;
	cin >> n >> m;
	g = new Graph(n);
	int u, v ;
	for( int i = 0; i < m ; i++)
		cin >> u >> v,--u,--v, g->addEdge(u,v);

	for( int i = 0 ; i < n ; i++){
		for( int j = 0 ; j < m; j++){
			cout  << " " << g->edges[i][j];
		}
		cout << endl;
	}
}