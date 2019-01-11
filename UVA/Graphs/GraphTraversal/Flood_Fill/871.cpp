#include <bits/stdc++.h>

using namespace std;

typedef vector<char> vc;
typedef vector<vc> vcc;

#define FOR(i,a,b) for( int i = a; i < b; i++)

int m, n;
int dr[] = {1,1,0,-1,-1,-1, 0, 1};
int dc[] = {0,1,1, 1, 0,-1,-1,-1};
int floodFill(vcc& mapa, int  i, int  j, char c1, char c2){
	if( i < 0 || j < 0 || i >= m || j >= n) return 0;
	if(mapa[i][j] != c1) return 0;
	mapa[i][j] = c2;
	int ans = 1;
	FOR(d,0,8) ans += floodFill(mapa, i + dr[d] , j + dc[d] , c1, c2 );

	return ans;

}

int main ( ){

	int cases; cin >> cases;	
	bool flag = true;
	cin.ignore();
	cin.ignore();
	while( cases--){
		if(flag) flag = false;
		else cout << '\n';
		string row;
		vcc mapa(25, vc(25));
		m = 0;
		while(getline(cin, row) && row.size()){
			n = row.size();
			FOR(i,0,row.size()) mapa[m][i] = row[i];
			m++;
		}
		int num = 0;
		int max = 0;
		FOR(i,0,m){
			FOR(j,0,n){
				if(mapa[i][j] == '1'){
					num = floodFill(mapa, i, j, '1', '0');
					if( max < num) max = num;
				}
			}
		}

		cout << max << '\n';
	}
}