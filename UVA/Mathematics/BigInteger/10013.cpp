/*
Lo hice en java con BigInteger y me dio TLE

En c++

sumar dos numeros de hasta m =  un millon de digitos

crear dos vectores de tamaño m 
definir la suma para dichos vectores
	Tomando en cuenta el acarreo
	si la suma da mas de 9 se cambia el acarreo a 1 de  lo contrario cero
	para saber el valor  de la suma en ese digito solo es  mod 10

No olvidar que  debe haber un linea de impression entre cada salida 



CASO ESPECIAL  la suma se puede desbordar por 
eso se debe de tomar en cuenta el ultimo carr
porejemplo 
9
9
18 ese 1 esta en l ultimo carry pues los vectores son de tamaño 
*/


#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;

int main(){
	int cases;
	cin >> cases;
	bool flag = true;
	while(cases--){
		if(flag)flag = false;
		else cout << endl;
		int m; cin >> m;
		vi a(m), b(m), c(m);
		for(int i = 0; i < m ; i++) cin >> a[i] >> b[i];
		int dig = 0, carry = 0; 
		for(int i = m - 1 ; i >= 0 ; i--){
			dig =  a[i] + b[i] + carry;
			if(dig > 9 ) carry = 1;
			else carry = 0;
			c[i] = dig % 10;
		}
		if(carry) printf("1");
		for(int i = 0; i < m ; i++) printf("%d", c[i]);
		printf("\n");
	}
}