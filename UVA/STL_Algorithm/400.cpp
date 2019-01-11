#include <bits/stdc++.h>

using namespace std;

bool myfunction( string a , string b){
	return  a < b;
}

int main (){

	int n;
	while( cin >> n ){
		cin.ignore();
		string cad;
		vector<string> v;
		int colInicial = 0;
		for( int i = 0 ; i <  n ; i++){
			getline( cin , cad);
			v.push_back(cad);
			if( colInicial < cad.size() ) colInicial = cad.size();

		}

		sort(v.begin(), v.end(), myfunction);		

		// calculo del numero de columnas 
		int numCols = 1;
		int tamBloque = colInicial;
		int acumulador = tamBloque;		
		tamBloque += 2;	
		while( acumulador <= 60){
			acumulador += tamBloque;
			if(! ( acumulador <=60) ) break;
			numCols++;			
		}

		// calculo de filas 
		int numRows = (int) ceil ( ( n / (double)(numCols)) );
		for(int i = 0; i < 60 ; i++) cout << "-";
		cout << endl;
		for( int j = 0 ; j < numRows; j++){
			string line = "";
			for ( int i = 0; i < numCols; i++){
				if( i == numCols - 1 ) tamBloque = colInicial;
				else tamBloque = colInicial + 2;
				if ( j + i*numRows  < v.size()){
					line += v[ j + i*numRows ];
					int relleno  = tamBloque - v[ j + i*numRows ].size();
					for(int l = 0; l < relleno; l++) line += " ";
						
				}

			}
			cout << line << endl;
		}

	}	
}		