#include <bits/stdc++.h>

using namespace std;

int main(){

	int cases; cin >>cases;

	while( cases--){
		int r,c,m,n;
		cin >> r >> c >> m >> n;

		for	(int i = 0; i < r  ;  i++){
			string cad;
			getline( cin ,cad);
			map<char, int  > mp;
			for( int j  = 0; j < c; j++){
				mp[cad[j]]++;
			}
		}

	}
}

