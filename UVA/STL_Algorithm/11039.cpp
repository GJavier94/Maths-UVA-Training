#include <bits/stdc++.h> 

using namespace std;

bool myfn( int a, int b ){
	int a1 = abs(a), b1 = abs(b);
	return a1 > b1;

}
int main ( ){

	int cases;
	cin >> cases;
	while( cases--){
		int f; cin >> f;
		if( f == 0 ){
			cout << 0 << endl;
			continue;
		}
		vector<int> v(f);
		for( int i = 0; i < f; i++) cin >> v[i];

		sort(v.begin(), v.end(), myfn);

		int cont = 1;
		for( int i = 0 ; i < f - 1; i++){
			if ( (v[i] < 0 && v[i+1] > 0)  || (v[i] > 0 && v[i+1] < 0)  ) 
				cont++;
		}
		cout << cont << endl;

	}
}