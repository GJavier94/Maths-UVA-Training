/*
	Problema: dado un numero n, en cuantos pasos empezando por uno se lleg aa el 
	empezando por 1 y haciendo i por 2
	1 1
	2 1*2
	3 1*2 + 1
	4 2*2
	5 2*2 +1
	asi enlo sucevio sacando log2 se obtiene
	1 0....
	2 1.'
	3 2....
	4 2.0
	si hago n -1 y luego saco log(n-1) y luego sumo +1 obteno los valores
	osea log de laupenutima potencia de dos y leugo sumo 1 
	pue eso eso se hace en lultimo paso
*/


#include <bits/stdc++.h>

using namespace std;

int main(){
	int n, k = 1;
	while(cin >> n && n > 0){
		printf("Case %d: ",k++ );
		n--;
		if(n)
			printf("%.f\n", floor((log(n) / log(2))) + 1  );
		else 
			printf("0\n");
	}
}