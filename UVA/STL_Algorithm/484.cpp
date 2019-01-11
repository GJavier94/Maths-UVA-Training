#include <bits/stdc++.h>

using namespace std;

int main ( ){

	map<int, int> m;
	map<int, int> :: iterator it;
	int numero;

	while( cin >> numero ){
		it = m.find(numero);
		if( it == m.end()) m[numero] = 1;//m.insert(pair<int, int>(numero, 1));
		else m[numero]++;
	}

	for( it = m.begin() ; it != m.end(); it++){
		cout << it-> first << " " << it->second << endl;
	}
}