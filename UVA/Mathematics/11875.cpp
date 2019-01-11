#include <bits/stdc++.h>

using namespace std;
#define FOR(i,a,b) for( int i = a; i < b; i++)

typedef vector<int> vi;

int main(){

	int cases; cin >> cases;

	for(int k = 1; k <= cases; k++){
		int n; cin >> n;
		vi v(n);
		FOR(i,0,n) cin >> v[i];
		sort(v.begin(), v.end());

		cout << "Case " << k << ": " <<v[v.size()/2] << endl;
	}
}