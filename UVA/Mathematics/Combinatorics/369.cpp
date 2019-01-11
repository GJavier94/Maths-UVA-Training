/*
el problema me pedia las combinaciones de n,m donde  5 <= m,n <= 100
Cuando solicitan tantas es mejor hacer el calculo de el triangulo de pascal
respondiendo en tiempo constante.
*FUNCION precalc-> generacion del triangulo de pascal
*/
#include <bits/stdc++.h>
using namespace std;
#define SIZE 100 
typedef long long ll;
ll a[SIZE + 1][SIZE + 1];
void precalc(){
	memset(a, 0, sizeof(ll)*(SIZE +1)*(SIZE +1)) ;	
	a[0][0] = 1;
	for(int i = 1; i < SIZE + 1; i++){
		a[i][0] = 1;
		for(int j = 1; j < SIZE + 1; j++) a[i][j] = a[i-1][j-1] + a[i-1][j];
	}
}
int main(){	
	precalc();
	int n,m;
	while(cin >> n >> m && n &&  m ){
		printf("%d things taken %d at a time is %lld exactly.\n", n, m , a[n][m] );
	}
}