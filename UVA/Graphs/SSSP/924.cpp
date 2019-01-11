#include <bits/stdc++.h>
using namespace std;

typedef vector<vector<int> > vii;
typedef vector<int> vi;
const int INF = 1  << 30 ;
int n;

void bfs(vii& edges, int s){
	queue<int> q;
	vi dis(n, INF);
	dis[s] = 0;
	q.push(s);

	int sumLevel = 0,sumMaxima  = 0,level = 0,finalLevel = 0;
	while(!q.empty()){
		int u = q.front(); q.pop();
		if(level < dis[u]){ // se ha cambiado de nivel 
			level = dis[u];
			if( sumMaxima < sumLevel){
				sumMaxima = sumLevel,finalLevel  = level;
			}
			sumLevel = 0;
		}
		for(int i = 0; i < edges[u].size(); i++){
			int v = edges[u][i];
			if( dis[u] + 1 < dis[v]){				
				dis[v] = dis[u] + 1;
				q.push(v);
				sumLevel++;
			}
		}			
	}
	if(!sumMaxima) cout << "0" << endl;
	else 
		cout << sumMaxima << " " << finalLevel << endl;
}
int main(){
	cin >> n;cin.ignore();
	vii edges(n);
	int u, v, nv;
	for(u  = 0; u < n ; u++){cin >> nv;
		for(int j = 0; j < nv; j++){cin >> v;
			edges[u].push_back(v);			
		}		
	}
	int T; cin >> T;
	int s;
	for( int i  = 0; i < T; i++){
		cin >> s;bfs(edges,s);
	}
}