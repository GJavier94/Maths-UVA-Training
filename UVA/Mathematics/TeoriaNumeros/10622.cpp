/*
Nunca olvidar quen INTEGER son NEGATIVOS y positivos
se tiene que tambien considerar el caso en el que el numero sea negativo
*/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;

ll sieve_size;
vi primes;
bitset<10000010> bs;

ll gcd(ll a, ll b ){ return b == 0 ? a : gcd(b, a % b);}

void sieve(ll upperbound ){
	sieve_size =  upperbound + 1;
	bs.set(); bs[0] = bs[1] = 0;
	for(ll i = 2; i <= sieve_size; i++)if(bs[i]){
		for(ll j = i*i; j <= sieve_size; j+=i) bs[j] = 0;		
		primes.push_back((int) i);
	}	
}
/*
	Esta funcion checa primo por primo y calcula las potencias
	incluso las potencia que son 0 es decir 9 2^0	

*/
ll solve(ll N){
	ll PF;
	int pot,pi;
	bool flag = true;
	for( int i = 0; i < primes.size(); i++){
		PF = primes[i];pot = 0;
		while(N % PF == 0 ){N /= PF; pot++;}
		if(pot){
			if(flag) pi = pot, flag = false;
			else pi = gcd(pi,pot);
		}		
		if(N == 1 ) break;
	}
	if( N != 1) return 1;
	return pi;
}
int main(){
	sieve(1000000);
	ll n;	
	while( scanf("%lld",&n) && n ){
		ll pot = solve(abs(n));		
		if(n < 0 ){							
			while( !(pot&1) ){pot = pot / 2;}			
		}
		printf("%lld\n", pot );		
	}
}