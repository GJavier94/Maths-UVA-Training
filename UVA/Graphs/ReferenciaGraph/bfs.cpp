/*
BFS

    // Busqueda en amplitud desde el nodo s.
    // Devuelve el vector de distancias a todos
    // los nodos desde s. Un valor INF indica que
    // no es posible ir de s al respectivo nodo.

grafo dirigido/bidireccional no ponderado
*/

#include <bits/stdc++.h>

using namespace std;

/*
 Se define una plantilla tipo costo  
 luego se defina una constante de tipo costo 
 INF y se le da un valor grande 


*/
typedef int Costo;
const Costo INF  = 1 << 30;

typedef vector<int> List;

struct Graph
{
	vector<List> edges;
	int n;
	bool bi;

	Graph(int N, bool Bi = true):
	n(N), bi(Bi), edges(N,List())
	{}

	void addEdge(int u, int v){
		if(bi) edges[v].push_back(u);
		edges[u].push_back(v);
	}

	vector<Costo> BFS(int u ){
		queue<int> q;
		vector<Costo> d(n, INF); // guarda los valores para llegaar al nodo desde el nodo s
		q.push(u), d[u] = 0; // el costo de ir de u hacia u 

		while(!q.empty()){
			int u = q.front(); q.pop(); //Se obtiene el valor y se saca de la cola
			for( int v: edges[u])
				if(d[u] + 1 < d[v]) // No olvidemo que todos los valores estan en INF
					d[v] = d[u] + 1, // se le asigna su valor de capa
					q.push(v); // se mete  a la cola para  luego buscar a sus adyacentes
		}
		return d;
	}

};



int main( ){
	int n,m;
	cin >> n >> m;
	Graph *g;
	g = new Graph(n);

	int u,v;

	for( int i = 0; i < m ; i++)
		cin >> u >> v, g->addEdge(--u,--v);

	vector<Costo> costos;
	for( int u = 0; u < n; u++){		
		costos = g->BFS(u);
		for(Costo c : costos)
			cout << c << " ";
		cout << endl;
	}

}
