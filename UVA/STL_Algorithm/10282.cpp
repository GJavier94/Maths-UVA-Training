#include <bits/stdc++.h>

using namespace std;

int main ( ){

	string cadena, word, translate;
	map <string, string> m;
	map <string, string> :: iterator it;
	while(getline(cin,cadena) && cadena.size() != 0 ){
		word = cadena.substr (0, cadena.find(" "));
		translate = cadena.substr ( cadena.find(" ") + 1  ) ;
		m[translate] = word;		
	}

	while( cin >> translate  && translate.size() != 0){
		if(m.find(translate) == m.end()) cout << "eh" << endl;
		else cout << m[translate] << endl;
	}
}