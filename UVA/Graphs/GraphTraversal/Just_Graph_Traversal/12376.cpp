#include <bits/stdc++.h>

using namespace std;
typedef pair<int,int> edge;
typedef vector<edge> List;
struct Graph{
	vector<List> edges;	
	int n;
	bool bi;
	Graph(int N, bool Bi = true):
	n(N),bi(Bi),edges(N,List())
	{}
	void addEdge(int u ,int v, int w){
		if(bi) edges[v].push_back(edge{u,w});
		edges[u].push_back(edge{v,w});
	}
	void bfs(int k){
		queue<int> q;
		q.push(0);
		int suma = 0;
		int max;
		int nextnodo;
		while(!q.empty()){
			int nodoActual = q.front(); q.pop();
			//cout << nodoActual<< endl;
			max = 0;
			for(int i = 0; i < edges[nodoActual].size(); i++){
				if( max < edges[nodoActual][i].second){
					max = edges[nodoActual][i].second;
					nextnodo = edges[nodoActual][i].first;
				}
			}
			if(edges[nodoActual].size()){
				suma += max;
				q.push(nextnodo);				
			}
		}	
		cout << "Case " << k << ": " << suma << " " <<  nextnodo << endl;
	}
};
int main(){
	int t; cin >> t;
	for( int k = 1; k <= t; k++){
		int n, m ; cin >> n >> m;
		Graph *g = new Graph(n,false);
		// nodo y peso 
		map<int,int> nod;
		int w;
		for(int i = 0 ; i < n ; i++)cin >> w, nod[i] = w;			
		int u,v;
		for( int i = 0; i < m ; i++)cin >> u >> v,g->addEdge(u, v , nod[v]);		
		//g->printEdges();		
		g->bfs(k);
		delete g;		
	}
	return 0;
}