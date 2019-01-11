#include <bits/stdc++.h>

using namespace std;


typedef vector<int> fila;
typedef vector<fila> matriz;
typedef pair<int, int > Coord;

int main(){
	int t;
	cin >> t;
	
	int r,c,m,n;
	for (int k = 1; k <= t; k++){
		cin >> r >> c >> m >> n;
		matriz mapa(r, fila(c));
		matriz vis(r, fila(c));

		int nWater; cin >> nWater;
		int xWater, yWater;
		map<pair<int,int>, int > waters;
		for( int i = 0;  i < nWater; i++){
			cin >> xWater >> yWater;			
			waters[make_pair(xWater,yWater)]++;
		}



		int mr [8] = {-m, -m, m, m, -n, n, -n, n};
        int mc [8] = {n, -n, n, -n, m, m, -m, -m};
        vis[0][0] = 1;
		queue<Coord> q;
		q.push( Coord(0,0) );

		while(!q.empty()){
			Coord actual = q.front(); q.pop();
			set<pair<int,int> > movs;
			set<Coord> :: iterator it;
			int newX, newY;
			for(int i = 0; i < 8 ; i++){
				newX = mr[i] + actual.first;
				newY = mc[i] + actual.second;
				movs.insert(make_pair(newX,newY));
			}
			for(it = movs.begin(); it != movs.end(); it++){
				int newX, newY;
				newX = (*it).first;
				newY = (*it).second;
				if( newX >= 0  && newY  >= 0 && newX < r && newY < c && !waters[make_pair(newX,newY)] ){
					mapa[newX][newY]++;
					if(!vis[newX][newY]){
						vis[newX][newY] = 1;
						q.push(Coord{newX,newY});
					}
				}
			}
		}
		
		int pares = 0;  int impares = 0;
		for( int i = 0; i < r ;i++){
			for(int j = 0 ; j < c ;j++){
				if( mapa[i][j] || (!i && !j) ){
					if( mapa[i][j] % 2) pares++;
					else impares++;
				}
			}
		}

		cout <<"Case " << k  << ": " << impares << " " << pares << endl;
	}
}