#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vii;

int n;

#define FOR(i,a,b) for( int i = a; i < b; i++)

void dfs(vii& edges,vi& vis, int u){
	vis[u] = 1;
	FOR(j,0, edges[u].size()){
		int v = edges[u][j];
		if(!vis[v]){
			dfs(edges,vis,v);
		}
	}
}

int main ( ){	
	int cases; cin >> cases;
	bool flag = true;
	while( cases--){

		if(flag) flag = false;
		else cout << endl;

		char nod; cin >> nod;
		n = nod-'A', n++;		
		vii edges(n);
		vi vis(n);
		int u, v;
		string line;
		cin.ignore();
		while( getline(cin, line) && line.size( ) != 0  ){
			u = line[0] - 'A', v = line[1] - 'A';
			edges[u].push_back(v);
			edges[v].push_back(u);					
		}		
		int contador = 0;
		FOR(u, 0, n){
			if(!vis[u]){
				contador++;
				dfs(edges,vis,u);
			}			
		}
		cout << contador << endl;
	}
}


