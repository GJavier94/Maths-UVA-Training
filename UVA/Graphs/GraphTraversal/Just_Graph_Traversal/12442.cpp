#include <bits/stdc++.h>

using namespace std;

typedef vector<int> List;

typedef pair<int, int> marciano;
// suma y marciano respectivamente
int suma;

struct Graph{
	vector<List> edges;
	vector<int> seen;
	int n ;
	int bi;

	Graph(int N, int Bi = true):
	n(N), bi(Bi), edges(N,List()), seen(N,0)
	{}

	void addEdge(int u , int v){
		if(bi) edges[v].push_back(u);
		edges[u].push_back(v);
	}

	void dfs(int u ){
		suma++;
		seen[u] = 1;
		for(int v : edges[u]){
			if(!seen[v])
				dfs(v);			
		}
		seen[u] =0;
	}
};

int main(){
	int t;
	cin >> t;
	for( int k = 1; k <= t; k++){
		int n; // number of nodes
		cin >> n;
		int u, v;
		Graph *g = new Graph(n,false);
		for( int i = 0; i < n ; i++) cin >> u >> v, g->addEdge(--u,--v);
		
		int sumaFinal = 0;
		int marcian = 0 ;
		for(int i = 0; i < n ; i++){
			suma = 0;
			g->dfs(i);

			if( suma > sumaFinal)
				sumaFinal = suma, marcian = i;

			
		}
				
		cout << "Case " << k << ": " << marcian + 1 << endl;

	}
}