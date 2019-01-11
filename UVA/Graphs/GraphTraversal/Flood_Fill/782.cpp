#include <bits/stdc++.h>
#define MAX 85
using namespace std;

char mat[MAX][MAX];
int color[MAX][MAX];

#define FOR(i,a,b) for( int i = a ;i < b;i++)

int dr[] = {1,0,-1,0};
int dc[] = {0,1,0,-1};

char ch;
int m,n ;

bool isOut(int i, int j ){
	if( i < 0 || j < 0 || i >= m || j >=n ) return true;
	return false;
}
void dfs(int i, int j ){
	if(isOut(i,j)) return;
	if(mat[i][j] == 'X')return ;
	if(color[i][j]) return;	
	color[i][j] = 1;
	FOR(d,0,4){
		int ni, nj;
		ni = i + dr[d];
		nj = j + dc[d];
		if(!isOut(ni,nj)){
			if(mat[ni][nj] == 'X'){
				mat[i][j] = ch;
				for(i = 0; i <= m; i++){
					puts(mat[i]);
				}
			}			
		}
	}
	FOR(d,0,4){
		int ni, nj;
		ni = i + dr[d];
		nj = j + dc[d];
		dfs(ni, nj);		
	}
}
int main(){

	int cases; cin >> cases;

	while(cases--){
		memset(mat, '\0', sizeof(mat));
		memset(color,0, sizeof(color));
		int i = 0;
		while(gets(mat[i])){
			cout << "mas "; puts(mat[i]);
			if(mat[i][0] == '_') break;
			i++;
		}
		m = i; n = MAX;
		FOR(i,0,m){
			for(int j = 0; mat[i][j] != '\0'; j++){
				if(mat[i][j] != 'X' && mat[i][j] != ' ' && !color[i][j]){
					ch ='#';
					mat[i][j] = ' ';
					dfs(i,j);
				}
			}
		}

		for(i = 0; i <= m; i++){
			puts(mat[i]);
		}
	}
	return 0;
}