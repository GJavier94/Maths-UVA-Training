/*
	Problema: dado un numero 2^n se perdieron digitos de la derecha
	divido en dos partes la izquierda se conoce y miden la derecha se perdio y al menos mide n + 1 (osea se perdio al menos mas de la mitad)

	Solción
	nos dan un entero p
	es el entero tal que p = floor(2^n / 10^t) buscamos n y t  siendo t >= n + 1 ( los perdidos ) (dividimos entre 10 para quitar un digitos y asi..)
	nos da en decimales y le hacemos piso (por eso floor)

	son puras ecuacines  y ee 2^n puede ser grandisimo
	-> hint -> usamos logaritmos 
	asi 


	----
	p = floor( 2^n / 10^t)
	por definicion  de funcion piso 

	p <=  2^n / 10^t <  p + 1

	p * 10^t <= 2^n < (p + 1)*10^t

	log2(p * 10^t) <= log2(2^n) < log2( (p + 1)*10^t ) 
	log2(p) + log2(10^t) <= n < log2( (p + 1) ) + log2(10^t )
	log2(p) + t*log2(10) <= n < log2( (p + 1) ) + t*log2(10 ) 

	las cotas son decimales al inferior le hacemos techo
	al superior le hacemos piso para osea a.. < a1  < n < b1 < b... 

	asi n  tiene que ser ceil(log2(p) + t*log2(10) ) y floor(log2( (p + 1) ) + t*log2(10 ) )
	vamos variando t desde  n + 1 hasta que ceil y floor coincidan
	osea cuando coinciden se hace veridica la desigualdad	
*/


// #include <bits/stdc++.h>
// using namespace std;
// double numDig(double n ){
// 	return floor(log10(n)) + 1; //log10 de cero o negativos no estan definidos
// }
// int main(){
// 	double p, t, lp, lp1, a;
// 	a =  log(10) / log(2);
// 	while(cin >> p ){
// 		t =  numDig(p) + 1;
// 		lp = log(p) / log(2);
// 		lp1 = log(p + 1) / log(2);		
// 		for(;  ceil(lp + t*a) != floor(lp1 + t*a);t++); // si pones for's sin lineas hay que poner ;
// 		//cuando coincida sera el valor de n
// 		printf("%d\n", (int)ceil(lp + t*a) );
// 	}
// }




// #include <bits/stdc++.h>

// using namespace std;
// double numDig( double n){
// 	return floor(log10(n)) + 1;
// }
// int main(){
// 	double p,t , a, lp, lp1;
// 	a = log(10) / log(2);
// 	while(cin >> p ){
// 		t =  numDig(p) + 1;
// 		lp = log(p) / log(2);
// 		lp1 = log(p + 1) / log(2);

// 		while( ceil(lp +  t*a ) != floor(lp1 + t*a)){t++;}		

// 		cout << (int )ceil(lp +  t*a ) << endl;

// 	}
// }