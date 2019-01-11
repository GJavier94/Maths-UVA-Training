#include <bits/stdc++.h>

using namespace std;

#define maxM 35
#define maxN 85

char mapa[maxM][maxN];
int  visitados[maxM][maxN];
#define FOR(i,a,b) for( int i = a; i < b ; i++)

int m, n ;
char car;

int dr[] = {1,0,-1,0};
int dc[] = {0,1,0,-1};

void dfs(int i, int j ){
	if( i < 0 || j < 0 || i >= m || j >= n) return;
	if( (mapa[i][j] >= 32 &&  mapa[i][j] <= 126) && mapa[i][j] != '*' && mapa[i][j] != '_' && mapa[i][j] != ' ' ) return;
	if(visitados[i][j]) return;
	visitados[i][j] = 1;
	mapa[i][j] = '#';
	FOR(d,0,4) dfs(i + dr[d], j + dc[d]);

}
int main(){
	int cases; cin >> cases; 
	cin.ignore();	
	//bool flag = true;
	while(cases--){
		memset(mapa,'\0', sizeof(mapa));
		memset(visitados, 0 , sizeof(visitados));
		int ind = 0;

		while( gets(mapa[ind]) ){
			if(mapa[ind][0] == '_') break;
			ind++;
		}
		m = ind, n = maxN;

		FOR(i,0,m){
			for(int j = 0; mapa[i][j] != '\0' ; j++ ){
				if( mapa[i][j]  == '*' && !visitados[i][j]){							
					dfs(i,j);
				}
			}
		}
		// int inicio;
		// if(flag) inicio = 1, flag = false;
		// else inicio = 0;
		FOR(i,0,m+1){
			for(int j = 0; mapa[i][j] != '\0' ; j++ ){
				printf("%c",mapa[i][j]);
			}
			printf("\n");				
		}

	}

}