/*
	Implementation of adjacency list 
*/
//inicio =  16:35



#include <bits/stdc++.h>

using namespace std;

typedef vector<int> List;

struct Graph{
	vector<List> edges;
	bool bi;
	int n;

	Graph(int N, bool Bi = true):
		n(N),edges(N, List()), bi(Bi){}
	
	void addEdge(int u, int v)	{
		if(bi) edges[v].push_back(u);
		edges[u].push_back(v);
	}

};

int main ( ){
	Graph *g; //apuntador a grafo 
	int n,m ; // numero de nodos, numero de aristas
	cout << " nodos : aristas" << endl;
	cin >> n >> m;


	g =  new Graph(n,false); // se crea un grafo bidireccional al omitir la bandera
	int u, v; // los dos nodo que se van  conectar
	for( int i  = 0 ; i < m; i++ ){
		cout << "Introduce el nodo y arista que estan conectados" << endl;
		cin >> u >> v, --u, --v,
		g->addEdge(u,v); // se pueden usar comas par a
		// escribir sentencias qu eno tiene que ver con proceoso
		//se  le da decremente si se recibe uno indexado y se  requiere 0 indexado
		// se utiliza operador flecha ya que que  se esta usando un apuntador 
	}

	cout << "Impresion del grafo" << endl;

	for( int i = 0; i < n ; i++){
		for( int j = 0; j < g->edges[i].size(); j++)
			cout << " El nodo " << i << " con nodo " << g->edges[i][j] << endl;
	}


	delete g;

	return 0;	
}