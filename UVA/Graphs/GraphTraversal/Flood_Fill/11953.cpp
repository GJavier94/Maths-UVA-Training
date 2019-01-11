#include <bits/stdc++.h>

using namespace std;

char mapa[105][105];

#define FOR(i,a,b) for( int i = a; i < b; i++)
int n;

int dr[] = {1,0,-1,0};
int dc[] = {0,1,0,-1};

void dfs(int i, int j){
	if( i < 0 || j < 0 || i >= n || j >= n) return;
	if(mapa[i][j] == '.') return;

	mapa[i][j] = '.';

	FOR(d,0,4) dfs(i + dr[d], j + dc[d]);
}
int main(){
	int cases; cin >> cases;

	FOR(k,1,cases+1){
		cin >> n;
		FOR(i,0,n)FOR(j,0,n) cin >> mapa[i][j];

		int suma = 0;
		FOR(i,0,n){
			FOR(j,0,n){
				if(mapa[i][j] == 'x'){
					suma++;
					dfs(i,j);
				}
			}
		}


		cout << "Case " << k << ": " << suma <<'\n';
	}

}