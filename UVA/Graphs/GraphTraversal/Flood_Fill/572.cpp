#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vii;

typedef vector<char> vc;
typedef vector<vc> vcc;

int M, N;
#define FOR(i, a, b ) for( int i = a ; i < b; i++)

// int dr[8][2] = {{0,1},{1,0},{-1,0},{0,-1},
// 				{1,-1},{1,1},{-1,1},{-1,-1}
// 				};

int dr[] = {1,1,0,-1,-1,-1, 0, 1};
int dc[] = {0,1,1, 1, 0,-1,-1,-1};

void dfs(vcc& mapa, vii& vis,int  i, int j){
	if(i < 0 || j < 0 || i >= M || j >= N) return;
	if(vis[i][j]) return;
	if(mapa[i][j] == '*') return;
	vis[i][j] = 1;
	FOR(d,0,8){
		dfs(mapa, vis, i + dr[d],  j + dc[d]);
	}
}

int main ( ){

	while(cin >> M >> N && M){
		vcc mapa(M, vc(N));
		vii vis(M, vi(N));
		FOR(i,0,M) FOR(j,0,N) cin >> mapa[i][j];

		int contador = 0;
		FOR(i,0,M){
			FOR(j,0,N){
				if(mapa[i][j] == '@' && vis[i][j] == 0){
					contador++;
					dfs(mapa, vis, i, j);
				}

			}	
		}		 
		cout << contador << endl;
	}
}