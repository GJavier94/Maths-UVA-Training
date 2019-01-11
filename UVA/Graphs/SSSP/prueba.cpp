#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int > ii;
typedef vector<vector<ii> > vii;
typedef vector<int> vi;

const int INF = 1 << 30;

#define FOR(i,a,b) for( int i = a; i < b; i++)
int main ( ){
	int k = 0;

	while(scanf("%d", &n) == 1 ){
		vii edges(n);
		vi c(n);
		FOR(i,0,n) cin >> c[i];

		int r; cin >> r;

		int u, v, w;
		FOR(i,0,r){
			cin >> u >> v, --u, --v;
			w = (c[v] - c[v]) * (c[v] - c[v]) * (c[v] - c[v]);
			edges[u].push_back(ii(v,w));
		}

		int queries, destino;
		cin >> queries;
		k++;
	}
}