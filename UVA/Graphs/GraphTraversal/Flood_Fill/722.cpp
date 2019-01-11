#include <bits/stdc++.h>

using namespace std;

typedef vector<char> vc;
typedef vector<vc> vcc;

int m,n;
#define FOR(i,a,b) for( int i = a; i < b ; i++)

int dr[] = {1,-1,0,0};
int dc[] = {0,0,1,-1};

int floodFill(vcc& mapa,int  i,int  j, char c1,char c2 ){
	if( i < 0  || j < 0 || i >= m || j >= n ) return 0;
	if( mapa[i][j] != c1) return 0;
	int ans = 1;
	mapa[i][j] = c2;

	FOR(d,0,4){
		ans += floodFill(mapa, i + dr[d], j + dc[d], c1 ,c2 );
	}
	return ans;
}

int main(){
	int cases;cin >> cases;
	bool flag = true;
	while(cases--){
		if(flag) flag = false;
		else cout << endl;
		vcc mapa(99,vc(99));		
		int i, j; string n1, n2;
		cin >> n1 >> n2;
		i = (n1[0] - '0')*10 + (n1[1] - '0');
		j = (n2[0] - '0')*10 + (n2[1] - '0');

		string row;
		cin.ignore();
		m = 0 ;
		while(getline(cin,row) && row.size()){
			n = row.size();
			FOR(i,0, n) mapa[m][i] = row[i];
			m++;
		}

		vcc aux(m, vc(n));

		int numero = floodFill(mapa, --i, --j, '0', '.' );
		cout << numero << endl;
	}
} 