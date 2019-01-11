#include <bits/stdc++.h>

using namespace std;

typedef vector<vector<int> > vii;
typedef vector<int> vi;

const int INF = 1 << 30;

int p;

void bfs(vii& edges, int s ){
	queue<int> q;
	vi dis(p, INF);
	q.push(s);
	dis[s] = 0;

	while(!q.empty()){
		int u = q.front(); q.pop();
		for(int i = 0; i < edges[u].size(); i++){
			int v = edges[u][i];
			if( dis[u] + 1 < dis[v]){
				dis[v] = dis[u] + 1;				
				q.push(v);
			}
		}
	}
	for( int i = 1; i < p ; i++){
		cout << dis[i] << endl;
	}
}

int main ( ){

	int cases; cin >> cases;
	int d;
	bool flag = true;
	while(cases--){
		if(flag) flag = false;else cout << endl;		
		cin >> p >> d;
		int u, v ;
		vii edges(p);

		for( int i = 0; i < d; i++){
			cin >> u >> v;			
			if( find(edges[u].begin(),edges[u].end(), v) != edges[u].end() ) continue;
			edges[u].push_back(v);
			edges[v].push_back(u);
		}
		bfs(edges,0);
	}
}