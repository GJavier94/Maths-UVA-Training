#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> ii;
typedef vector<vector<pii>> vii;

int const INF = 1 << 30;

int main ( ){
	int cases; cin >>  cases;

	for( k = 1; k <= cases; k++){
		int n,m, s ,t ;
		cin >> n >> m >> s >> t;

		edges(n);
		int u, v, w;
		for( int i = 0 ; i < m; i++){
			cin >> u >> v >> w;
			edges[u].push_back((ii){v,w});
			edges[v].push_back((ii){u,w});

		}


		cout << "Case #" << k << ": " << endl;
	}
}