/*
 Calculo de los numeros de catalan 
 de manera individual 
 dada por la formula cn = (1/ (n + 1) )  * (2n C n)
 al expandir en factoriales me quedo 

 cn = 1.2......(n)(n+1)....(n + n)
      -----------------------------
      1.2.......n.1.2..........n(n + 1)
   cancelando y reduciendo 

  cn = (n+1)....(n + n)
      -----------------------------
       1.2..........n(n + 1)
 para calcular rapido 
 hice 
  cn = (n+1)....(n + n)
      -----------------------------
       1.2..........n
       y luego =/ (n + 1)  en el for

esto es cuando no me dan el maximo de n o si n es  muy gande


2. en caso de que me den el maximo de n y sea pqueño
hago una dp bottom up y uso  la relacion concurrente en el problema 991.cpp
*/

#include <bits/stdc++.h>
using namespace std;

int main(){
	int cases; cin >> cases;
	while(cases--){
		int n; cin >> n;
		int catalan = 1;
		for(int i  = 1; i <= n ; i++){catalan *= n + i;catalan /= i;}
		catalan /= n + 1;
		cout << catalan << "\n";
	}
}