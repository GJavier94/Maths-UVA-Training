#include <bits/stdc++.h>

using namespace std;
typedef vector<char> vc;
typedef vector<vc> vcc;

typedef vector<int> vi;
typedef vector<vi> vii;

#define FOR(i,a,b) for(int i = a ; i < b; i++)

int m, n;
bool flag;
int sumaOro;
int sumaMaxima;

int dr[] = {-1,1,0,0};
int dc[] = {0,0,1,-1};

void dfs(vcc& mapa,vii& vis, int i, int j){
	if(!flag) return;
	if(i < 0 || j < 0 || i >= m || j >= n) return;	
	if(mapa[i][j] == '#') return;
	if(mapa[i][j] == 'T') return;
	if(vis[i][j]) return;
	vis[i][j] = 1;

	if(mapa[i][j] == 'G'){sumaOro++;}
	
	FOR(d,0,4) dfs(mapa, vis, i + dr[d], j + dc[d]);
}

int main ( ){
	while(cin >> n >> m){
		vcc mapa(m, vc(n));
		vii vis(m, vi(n));
		int ix,iy;
		FOR(i,0,m)FOR(j,0,n){cin >> mapa[i][j]; if(mapa[i][j] == 'P') ix = i,iy = j; } 
		FOR(i,0,m){
			FOR(j,0,n){
				cout << mapa[i][j];
			}
			cout << endl;
		}

		sumaOro = 0;
		sumaMaxima = 0;
		flag = true;
		dfs(mapa,vis,ix, iy);
		if(flag) cout << sumaOro << endl;
		else cout << sumaMaxima << endl;

	}
}