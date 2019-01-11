#include <bits/stdc++.h>

using namespace std;

typedef vector<int> List;

typedef pair<int, int> marciano;

vector<int> sumas;
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

	int dfs(int u ){
		int total = 0;
		seen[u] = 1;		
		for(int v : edges[u]){
			if(!seen[v]){
				total += 1 + dfs(v);							
			}
			seen[u] = 0 ;
			return sumas[u] = total;
		}
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
		sumas.assign(n,-1);

		int marciano = 0; int sumaFinal = 0;
		for(int i = 0; i < n ; i++){						
			if(sumas[i] == -1) g->dfs(i);
			if(sumas[i] > sumaFinal ){
				sumaFinal = sumas[i];
				marciano = i;
			}
		
		}
		
		cout << "Case " << k << ": " << marciano + 1 << endl;
	}
}