#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vii;
int n;
#define FOR(i,a,b) for( int i = a; i < b; i++)
#define FOR2(i,a,b,flag) for( int i = a; i < b && flag; i++)

int dr[]={-1,1,0,0};
int dc[]={0,0,1,-1};

int floodFill(vii& mapa, int  i, int  j, int  c1, int c2 ){
	if( i < 0 || j < 0 || i >= n || j >= n ) return 0;
	if(mapa[i][j] != c1) return 0;
	int ans = 1;
	mapa[i][j] = c2;
	FOR(d,0,4) ans += floodFill(mapa, i + dr[d], j + dc[d], c1, c2 );
	return ans;
}
int main(){
	while(cin >> n && n ){
		cin.ignore();
		vii mapa(n, vi(n,n));
		string line;
		FOR(i,1,n){
			getline(cin, line);
			stringstream ss(line);
			int x ,y;
			while(ss >> x >> y ){
				mapa[x-1][y-1] = i;
			}
		}
		bool flag = true;
		FOR2(i,0,n, flag){
			FOR2(j,0,n,flag){
				if(mapa[i][j]){
					if( floodFill(mapa, i, j, mapa[i][j], 0 )  != n  ){flag = false;}
				}
			}
		}
		if(flag) cout << "good" << endl;
		else cout << "wrong" << endl;
	}
}