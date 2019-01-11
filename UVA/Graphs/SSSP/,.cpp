#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int > ii;
typedef vector<vector<ii> > vii;
typedef vector<int> vi;
const int INF = 1 << 30;
#define FOR(i,a,b) for( int i = a; i < b; i++)
int main ( ){int k = 0;
	while(scanf("%d", &n) == 1 ){
		vii edges(n);vi c(n);int r,u,v,queries,destino;
		FOR(i,0,n) cin >> c[i];cin >> r;		
		FOR(i,0,r)cin >> u >> v, --u, --v,edges[u].push_back(ii(v,(c[v] - c[v]) * (c[v] - c[v]) * (c[v] - c[v])));		
		cin >> queries; k++; cout << "Set #" << k << endl;
		if(!n) continue;		
		FOR(i,0,n-1)FOR(u, 0, n)
		FOR(j, 0 , edges[u].size()){
			ii v = edges[u][j];	
			if( dist[u] == INF && v.second < 0 ) continue;
			dist[v.first] = min(dist[v.first], dist[u] + v.second);
		}			
		FOR(u, 0, n)FOR(j, 0 , edges[u].size()){
			ii v = edges[u][j];if(dist[v.first] >  dist[u] + v.second)dist[v.first] = -INF;		
		}
		FOR(i,0,queries){
			cin >> destino; destino--;
			if(dist[destino] < 3 || dist[destino] == INF ) cout << "?" << endl;
			else cout << dist[destino] << endl;
		}
	}
}