/*
	Sabemos que dad un numero de vertices te genera #numero de arboles binarios = cat(n vertices)
	el problema pide lo contrario
	dado el numeo de arboles cual fue el  n catalana que lo genera
	SOlucion 
	generamos los numeros y los asociamos con un map 

	a[numero de catalan ] = i-esimo numero  usamos find para encontrar a que iesimo pertence  y listo 
	n = max =  4294967295;
*/



#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vll;

map<ll, ll>  a;
vll b;

void precalcular(){
	b.push_back(1);
	ll MAX = 4294967295;
	ll n = 1;
	int i = 0;
	while(n  < MAX){
		i++;
		n = b[i - 1]*(4*i - 2);
		n /= i + 1;
		b.push_back( n );
		a[n] = i;					
	}
}
int main(){
	precalcular();		
	ll n;
	while(	cin >> n ){
		cout << (a.find(n))->second << endl;
	}
}
