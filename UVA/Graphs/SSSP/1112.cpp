#include <bits/stdc++.h>

using namespace std;


typedef pair<int, int > ii;
typedef vector<vector<ii> > vii;
typedef vector<int > vi;

const int INF = 1 << 30;
#define FOR(i,a,b) for( int i = a; i < b; i++)

int main( ){
	int cases; cin >> cases;
	bool flag = true;
	while( cases--){
		if(flag) flag = false;
		else cout << endl;
		int n, e, t, m;
		cin >> n >> e >> t >> m, --e;		
		vii edges(n);	
		int u, v, w;
		FOR(i,0,m) cin >> u >> v >> w,edges[--u].push_back((ii){--v,w});

		int cont = 0;
		FOR(i,0,n){ // i-esimo noodo considerado como nodo origen 

			priority_queue< ii, vector<ii>, greater<ii> > pq;
			vi dis(n, INF);
			pq.push((ii){0,i});
			dis[i] = 0;

			while(!pq.empty()){
				ii front  = pq.top(); pq.pop();
				int  d  = front.first, u = front.second;
				if( d > dis[u]) continue;

				for( int j  = 0; j < edges[u].size(); j++ ){
					ii v = edges[u][j];
					if( dis[u] + v.second < dis[v.first] ){
						dis[v.first] = dis[u] + v.second;
						pq.push((ii){dis[v.first], v.first});
					}
				}
			}			
			if( dis[e] <= t ) cont++;
		}
		cout << cont << endl;
	}
}



