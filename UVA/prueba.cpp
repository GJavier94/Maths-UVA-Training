/*
	Problema: dado un numero n obtener el siguiente numero de smith
	numero de smith: cualquier entero no primo tal que la suma de sus digitos es igua ala suma de la suma de los digitos de su descomposicion en factores primos

	SOLUCION:
	usar la criba para calcular primos ya que n <= 10^9 y los primos estan hasta sqrt(10^9) creamos esa criba
	luego recibimos el numero y usamos la funcion sumDigits par suma sus digitos
	luego utilizamos la funcion finding prime factro para obetner los facores primos y le sacamos la suma de digitos a cada uno
	sumamos todos 
	comparemos sumas 
	si son iguales y no fue primo es s smith hacer esto mientras no se encuentre numero de smith
	 =) 

*/



#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;

ll sieve_size;
bitset<100000010> bs;
vi primes;

void sieve(ll upperbound){
	sieve_size = upperbound + 1;
	bs.set(); bs[0] = bs[1] = 0;
	for(ll i = 2; i <= sieve_size; i++)if(bs[i]){
		for(ll j = i*i; j <= sieve_size; j += i) bs[j] = 0;
		primes.push_back((int)i);
	}
}
ll sumDigits(ll n){
	ll s = 0;
	while(n){ s += n % 10; n /= 10;}
	return s;
}
bool isSmith(ll n ){
	ll m = n;	
	int s1 = 0, s2 = 0;
	s1 = sumDigits(n);	
	ll idx = 0, PF = primes[idx];	
	while(PF * PF <= n){
		while(n % PF == 0 ){n /= PF; s2 += sumDigits(PF);}
		PF = primes[++idx];
	}
	if(n != 1) s2 += sumDigits(n);
	if(s1 == s2 && (m != n )) return true;	
	return false;
}

int main(){
	sieve(100000);	
	int cases;
	cin >> cases;
	ll n;
	while(cases--){		
		cin >> n;
		for(ll i = n + 1; ; i++){
			if(isSmith(i)){cout << i << "\n"; break;}
		}
	}
	return 0;
} 