#include <bits/stdc++.h>

using namespace std;

int m;

bool myfn( int a, int b){
	int m1 = a % m , m2 = b % m;
	if( m1 != m2 ) return m1 < m2;
	if( a % 2 == 1  &&  b % 2 == 1  ) return  a > b;
	if( a % 2 == 1  &&  b % 2 == 0  ) return  true;
	if( a % 2 == 0  &&  b % 2 == 1  ) return  false;
	return  a < b;
}
int main ( ){
	int n;
	while( cin >> n >> m  && n != 0 && m != 0){
		vector<int> v;
		cout << n << " " << m << endl;
		for( int  i = 0; i < n ;i++){
			int aux; cin >> aux;
			v.push_back(aux);
		}
		sort(v.begin(), v.end(), myfn);

		for( int i = 0 ; i < n; i++){
			cout << v[i] << endl;
		}
	}
	cout << "0 0" << endl;
	return 0;
}