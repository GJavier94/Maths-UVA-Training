#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int > point;
typedef pair<int, point > ii;

typedef vector<int> vi;
typedef vector<vi> vii;

const int INF = 1 << 30;
int m, n;
#define FOR(i,a,b) for(int i = a; i < b ; i++)

int movs[4][2] = { {-1,0},{1,0} ,{0,-1} ,{0,1} };

bool valida(int x, int y){
	if( x < 0 || y < 0 || x >= n || y >= m) return false;
	return true;	
}
int main ( ){
	int cases; cin >> cases;
	while( cases--){
		cin >> n >> m;
		vii edges(n, vi(m));
		FOR(i,0,n)FOR(j,0,m) cin >> edges[i][j];		

		priority_queue< ii, vector<ii>, greater<ii> > pq;
		vii dis(n, vi(m, INF));
		dis[0][0] = 0;// nodo origen s
		pq.push( (ii){0,(point){0,0}} );

		while(!pq.empty() ){
			ii front = pq.top(); pq.pop();
			point p = front.second;
			int d = front.first;
			int x = p.first, y = p.second;
			if( d > dis[x][y] ) continue;
			cout << "Visitando nodo " << x  <<  "  " << y << endl;
			for( int  i = 0; i < 4 ; i++){
				int newx, newy;
				newx = x + movs[i][0];
				newy = y + movs[i][1];
				if( valida(newx, newy ) ) { // es un elemento a considerar 
					if( dis[x][y] + edges[newx][newy] < dis[newx][newy]){
						dis[newx][newy] = dis[x][y] + edges[newx][newy];
						pq.push((ii){dis[newx][newy], (point){newx,newy}});

					}
				}
			}			
		}
		cout << dis[n-1][m-1] + edges[0][0] << endl;
	}
}