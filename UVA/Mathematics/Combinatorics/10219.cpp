// 4ta solucion  derivada de la desarrollada en java 
/*
	hay una manera mas eficiente de obtener c_nk 
	surge de que c_nk = n!  / (n-k)!k! 
	= 1.2.3.....(n-k)(n-k + 1)....n / (1.2.3 ... n -k).k!
	= (n-k + 1)... n / k!
	= (n-k + 1 )... n / 1.2.3. k
	= (n - k + k)/ 1 * (n - k + k - 1) / 2 * (n - k + k - 2) / 3 *  ..... (n - k + k (- k + 1 )  / k

	y ya que quiero log10( c_nk)
	= log10 ( (n - k + k)/ 1 * (n - k + k - 1) / 2 * (n - k + k - 2) / 3 *  ..... (n - k + k (- k + 1 )  / k )
	= log10 (n - k + k)/ 1) + ... +  log10 (n - k + k (- k + 1 )  / k )
	= log10 ((n - k + k))- log10(1) + ... lo mismo 	

	Asi no es necesario usar la clase biginteger
	Escribir funcion propia log base 10  para evitar problemas
	para saber el numero de digitos en  cierta base 
	es floor( logbase(numero,base) ) + 1 // se le hace pisoy luego se le suma uno ejemplo log10( 9 ) 0.... = flor = 0 + 1 = 1 un digito para representarlo
*/	

#include <bits/stdc++.h>
using namespace std;
/*
double logBase(double n, int base){
	return log(n)/log(base);
}
*/
double log10(double n){
	return log(n)/log(10);
}
int main(){
	int n, k;
	while(cin >> n >> k ){
		double sum = 0;
		for(int i = 1; i <= k ; i++)
			sum += log10(n - i + 1)  - log10(i); 
		int res = floor(sum) + 1;
		printf("%d\n",res);
	}
}