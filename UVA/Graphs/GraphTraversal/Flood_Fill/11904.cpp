#include <bits/stdc++.h>

using namespace std;

typedef vector<char> vc;
typedef vector<vc> vcc;

#define FOR(i,a,b) for( int i = a; i < b; i++)
int m, n;
int dc[] = {1,-1,0,0};
int dr[] = {0,0,1,-1};

int floodFill(vcc& mapa, int  i, int  j, char c1 , char c2 ){
	if(j < 0 ) j = n -1;
	if( j >= n)  j = 0;
	if( i < 0 || i >= m) return 0;
	
	if( mapa[i][j] != c1 ) return 0;
	mapa[i][j] = c2;
	int ans = 1;
	FOR(d,0,4) ans += floodFill(mapa, i +  dr[d], j + dc[d], c1, c2);
	return ans;
}

int main ( ){

	while( cin >> m >> n ){
		vcc mapa(m, vc(n));
		FOR(i,0,m)FOR(j,0,n) cin >> mapa[i][j];
		int x, y; cin >> x >> y;
		char land = mapa[x][y];
		

		floodFill(mapa, x, y,land, ' ' );
		int ans = 0;
		int sum = 0;
		FOR(i,0,m){
			FOR(j,0,n){
				if(mapa[i][j] == land){
					sum = floodFill(mapa, i, j, mapa[i][j], ' ' );
					if(ans < sum ) ans = sum;
				}
			}
		}
		printf("%d\n",ans );
	}
}