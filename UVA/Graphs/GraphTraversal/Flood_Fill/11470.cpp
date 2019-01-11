#include <bits/stdc++.h>

using namespace std;
#define max 10 
int mapa[max][max];
int vis[max][max];
typedef vector<int> vi;

int n;	
#define FOR(i,a,b) for( int i = a; i < b ;i++)

int sum = 0;
vi sumas;
void dfs(int i, int j){
	if( i < 0 || j < 0 || i >= n || j >= n) return;
	if(vis[i][j]) return;
	vis[i][j] = 1;

	sumas,push_back();

	FOR(d,0,8) dfs(i + dr[d], j + dc[d]);
}
int main(){

	while(cin >> n && n ){	
		FOR(i,0,n)FOR(j,0,n) cin >> mapa[i][j];

		if(n&1){
			int center = (int)(n/2);
			dfs(center, center);
		}	
		else{
			
		}
	}	

}