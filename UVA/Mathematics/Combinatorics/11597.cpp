/*
dado un grafo completo n dirigido 
cuantas maneras hay de crear spaning trees 
tal que estos no tengan aristas iguales

lo hhice hasta 5 y salio que siempre son la mitad
si son n -> n/2 spanning trees

solucion 

en un complete undirected graph
tengo n(n-1) edges
por cada spanning tree necesito n-edges diferentes

entonces 
(n-1)*x = n(n-1) / 2
x = n(n-1)/ 2*n(n-1)
x = n /2
por eso solo basta con solo dividir por do s


*/

#include <bits/stdc++.h>
using namespace std;
int main(){
	int n, k = 1;
	while(cin >> n  && n ){	
		printf("Case %d: %d\n",k++, n / 2 );		
	}
}