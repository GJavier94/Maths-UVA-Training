#include <bits/stdc++.h>

using namespace std;

typedef vector<char> vc;
typedef vector<vc> vcc;

typedef vector<int> vi;
typedef vector<vi> vii;

int n;
#define FOR(i,a,b) for(int i = a; i < b; i++)

int dr[] = {1,1,0,-1,-1, 0};
int dc[] = {0,1,1, 0,-1,-1};

int flagw = 0;
int flagb = 0;

void floodFill(vcc& mapa, vii& vis, int i, int j, char c1){
	if(flagw || flagb) return;
	if( i < 0 || j < 0 || i >= n || j >= n ) return;
	if(mapa[i][j] != c1 ) return ;
	if(vis[i][j]) return;
	vis[i][j] = 1;
	FOR(d,0,6)  floodFill(mapa,vis, i + dr[d], j + dc[d], c1 );

	if( c1 == 'w' && j == n-1) flagw++;

	if( c1 == 'b' && i == n-1) flagb++;
}
int main ( ){	
	int k = 0;
	while( cin >> n && n){
		k++;
		vcc mapa(n,vc(n));		
		FOR(i,0,n)FOR(j,0,n) cin >> mapa[i][j];
		cout << k << " " ;
		bool flag2 = true;
		vii vis(n,vi(n));
		for(int i =  0; i < n && flag2; i++){
			char car = mapa[i][0];
			if(mapa[i][0] == 'w' && !vis[i][0] ){
				flagw = 0;
				floodFill(mapa,vis,i,0, car);
				if(flagw) flag2 = false, flagw = 0,cout <<"W" << endl;
			}
		}
		if(flag2 == false) continue;

		vii vis1(n,vi(n));
		bool flag1 = true;
		for(int j = 0; j < n &&  flag1; j++){
			char car = mapa[0][j];
			vii vis1(n,vi(n));
			if(mapa[0][j] == 'b' &&  !vis1[0][j]  ){
				flagb = 0;
				floodFill(mapa,vis,0,j, car);
				if(flagb) flag1 = false,flagb = 0, cout <<"B" << endl;
			}
		}			
	}
}
