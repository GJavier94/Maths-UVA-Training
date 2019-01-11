/*
 Problema: dado el N numero de diagonales de un poligono
 cual es el poligono minimo ?
 por ejemplo 10 diagonoles un exagono no las tiene pero un 7agono tiens mas de esas por eso la rspuesta es 7

Solucion 
	un poligono de n lados tiene n vertices
	se pude ver como un grafo
	el numero de aristas de un grafo completo no dirigido es 
	n(n-1)/2 
	pero hay que quitarle las que son lados 
	como son n lados entonces tiene n(n-1)/2 - n diagonales
	luego entonces
	sea N las diagonales
	N = n(n-1)/2 - n  
	dado N queremos obtener n para eso pues despejamos
	N = (n^2 - n )/2 - 2n/2
	N = (n^2 - n - 2n) / 2
	2N = n^2 - 3n 
	n^2 - 3n - 2N = 0 
	es una ecuacion cuadratica con 
	a  = 1 ; b = -3; c = -2N 

	al sustituir y reduci
	n = 3/2 +- sqrt(9 + 8N) / 2
	osea 
	1)   n1 = 3/2 + sqrt(9 + 8N) / 2
	2)   n2 = 3/2 - sqrt(9 + 8N) / 2
	pero no se si la segunda puede ser solucion
	para que 
	   3/2 - sqrt(9 + 8N) / 2 > 0
	-> 3/2  >  sqrt(9 + 8N) / 2
	-> sqrt(9 + 8N) / 2  < 3/2
	-> sqrt(9 + 8N)   < 3
	-> 9 + 8N   < 9
	-> 8N   < 0
	-> N < 0 !!!!!!! lo cual nunca suscede entonces siempre sera negativo y no hay pedo 	

	asi dado el N usamos 1)   n1 = 3/2 + sqrt(9 + 8N) / 2
	lo calculamos 
	puede dar n.000 o n.decimales
	si son deciamles tendria que irese hasta n+1
	ceil lo solucion =) si es n.000 le pone n 
	si es n.decimales le pone n + 1

	long long porque va hasta N <= 10^15

	NOTA
	Usar %.lf cuando uso ceil  para  no ponr los puntos decimales
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
	ll N;
	double n;
	int k = 1;
	while(cin >> N && N){
		n = 1.5;
		n += (sqrt(9 + 8*N)) / 2.0;	
		printf("Case %d: %.lf\n", k++, ceil(n));
	}
}