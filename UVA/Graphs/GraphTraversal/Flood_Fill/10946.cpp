#include <bits/stdc++.h>

using namespace std; 
typedef vector<char> vc;
typedef vector<vc> vcc;

typedef pair<int, char> ii;

#define FOR(i,a,b) for( int i = a; i  < b ; i++)
int m, n;

// int dr[] = {1,1,0,-1,-1,-1, 0,1};
// int dc[] = {0,1,1,1,0,-1,-1,-1};
int dr[] = {0,0,-1,1};
int dc[] = {1,-1,0,0};

int floodFill(vcc& mapa, int  i, int  j, char c1 , char c2){
	if( i < 0 || j < 0 || i >= m || j >= n) return 0;
	if(mapa[i][j] != c1) return 0;
	int ans = 1;
	mapa[i][j] = c2;

	FOR(d,0,4) ans += floodFill(mapa, i + dr[d], j + dc[d], c1, c2 );

	return ans;
}

int main (){
	int k = 0;
	while( cin >> m >> n  && m && n ){
		k++;
		vcc mapa(m, vc(n));
		FOR(i,0,m)FOR(j,0,n) cin >> mapa[i][j];

		priority_queue<ii> pq;

		FOR(i,0,m){
			FOR(j,0,n){
				if(mapa[i][j] >= 'A' && mapa[i][j] <= 'Z' ) {
					char c = mapa[i][j];
					int numero =  floodFill(mapa, i, j, c, '.');		
					pq.push( ii (numero, c*(-1) )  );
				}
			}
		}
		cout << "Problem " << k << ":" << endl;
		while(!pq.empty()){
			ii elm = pq.top(); pq.pop();
			cout << (char)(elm.second*(-1)) << " " << elm.first << endl;
		}
	}
}