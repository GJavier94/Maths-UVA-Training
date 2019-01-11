#include <bits/stdc++.h>

using namespace std;
typedef vector<char> vc;
typedef vector<vc> vcc;

typedef vector<int> vi;
typedef vector<vi> vii;

#define FOR(i,a,b) for( int i = a; i < b; i++)
int M,N;

int dr[] = {1,1,0,-1,-1,-1,0,1};
int dc[] = {0,1,1,1,0,-1,-1,-1};

int floodfill(vcc& mapa, int i, int j, char c1 ,char c2){
	if( i < 0 ||  j < 0 ||  i >= M || j >= N ) return 0;
	if(mapa[i][j] != c1) return 0;
	int ans = 1; 
	mapa[i][j] = c2;

	FOR(d,0,8){
		ans += floodfill(mapa, i + dr[d], j + dc[d], c1, c2);
	}
	return ans;
}
int main(){
	int cases; cin >> cases; 
	cin.ignore();
	string row;
	getline( cin, row );
	bool flag = true;
	while(cases--){	
		if(flag) flag = false;
		else cout << endl;
		vcc mapa(99, vc(99));
		vii vis(99, vi(99));
		M = 0;
		while(getline(cin, row) && row.size() != 0 &&  (row.find(" ") ==  string::npos) ) {			
			N = row.size();			
			FOR(i,0,N) mapa[M][i] = row[i];
			M++;
		}		
		stringstream ss(row);
		vcc aux(M, vc(N));
		FOR(p,0,M){
			FOR(q,0,N){
				aux[p][q] = mapa[p][q];
			}
		}
		int i,j;
		ss >> i >> j, i--, j--;
		int numero = 0;
		numero = floodfill(aux, i, j, 'W', '.');
		cout << numero << endl;
		string query;
		while(getline(cin,query) && query.size() !=  0 ){						
			FOR(p,0,M){
				FOR(q,0,N){
					aux[p][q] = mapa[p][q];
				}
			}
			stringstream ss(query);
			ss >> i >> j, i--, j--;
			numero = floodfill(aux, i, j, 'W', '.');
			cout << numero << endl;
		}
		
	}
}