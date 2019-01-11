#include <bits/stdc++.h>
using namespace std;
typedef int weight;
typedef pair<int, weight> edge;
typedef vector<edge> List;
typedef int Costo;
const Costo INF =  1 << 30;
struct Graph{
	vector<List> edge;
	int n;
	bool bi;

	Graph(int N, bool Bi = true):
		n(N), bi(Bi), edges(N,List())
	{}

	void addEdge(int u , int v, weight w){
		if(bi) edge[v].push_back(edge(u,w));
		edge[u].push_back(edge(v,w));
	}

	vector<Costo> BFS(int u ){
		vector<Costo> d(n, INF);
		queue<int> Q;
		Q.push(u);
		d[u] = 0;

		while(!Q.empty()){
			int u = Q.front(); Q.pop();

			for( int i = 0; i < edges[u].size(); i++){
				int v = edges[u][i].first;
				int w = edges[u][i].second;
				if( d[u] + w < d[v]){
					d[v] = d[u] + w;
					Q.push(v);
				}				
			}
		}
	}
};
int main(){
	int n , m, t; // t = cases
	for( int k = 1; k <= t; k++){
		cin >> n >> m;
		Graph *g = new Graph(n);
		int u, v, w;
		for( int i = 0 ; i < m ; i++)cin >> u >> v >> w, g-> addEdge(--u, --v, w );		
		vector<Costo> costos = g->BFS(0);

		for( int i = 0 ; i < n ; i++){
			cout << i + 1  << " " << costos[i]  << endl;
		}
		delete g; // para liberar memoria
	}
	return 0;
}