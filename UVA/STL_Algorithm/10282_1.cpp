#include <bits/stdc++.h>

using namespace std;

int main ( ){

	string cadena, word, translate;
	map <string, string> m;
	map <string, string> :: iterator it;
	while(getline(cin,cadena) && cadena != "" ){
	 	stringstream ss(cadena);
	 	ss >> word  >> translate;
	 	m[translate] = word;
	}

	while( cin >> translate  && translate.size() != 0){
	 	if(m.find(translate) == m.end()) cout << "eh" << endl;
	 	else cout << m[translate] << endl;
	}
}