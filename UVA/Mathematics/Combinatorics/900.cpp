/*
	En c++ usando long long -> se soporta hasta el fib de 51 (probable ahasta 60)	s	
	Problema cuantos posibles posiciones por cada cantidad -> patron la serie de fibonacci desplazada
	*Hacer precalculo de la serie de fibonacci hasta n  = 50  + 1 ( Por el desplazamiento)
*/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

typedef vector<ll> vll;
#define SIZE 51
vll f(SIZE + 1);

void precalc(){
	f[0] = 0; f[1] = 1;
	for(int i = 2; i < f.size(); i++) f[i] = f[i-2] + f[i-1];
}
int main(){
	precalc();
	int n;
	while(cin >> n && n ){
		cout << f[n + 1 ] << "\n";
	}
}