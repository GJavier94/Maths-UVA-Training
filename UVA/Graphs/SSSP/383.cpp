#include <bits/stdc++.h>

using namespace std;
int n;
const int INF = 1 << 30;

int bfs(vector<vector<int> >& edges, int sizeCh, int s, int dest){

	vector<int> dis(n, INF);
	queue<int> q;
	q.push(s); dis[s] = 0;

	while(!q.empty()){
		int u = q.front(); q.pop();

		for( int  i = 0; i < edges[u].size(); i++){
			int v = edges[u][i];
			if ( dis[u] + 1 < dis[v]){ // no ha sido visitados
				dis[v] = dis[u] + 1 ;
				q.push(v);
			}
		}
	}
	
	if(dis[dest] == INF) return -1;
	else return dis[dest]*100*sizeCh;
}

int main ( ){

	int cases; cin >> cases;
	cout << "SHIPPING ROUTES OUTPUT\n\n";

	for (int i = 1; i <= cases; i++){
		cout << "DATA SET "	 <<  i << "\n\n";
		int m,queries; cin >> n >> m >> queries;
		vector< vector<int> > edges(30);
		
		map<string, int > mapeo;
		string nodou, nodov;
		for( int i = 0 ; i < n; i++)
			cin >> nodou, mapeo[nodou] = i;

		for(int i = 0 ;i < m; i++){
			cin >> nodou >> nodov;
			edges[mapeo[nodou]].push_back(mapeo[nodov]);
			edges[mapeo[nodov]].push_back(mapeo[nodou]);
		}
		int size, result;
		for( int i = 0 ; i < queries; i++){
			cin >> size >> nodou >> nodov;			
			result = bfs(edges, size, mapeo[nodou], mapeo[nodov]);
			if(result == -1 ) cout << "NO SHIPMENT POSSIBLE" << '\n' ;
			else cout << "$" <<  result  << '\n';
			
		}
		cout << "\n" ;
	}
	cout << "END OF OUTPUT" << '\n';
}