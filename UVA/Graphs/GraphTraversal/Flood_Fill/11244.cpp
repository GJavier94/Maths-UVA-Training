#include <bits/stdc++.h>
using namespace std;

typedef vector<char> vc;
typedef vector<vc> vcc;
int m,n;
int dr[] = {1,1,0,-1,-1,-1, 0,1};
int dc[] = {0,1,1,1,0,-1,-1,-1};

#define FOR(i,a,b) for( int i = a ; i < b ; i++)
int floodFill(vcc& mapa, int  i, int  j , char c1, char c2){
	if(i < 0 || j < 0 ||  i >= m || j >= n) return 0;
	if(mapa[i][j] != c1) return 0;
	int ans = 1 ;
	mapa[i][j] = c2;
	FOR(d,0,8){
		ans += floodFill(mapa,i + dr[d] ,j +dc[d] ,c1,c2);
	}
	return ans;
}

int main ( ){
	while( cin >> m >> n  && m && n ){		
		vcc mapa(m , vc(n));		
		FOR(i,0,m)FOR(j,0,n) cin >> mapa[i][j];
		int numstars = 0 ;		
		FOR(i,0,m)FOR(j,0,n)if(mapa[i][j] == '*')if(floodFill(mapa, i, j , '*', '.') == 1) numstars++;			
		cout << numstars << endl;
	}
}