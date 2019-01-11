#include <bits/stdc++.h>

using namespace std;
const string signo("::");


int main ( ){

	string cad;
	map<string,int> ignore;
	while( cin >> cad &&  cad != signo) ignore[cad] = 1;

	multimap<string, string> mapa;
	multimap<string, string> :: iterator it;

	while(getline(cin, cad)){
		for( int i = 0 ; i < cad.size(); i++) cad[i] = tolower(cad[i]);
		
		for( int i = 0; i < cad.size(); i++){
			if(! isalpha(cad[i]) ) continue;

			int j = i;
			string aux;

			while( j < cad.size() && isalpha(cad[j]) ){
				aux += cad[j];
				j++;
			}

			if( ignore[aux] == 0 ){ // es una keyword
				for( int i = 0 ;i < aux.size();i++) aux[i] = toupper(aux[i]);

				// creamos un nuevo string  donde ira con la keyword en capital letters
				string t  =  cad;
				t.replace(i, aux.size(), aux);
				mapa.insert(make_pair(aux, t));
			}
			i = j ;
		}
	}

	for ( it = mapa.begin() ;it != mapa.end(); it++)
		cout << it->second << endl;

}
