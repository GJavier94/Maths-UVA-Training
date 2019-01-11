#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> ii;
typedef vector<vector<ii> > vii;
typedef vector<int> vi;

int const INF = 1 << 30;

int main ( ){
	int cases; cin >>  cases;

	for(int k = 1; k <= cases; k++){
		int n,m, s ,t ;
		cin >> n >> m >> s >> t;
		vii edges(n);
		int u, v, w;
		for( int i = 0 ; i < m; i++){
			cin >> u >> v >> w;
			edges[u].push_back((ii){v,w});
			edges[v].push_back((ii){u,w});
		}

		priority_queue<ii, vector<ii>, greater<ii> > pq;
		vi dist(n,INF);
		dist[s] = 0;
		pq.push(ii(0,s));

		while(!pq.empty()){
			ii front = pq.top(); pq.pop();
			int d = front.first, u = front.second;

			if( d > dist[u]) continue;

			for(int j = 0; j < (int)edges[u].size(); j++ ){
				ii v = edges[u][j];

				if(dist[u] + v.second  < dist[v.first]){
					dist[v.first] = dist[u] + v.second;
					pq.push((ii){dist[v.first], v.first} );
				}
			}
		}

		if( dist[t] != INF)
			cout << "Case #" << k << ": " << dist[t] << endl;	
		else
			cout << "Case #" << k << ": unreachable" << endl;
		
	}
}