#include <bits/stdc++.h>
#define max 85
char mapa[max][max];
int visitados[max][max];

char mark;
#define FOR(i,a,b) for(int i = a; i < b; i++)


int dr[] = {1,0,-1,0};
int dc[] = {0,1,0,-1};
int m, n ;
void dfs(int i, int j){
	if(mapa[i][j] == 'X') return;
	if(visitados[i][j]) return;
	visitados[i][j] = 1;
	mapa[i][j] = mark;
	FOR(d,0,4) dfs(i + dr[d], j + dc[d]);
}


int main(){

	int R;
	while(gets(mapa[0])){
		int ind = 1;
		memset(visitados,0,sizeof(visitados));
		while(gets(mapa[ind])){
			if(mapa[ind][0] == '_') break;
			ind++;
		}
		R = ind;
		FOR(i,0,R){
			for( int j = 0; mapa[i][j] != '\0';  j++){
				if(mapa[i][j] != 'X' && mapa[i][j] != ' ' && !visitados[i][j] ){
					mark = mapa[i][j];
					dfs(i,j);
					mapa[i][j] = mark;
				}
			}
		}

		for(int i = 0 ; i <= R ;  i++){
			puts(mapa[i]);			
		}

		memset(mapa, '\0', sizeof(mapa));
	}
}