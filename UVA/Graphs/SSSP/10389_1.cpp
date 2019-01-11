#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int > ii;
typedef vector<vector<ii> >  vii;
typedef vector<int> vi;
typedef map<ii, int > mapa;

const int INF = 1 << 30;

int n = 220;

#define FOR(i,a,b) for( int i = a; i < b; i++)
int peso(int x1, int y1, int x2, int y2, int vel ){//v = d/t  -> t = d / v
	double tiempo, distancia;
	distancia = sqrt( (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2) ) ;
	tiempo = distancia / (  (double)vel/60.0 );
	return (int)round(tiempo);
}
int main( ){
	int cases; cin >> cases;
	bool flag = true;
	while(cases--){
		if(flag) flag = false;
		else cout << endl;
		int cx[n], cy[n];
		int index = 0;
		mapa m;
		cin >> cx[index] >> cy[index]; m[ii(cx[0], cy[0])] = index++;
		cin >> cx[index] >> cy[index]; m[ii(cx[1], cy[1])] = index++;
		vii edges(n);
		string line; cin.ignore();

		while(getline( cin, line) && line.size() != 0){
			stringstream ss(line);
			int x1, x2, y1, y2;
			ss >> x1 >> y1; 
			if(m.find(ii(x1,y1)) == m.end()) cx[index] = x1, cy[index] = y1, m[ii(x1,y1)] = index++;

			while(ss >> x2 >> y2 &&  x2 != -1 && y2 != -1){
				if(m.find(ii(x2,y2)) == m.end()) cx[index] = x2, cy[index] = y2, m[ii(x2,y2)] = index++;				
				int w = peso(x1, y1, x2, y2, 40 );
				edges[m[ii(x1,y1)]].push_back(ii(m[ii(x2,y2)],w));
				edges[m[ii(x2,y2)]].push_back(ii(m[ii(x1,y1)],w));								
				x1 = x2, y1 = y2;
			}
		}
		int size = index;
		FOR(i,0,size){
			FOR(j,0,size){
				if( i == j )continue;
				int w = peso(cx[i], cy[i],cx[j], cy[j], 10);
				edges[i].push_back(ii(j,w));				
			}
		}

		priority_queue <ii, vector<ii>, greater<ii> > pq;
		vi dis(n, INF);
		pq.push((ii){0, 0});
		dis[0] = 0;

		while(!pq.empty()){
			ii front = pq.top(); pq.pop();
			int d = front.first, u = front.second;

			if( d > dis[u] ) continue;

			FOR(j,0,edges[u].size()){
				ii v = edges[u][j];

				if( dis[u] + v.second < dis[v.first]){
					dis[v.first] = dis[u] + v.second;
					pq.push((ii){dis[v.first], v.first});
				}
			}
		}	
		double r1 =(dis[1]/1000.0);
		int r2 = r1;
		if( r1 - r2 <= 0.5) cout << r2 << endl;
		else cout << r2 +1 << endl; 		

	}
}