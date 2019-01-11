#include <bits/stdc++.h>

using namespace std;
int main(){

	queue<string> Q;
	map<string, int> m;
	map<string, int> :: iterator it ;
	for( char i  = 'a'; i <= 'z' ; i++){
		Q.push(string(1,i));
	}

	int cuenta = 1;
	string cad;
	while( !Q.empty() ){
		cad = Q.front(); Q.pop();
		m[cad] = cuenta; cuenta++;

		if(cad.size() == 5) continue;

		for( char carNuevo = cad [ cad.size() -1 ] + 1 ;  carNuevo <= 'z' ; carNuevo++){
			Q.push( cad + carNuevo );
		}
	}
	while( cin >> cad ){
		it = m.find(cad);
		if( it == m.end() ) cout << 0 << endl;
		else cout << it->second << endl;
	}

}