/*
	Me costo mucho 
	Problema dado un grafo lineal 1-2-3-n
	hacer conjuntos en el que sus nodos no esten conectados y que si se puede agragar un nodo mas 
	no se podria porque estaria conectao a alguno
	
	1.-Me di cuenta  de que solo podia haber un nod s
	o dos nodos de distanciaporque si fuera mas lejos se estarian omitieneod nodos 
	los cuales podrian agregarse ya que no estarian conectados aguno
	ejemplo
	1 2 3 4 5
	me 1  y  5  cumplen que no se coencta peeero se puede meter el 3 lo cual ya no deberia
	2. forzosamente debe empezar con el nodo 1 o con el nodo 2 y de ahi en adlenta
	ya que el nodo 1 contecta  se cehcan las de 3 en adeltan 
	y si es con dos pues se omite el 1
	3.-
	se puede representar en un arbol las difernte cobinacion 
	al final del dia son las combinaciones de sumar 2 o sumar 3  hasta tener n o n-1 
	 ejemplo
	 n = 5
	puedo escoger 1 o 2 	
				5
	 		3
		1
	 .		4

		2   4
			5
	para n = 5 son 4  hojas y eso es el resultado 
	despues de ver el patron 1,1,1,2,4,5,7,12
	es una dp donde a[i] = a[i-2] + a[i-3] eso era todo
	Cabe en un entero
	se precalcula y se imprime


	Despues de investigar la secuencia en oeis

	es la A000931 y se llama padovan sequence o padovan numbers 
	0, 0, 1, 0, 1, 1, 1, 2, 2, 3, 4, 5, 7, 9, 12, 16, 21, 28, 37, 49, 65, 86, 114, 151, 200, 265, 351, 465, 616, 816, 1081, 1432, 1897, 2513, 3329, 4410, 5842, 7739, 10252, 13581, 17991, 23833, 31572, 41824, 55405, 73396, 97229, 128801, 170625


*/



#include <bits/stdc++.h>

using namespace std;
#define SIZE 77
int a[SIZE];

void precalc(){
	a[0] = 1;
	a[1] = 2;
	a[2] = 2;
	for(int i = 3; i < SIZE; i++)
		a[i] = a[i-2] + a[i -3];
}
int main(){
	precalc();
	int n;
	while(cin >> n ){
		cout << a[n - 1] << endl;
	}
}