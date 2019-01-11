#include <bits/stdc++.h>

using namespace std;

int main ( ){

	int c,n;
	cin >> c >> n;
	cout << c << " " << n << endl;

	string input = "";
	char aux;
	for( int i = 0; i < n ; i++){
		cin >> aux;
		input += aux;
	}

	int contador = 0;
	int tamBloque = n;

	input += input;
	cout << input << endl;
	int i = 0,j = 0 ;


	while( i <= n ){
		if ( contador <= c){

			if( contador  == c ){
				if(  (j-i +1 ) < tamBloque){

					tamBloque = (j-i +1 );
					cout << tamBloque << endl;
				}
			}

			while(input[j] == 0 ){
				j++;
				contador++;
			}
			
		}else{			
			while(input[i] != 0 ){
				i++;
				contador--;
			}
		}
		
	}
	cout << tamBloque << endl;


}