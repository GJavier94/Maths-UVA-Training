#include <bits/stdc++.h>

using namespace std;

int escalar( int x, int w ){
	int an = x & w;
	int r = an & 1;
	an = an >> 1;
	while( an  != 0){
		r = r ^ (an & 1);
		an = an >> 1;
	}
	return r;
}

int main ( ){

	int SIZE = 8;	
	int fx[SIZE] = {1,1,1,-1,1,-1,-1,-1};
	int sum = 0;
	for( int w = 0; w < SIZE ; w++){
		sum = 0;
		for( int x = 0;  x < SIZE; x++){
			int potencia, elemento;
			
			potencia = fx[x] ^ escalar(x,w);
			elemento = pow (-1, potencia);
			
			if( potencia == -2 )
				elemento = -1 ;			
			if(potencia == -1)
				elemento = 1;
			if(potencia == 0 )
				elemento = 1;
			if(potencia == 1 )
				elemento = -1;

			sum +=  elemento;
			
		}
		
		cout << sum*(-1) <<  endl;
	}
}


