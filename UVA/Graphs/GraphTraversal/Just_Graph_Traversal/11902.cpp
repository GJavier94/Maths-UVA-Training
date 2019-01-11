#include <bits/stdc++.h>

using namespace std;

typedef vector<int> List;

struct Graph{
	vector<List> edges;
	vector<int> seen;
	int n;
	bool bi;

	Graph(int N, bool Bi = true ):
	n(N), bi(Bi), edges(N,List(N)), seen(N,0)
	{}
	void addEdge(int u, int v){
		if(bi) edges[v][u] = 1;
		edges[u][v] = 1;
	}

	void dfs(int u ){
		seen[u] = 1;
		for(int v = 0; v < n; v++)
			if(edges[u][v]){
				if(!seen[v])
					dfs(v);
			}
	}
};

int main ( ){

	int t;
	int n;
	cin >> t;
	for( int  k = 1; k <= t; k++){
		cin >> n;
		Graph *g = new Graph(n, false);

		for( int i = 0; i < n ;i++)
			for( int j = 0; j < n ;j++){
				int aux; cin >> aux;
				if( aux == 1) g-> addEdge(i,j);
			}

		
		char a[n][n];
		//Revisaremos nodo por nodo (fila)
		for( int i = 0; i < n; i++){
			g->dfs(0);
			if(g->seen[i]){ // si es alcanzable
				fill( g->seen.begin(), g->seen.end(), 0);

				for( int j = 0; j < n ; j++){ // checo posibles dominantes
					if( i == j || j == 0 ){ a[j][i] = 'Y'; continue;}
					g->seen[j] = 1;
					g->dfs(0);
					if(g->seen[i])
						a[j][i] = 'N';
					else
						a[j][i] = 'Y';						
					fill( g->seen.begin(), g->seen.end(), 0);
				}				
			}else{				
				for( int j = 0; j < n ; j++) a[j][i] = 'N';
				fill( g->seen.begin(), g->seen.end(), 0);
			}
			
		}
		cout << "Case " << k << ":" << endl;
		for( int i = 0;i < n ; i++){
			cout << "+"; for(int i = 0 ;i < 2*n -1;i++) cout << "-"; cout << "+"<<endl;
			for( int j = 0 ;  j < n ;j++){
				cout << "|" << a[i][j];
			}
			cout << "|" <<endl;
		}
		cout << "+"; for(int i = 0 ;i < 2*n -1;i++) cout << "-"; cout << "+"<<endl;
		delete g;		
	}
}