#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;

typedef int weight;

typedef pair<int,weight> edge;

typedef vector<edge> List;

typedef int Costo;

const Costo INF  = 1 << 30;

Costo maxi;
struct Graph
{
	vector<List> edges;
	int n;
	bool bi;

	Graph(int N, bool Bi = true ):
	n(N), bi(Bi), edges(N, List())
	{}

	void addEdge(int u, int v, weight w ){
		if(bi) edges[v].push_back( edge(u,w) );
		edges[u].push_back( edge(v,w) );
	}
	vector<Costo> BFS(int u ){
		queue<int> q;
		vector<Costo> d(n, INF);
		q.push(u), d[u] = 0; // ir del nodo origen al nodo origen
		while(!q.empty()){
			int u = q.front(); q.pop();			

			for(  edge e: edges[u]){
				int v = e.first;
				int w = e.second;				
				if(d[u] + w < d[v]){
					d[v] = d[u] + w;					
					q.push(v);
				}					
			}				
		}		
		return d;
	}
};

int main(){
	int n, m;
	int k = 1;
	while( cin >> n && n != 0){	
		
		cin >> m;
		Graph *g;
		g = new Graph(n);
		int u, v, w;
		for(int i = 0; i < m ; i++)
			cin >> u >> v >> w, g->addEdge(--u,--v, w);
		vector<Costo> d = g->BFS(0);

		double maxi = 0, pmaxi = 0;
		int  mu = 0, mv = 0;
		for( int i = 0; i < n ; i++){
			for( int j = 0; j < g->edges[i].size() ;j++){
				int u = i, v = g->edges[i][j].first;
				int wuv =  g->edges[i][j].second;

				if( wuv !=  abs( d[u] - d[v]) ){
					pmaxi = max(d[u], d[v]) + (double)abs( wuv - abs( d[u] - d[v]) )/2.0;
					if(maxi < pmaxi){maxi = pmaxi, mu = u, mv = v; }
				}
				//cout << i << " " <<  g->edges[i][j].first << " " << g->edges[i][j].second << endl;
			}
		}
		//cout << endl;

		vector<Costo> :: iterator it;
		it = max_element(d.begin(), d.end());
		int indMaxKey = it - d.begin();
		double valMaxKey = (double)*it;

		cout << "System #" << k++ << endl;
		if( n == 1 ){printf("The last domino falls after 0.0 seconds, at key domino 1.\n");}		
		else{
			if( maxi < valMaxKey){
			printf("The last domino falls after %.1lf seconds, at key domino %d.\n", valMaxKey, ++indMaxKey);
			}else{
			printf("The last domino falls after %.1lf seconds, between key dominoes %d and %d.\n", maxi, ++mu, ++mv );
			}
		}
		
		cout << endl;
	}	
}