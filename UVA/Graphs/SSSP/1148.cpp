#include <bits/stdc++.h>

using namespace std;

typedef vector<vector<int> > vii;
typedef vector<int> vi;
const int INF = 1 << 30;
int n;
int bfs(vii& edges, int source, int destination){
	queue<int> q;
	vi dis(n,INF);
	q.push(source);
	dis[source] = 0;

	while(!q.empty()){
		int u = q.front(); q.pop();
		for( int i = 0; i < edges[u].size(); i++){
			int v = edges[u][i];
			if( dis[u] + 1 < dis[v]){
				dis[v] = dis[u] + 1;
				q.push(v);
			}
		}
	}
	cout << source << " " << destination << " " << dis[destination] - 1 << endl;
}
int main ( ){
	int cases; cin >> cases;
	bool flag  = true;
	while(cases--){
		if(flag) flag = false;
		else cout << endl;
		cin >> n;
		vii edges(n);
		for( int i = 0 ; i < n ; i++){
			int nodo; int numV;
			cin >> nodo >> numV;
			for( int j = 0;  j < numV; j++){
				int v; cin >> v;
				edges[i].push_back(v);
			}
		}
		int source, destination;
		cin >> source >> destination;
		bfs(edges, source, destination);

	}
}