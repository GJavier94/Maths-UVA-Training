#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;
typedef vector<vector<ii> > vii;
typedef vector<int> vi;

const int INF = 1 << 30;

int main ( ){

	int n, m ;
	cin >> n >> m;

	vii edges(n);
	int u, v , w;

	for( int i = 0; i < m ; i++){
		cin >> u >> v >> w;
		edges[u].push_back((ii){v,w});
		edges[v].push_back((ii){u,w});
	}
	int s,d;
	cin >> s >> d ;

	priority_queue<ii, vector<ii>, greater<ii> > pq;
	vi dis(n, INF );
	pq.push((ii){0,s});
	dis[s] = 0;

	while(!pq.empty()){
		ii front = pq.top(); pq.pop();
		
	}

}
