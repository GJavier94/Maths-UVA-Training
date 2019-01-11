#include <bits/stdc++.h>

using namespace std;

int main (){

	int cases;cin >> cases;

	while( cases--){
		int n; cin >> n;
		int p; cin >> p;
		map<int,int > m;
		for (int i = 0; i < p; i++){
			int multiplos ;cin >> multiplos;
			int k = 0;
			while(k < n){
				k += multiplos;				
				if ( k <= n && (k%7 != 6  && k%7 != 0 ) ){
					m[k]++;
			
				}
			}
		}
		cout << m.size() << endl;
		
	}
}