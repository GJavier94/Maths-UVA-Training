#include <bits/stdc++.h>
using namespace std;
typedef pair <int, int > ii;
typedef vector<vector<ii > > vii;
typedef vector<int > vi;
typedef map<string, int  > mapa;

const int INF = 1 << 30;
#define FOR(i,a,b,) for( int i = a; i < b ; i++)
int n ;
int main ( ){
	int t; cin >> t;

	FOR(k,0,t){	
		cin >> n;
		vii edges(n);
		mapa ma;
		int index = 0;
		string city1, city2;
		FOR(i, 0 , n ){
			cin >> city1;
			if(ma.find(city1) == ma.end()) ma[city1] = index++;
		}
		int m; cin >> m;
		int u, v, w;
		FOR( i, 0 , m ){
			cin >> city1 >> city2 >> w; 
			edges[ma[city1]].push_back(ii(ma[city2], w));		
		}
		//tiramos bellman ford

		vi dist(n, INF);		
		dist[0] = 0;		
		vi padres(n);			

		FOR(i, 0, n -1){
			FOR(u, 0 ,  n ){
				FOR(j,0 , edges[u].size()){
					ii v = edges[u][j];
					if( dist[u] + v.second < dist[v.first]){
						dist[v.first]  =  dist[u] + v.second;
						padres[v.first] = u;
					}
				}
			}
		}

		int queries; cin >> queries;
		int steps;
		FOR( i, 0, queries){
			cin >> steps;

			

		}


		cout << k+1 << endl;
	}

}





