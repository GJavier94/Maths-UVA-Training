#include <bits/stdc++.h>

using namespace std;

const int INF = 1 << 30;
int n;

int bfs(vector<vector<int> >& edges, int size, int s, int dest){
	queue<int> q;
	vector<int> dis(n,INF);
	q.push(s); dis[s] = 0;

	while(!q.empty()){
		int u = q.front(); q.pop();

		for( int i = 0; i < edges[u].size() ; i++){
			int v = edges[u][i];
			if( dis[u] + 1 < dis[v]){
				dis[v] = dis[u] + 1 ;
				q.push(v);
			}

		}
	}

	if( dis[dest]  == INF) return -1;
	else return dis[dest]*100*size;
}
int main ( ){

	int cases; cin >> cases;
	cout << "SHIPPING ROUTES OUTPUŢ\n\n";
	for (int i = 1; i <= cases; i++){
		cout << "DATA SET " << i  << "\n\n";
		int m, queries;
		cin >> n >> m >> queries;		
		string nodo;
		vector<vector <int > > edges(30);
		map<string,int> ma;
		for( int i = 0; i < n; i++) cin >> nodo, ma[nodo] = i;

		string nodou, nodov;
		for( int i =  0 ; i < m ; i++) 
			cin >> nodou >> nodov,
			edges[ma[nodou]].push_back(ma[nodov]),
			edges[ma[nodov]].push_back(ma[nodou]);

		int size;
		for( int i = 0; i < queries; i++){
			cin >> size >> nodou >> nodov;
			int result = bfs(edges, size, ma[nodou], ma[nodov]);
			if(result == -1 ) cout << "NO SHIPMENT POSSIBLE\n";
			else cout << "$" << result << '\n';
		}
		cout  << endl;
	}
} 