#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int > ii;
typedef vector<vector<ii> > vii;
typedef vector<int> vi;

const int INF = 1 << 30;

#define FOR(i,a,b) for( int i = a ; i < b; i++)

bool bfs(vii& edges, int v, int n){
	queue<int> q;
	vi dis(n, INF);
	dis[v] = 0;
	q.push(v);

	while(!q.empty()){
		int u = q.front(); q.pop();
		for( int i = 0 ; i < edges[u].size(); i++){
			int v = (edges[u][i]).first;
			if( dis[u] + 1 < dis[v]){
				dis[v] = dis[u] + 1;
				q.push(v);
			}
		}
	}

	if(dis[n - 1] == INF) return false;

	return true;
}

int main ( ){
	int n; 

	while(cin >> n && n != -1 ){
		
		vii edges(n);
		int w, nv;
		FOR(u,0,n){
			cin >> w >> nv;
			FOR(j,0,nv){
				int v; cin >> v, --v;				
				edges[u].push_back(ii(v, (-1)*w));
			}
		}

		vi dist(n,INF);
		dist[0] = -100;

		FOR(i,0, n - 1){
			FOR(u,0,n){
				FOR(j,0,edges[u].size()){
					ii v = edges[u][j];
					if( dist[u] + v.second  < 0)
						dist[v.first] = min( dist[v.first], dist[u] + v.second );
				}
			}
		}
		int f = n - 1;		
		if(dist[f]*(-1) > 0 ){ cout << "winnable" << endl; continue;}

		bool isReach = false;

		FOR(u, 0, n){
			FOR(j, 0, edges[u].size()){
				ii v = edges[u][j];
				if( dist[u] + v.second < dist[v.first] && ( dist[u] + v.second ) < 0){
					//cout << u + 1 << "  " << v.first + 1<< endl;
					isReach = bfs(edges, v.first , n);
				}
			}
		}
		if(isReach) cout << "winnable" << endl;
		else cout << "hopeless" << endl;

	}
}