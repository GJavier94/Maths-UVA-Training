#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vii;

int N;
int num;

#define FOR(i,a,b) for( int i = a ; i < b; i++)

int dr[] = {1,1,0,-1,-1,-1, 0, 1};
int dc[] = {0,1,1, 1, 0,-1,-1,-1};

void dfs(vii& mapa, vii&  vis, int i, int j){
	if(i < 0 || j < 0  || i >= N || j >= N) return;
	if(vis[i][j]) return;
	if(mapa[i][j] == 0 ) return;
	vis[i][j] = 1;	
	num++;
	FOR(d, 0, 8){
		dfs(mapa, vis, i + dr[d] , j + dc[d] );
	}
}

int main ( ){
	int k = 0;
	while(cin >> N ){
		k++;
		vii mapa(N, vi(N));
		vii vis(N, vi(N));
		string row;
		cin.ignore();
		FOR(i,0,N){
			getline(cin, row);
			FOR(j,0,N) mapa[i][j] = row[j] - '0';
		}

		// FOR(i,0,N){
		// 	FOR(j,0,N){
		// 		cout << mapa[i][j];
		// 	}
		// 	cout << endl;
		// }

		
		int comp = 0;
		
		FOR(i,0,N){
			FOR(j,0,N){
				if(mapa[i][j] == 1  && vis[i][j] == 0 ){
					comp++;					
					dfs(mapa, vis, i, j);					
				}
			}			
		}
		cout << "Image number "<< k << " contains " << comp << " war eagles." << endl;
	}
} 