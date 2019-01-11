#include <bits/stdc++.h>

using namespace std;

typedef vector<vector<int> > vii;
typedef vector<int> vi;
typedef map<char , int > mapa;
typedef map<int, char > mapav;

const int INF = 1 << 30;

const int n = 50;

void printGraph(vii& edges){
	int u,v;
	for( int i = 0; i < edges.size(); i++){
		cout << i;
		for( int j = 0; j < edges[i].size(); j++){
			cout << " " <<  edges[i][j] ;
		}	
		cout << endl;
	}
}

void printPath(mapav& am, vi& p, int  s, int dest){
	if( s == dest){cout << am[s]; return;}
	printPath(am, p, s, p[dest]);
	cout << am[dest];
}

void bfs(vii& edges, mapav& am, int s, int dest){
	queue<int> q;
	vi dis(n, INF);
	q.push(s);
	dis[s] = 0;
	vi p(n);

	while(!q.empty()){
		int u = q.front(); q.pop();
		for( int i = 0 ; i < edges[u].size(); i++){
			int v = edges[u][i];
			if( dis[u] + 1 < dis[v]){
				dis[v] = dis[u] + 1;
				q.push(v);
				p[v] = u;
			}
		}
	}

	printPath(am, p, s, dest);
	cout << endl;
}

int main ( ){
	int cases; cin >> cases;
	int m, queries;
	
	bool flag = true;

	while( cases--){
		if(flag){flag = false;}
		else cout << endl;
		cin >> m >> queries;
		vii edges(n);
		mapa ma;
		mapav am;
		int var = 0;
		string s1,s2;
		char c1,c2;

		for( int i = 0; i < m; i++){
			cin >> s1 >> s2, c1 = s1[0], c2 = s2[0];			
			if(ma.find(c1) == ma.end()){ma[c1] = var; am[var] = c1; var++;}
			if(ma.find(c2) == ma.end()){ma[c2] = var; am[var] = c2; var++;}
			edges[ma[c1]].push_back(ma[c2]);
			edges[ma[c2]].push_back(ma[c1]);			
		}
		int s, dest;
		for( int i = 0; i < queries; i++){
			cin >> s1 >> s2, c1 = s1[0], c2 = s2[0];			
			s = ma[c1], dest = ma[c2];			
			bfs(edges, am, s, dest);
		}
	}
}