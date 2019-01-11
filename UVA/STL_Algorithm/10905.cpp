#include <bits/stdc++.h>

using namespace std;

bool myfunction ( string a , string b ){
	return a + b  > b + a  ;
}
int main ( ){
	int n ;

	while(cin >> n && n != 0 ){
		cin.ignore();
		string cad;
		getline(cin, cad);		
		stringstream ss(cad);
		vector<string> v(n);
		for( int i = 0 ;  i < n ; i++)
			ss >> v[i];
		sort(v.begin(), v.end(), myfunction );

		for( int i = 0 ;  i < n ; i++) cout << v[i];
		cout << endl;
	}
}