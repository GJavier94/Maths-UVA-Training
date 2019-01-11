#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int > ii;
typedef vector<vector<ii> > vii;
typedef vector<int> vi;
const int INF = 1 << 30;
#define FOR(i,a,b) for(int i = a; i < b; i++ )
int main(){
	int cases; cin >> cases;
	while(cases--){
		int n, m; cin >> n >> m;
		vii edges(n);
		int u, v, w ;
		FOR(i,0,m) cin >> u >> v >> w,edges[u].push_back(ii(v,w));
		vi dis(n, INF);
		dis[0] = 0;
		FOR(i,0,n - 1)
			FOR(u,0,n)
				FOR(j,0,edges[u].size()){
					ii v = edges[u][j];
					dis[v.first] = min(dis[v.first], dis[u] + v.second );					
				}
		bool hasNegativeCycle = false;
		FOR(u,0,n)FOR(j,0,edges[u].size()){
			ii v = edges[u][j];
			if( dis[u] + v.second < dis[v.first]){
				hasNegativeCycle = true;				
			}
		}		
		if(hasNegativeCycle) cout << "possible" << endl;
		else cout << "not possible" << endl;	
	}
}