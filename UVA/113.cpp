/*	
	Problema: 
		pide calcular la raiz enesima de  p
	Solucion 
	Usaremos para representar a  n y a p, 
	 como queermos
	la raiz n-esima de p = (p)^(1/n) => 
	de ese modo podemos usar la funcion pow
	haciendo pow(p , 1 / n )
	si noq ueiro imprimir decimales "%.f"
*/
	
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
	double n, p;
	while(cin >> n >> p ){		
		printf("%.f\n", pow(p , 1 / n )  );
	}
}