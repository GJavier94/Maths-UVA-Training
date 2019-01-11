#include <bits/stdc++.h>

using namespace std;

int main ( ){

	int cases; cin >> cases; cin.ignore();
	string cad;
	getline(cin, cad);

	while(cases--){
		map<int, map<string,int> > sec;
		map<int, map<string, int> >:: iterator it1;
		map<string,int> :: iterator it2;
		map<string,int> :: iterator it3,it4;

		while( getline(cin, cad) && cad != ""){		
			sec[cad.size()][cad] = 1;	
			//cout << "insertando " << cad.size() << " " << cad << endl;
		}
		map<string,int> result;

		int min,max,tam;
		min = sec.begin()->first;
		max = (--sec.end())->first;
		tam = min + max;		

		for( it1 = sec.begin ( ); it1 != sec.end();it1++){
			int comp = tam - (it1->first);
			for( it2 = (it1->second ).begin(); it2 != (it1->second ).end(); it2++ ) {

				if( sec[comp].size() != 0){// encontre uno

				}
			}
		}
	}
}