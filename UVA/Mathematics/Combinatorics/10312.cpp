/*
	Problema:  dada una expresion saber el numero de formas #n1 que son non binary bracketing
	solcion:  

	1. Calcular todas las formas  de brackenting ( numeros de super catalan)
	2. Calcular las que son binary bracketing ( numero de catalan )
	3. restar toodas de las que si son para obtner las que no son 

	0 < n  <= 26  lo soporta long long para super catalan 
	FOrmula de super catalan  pero esta 1-indexado

	S(1) =  1;
	s(2) = 2;
	s(n) = 3*(2*n - 3)*s(n-1) -(n - 3)*s(n -2)    / n 

	1. primero precalculo los de catalan  hasta  fac[25]
	2. calculos lo de super catalan hasta sc[25] 
		pero sepero el producot para que no lo sobrepase
		osea s(n) = 3*(2*n - 3)*s(n-1) -(n - 3)*s(n -2)    / n 
			= s(n) = (3*(2*n - 3)*s(n-1)) / n )
				-  ((n - 3)*s(n -2)    / n )

	ya que esta uno indexado en el codigo la entrada le reston uno 
	por eso el n - 1;

	REVISAR RELACION DE NUMEROS DE CATALAN Y SUPER CATALAN EN LA PATHS DE GRID

	dada una grid  n *n   todas las rutas de un lado a otro se da por nCn ( permutaciones con repeticiones)
	las que estan debajo de la diagonal son las de catalan 
	y las que no tocan las diagonal son supercatalan =) 
	NOTA:  conozco la formula de recurrencia para obtener super catalan pero necesito calcular las anteriores
	usando DP bottom up los calculo pero si me preguntarn uno en especifico tengo que revisar una formula de 
	legendre para obtenerlo sin una relaccion de recurrencia
	Sitio visitado 

	http://mathworld.wolfram.com/SuperCatalanNumber.html
	*/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define SIZE 27

ll cat[SIZE];
ll sc[SIZE];

void precalcCat(){
	cat[0] = 1;
	for(int i = 1; i < SIZE; i++){
		cat[i] = cat[i - 1]*( 4*i - 2 );cat[i] /= i + 1;
	}
}
void precalcSuperCat(){
	sc[0] = sc[1] = 1;
	for(int i = 2; i < SIZE ; i++){
		sc[i] = (3*(2*(i+1) - 3)*sc[i - 1]) / ( i + 1);
		sc[i] -= ( ((i+1) - 3)*sc[i - 2]) / ( i + 1);;		 		
	}
}

int main(){
	precalcCat();
	precalcSuperCat();
	int n;
	while(cin >> n ){
		cout << sc[n - 1] - cat[n - 1] <<"\n";
	}
}