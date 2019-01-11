#include <bits/stdc++.h>

using namespace std;

typedef vector<char> vc;
typedef vector<vc> vcc;

typedef vector<int> vi;


#define FOR(i,a,b) for( int i = a ; i < b ; i++)

int m, n;

int dr[] = {0,0,-1,1};
int dc[] = {1,-1,0,0};
vi letras;

void floodFill(vcc& mapa, int i, int j , char c1, char c2 ){

	if( i < 0 || j < 0 || i >= m || j >= n ) return;	
	if(mapa[i][j] != c1) return;
	mapa[i][j] = c2;
	FOR(d,0,4) floodFill(mapa, i + dr[d], j + dc[d], c1,c2);

	return;
}

bool myfunction (int i, int j ){
	if( letras[i] != letras[j] ) return letras[i] > letras[j];
	return  i < j ;
}

int main ( ){
	int t; cin >> t;

	FOR(k,1,t+1){
		cout << "World #" << k << '\n';
		cin >> m >> n;
		vcc mapa(m, vc(n));
		FOR(i,0,m)FOR(j,0,n) cin >> mapa[i][j];
		vi ind(26);
		letras.assign(26,0);
		FOR(i,0,m){
			FOR(j,0,n){
				if(isalpha(mapa[i][j])){
					letras[mapa[i][j] -'a']++;
					floodFill(mapa, i, j , mapa[i][j], '.');
				}
			}
		}		

		FOR(i,0,26) ind[i] = i;
		sort(ind.begin(), ind.end(), myfunction);
		FOR(i,0,26)if(letras[ ind[i] ]) cout << (char)( ind[i] + 'a') << ": " << letras[ ind[i] ] << '\n' ;
	}
}






